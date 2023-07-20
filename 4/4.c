#include <stdio.h>
#include <stdlib.h>

int get_int(char* line, int index, int* last)
{
  //printf("LAST: %d\n", *last);
  char l[3] = {0};

  int ind = index;
  if(index == -1)
    ind = *last;
  
  for(int i=0; i < 3; i++)
    {
      if((line[i+ind] == '-' || line[i+ind] == ',') || line[i+ind] == '\n')
	{
	  if(line[i+ind] == '\n')
	    l[i] = line[i+ind];
	  *last = ind+(i+1);
	  //printf("last: %d %c\n", *last, line[*last]);
	  return atoi(l);
	}
      else
	l[i] = line[i+ind];
    }
  return -1;
}

int main()
{

  FILE* f;
  f = fopen("input4","r");

  char* line = NULL;
  size_t size;
  ssize_t read;

  int last;

  int count = 0;
  
  while((read = getline(&line, &size, f)) != -1)
    {
      int f1 = get_int(line, 0, &last);
      int f2 = get_int(line, -1, &last);

      int s1 = get_int(line, -1, &last);
      int s2 = get_int(line, -1, &last);

      /*if((f1 >= s1 && f2 <= s2) || (f1 <= s1 && f2 >= s2))
	{
	  count++;
	  }*/
      //if(f1 >= s1 || f2 <= s2 || f2 == s1)
      if((f1 >= s1 && f1 <= s2) || (f2 >= s1 && f2 <= s2) ||
	 (s1 >= f1 && s1 <= f2) || (s2 >= f1 && s2 <= f2))
	count++;
      
      //printf("%d %d %d %d %d\n", f1, f2, s1, s2, last);
      //return 0;
    }

  printf("%d\n", count);
  
  return 0;
}
