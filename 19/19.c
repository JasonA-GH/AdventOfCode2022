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
      if(line[i+ind] == ' ' || line[i+ind] == '\n')
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
  f = fopen("input19","r");

  char* line = NULL;
  size_t size;
  ssize_t read;


  while((read = getline(&line, &size, f)) != -1)
    {
      int lastInd = -1;
      
      int oreCost = line[0] - '0';
      
      int clayCost = line[2] - '0';
      
      int obsOreCost = line[4] - '0';
      int obsClayCost = get_int(line, 6, &lastInd);
      
      int geoOreCost = get_int(line, -1, &lastInd);
      int geoObsCost = get_int(line, -1, &lastInd);

      printf("%d %d %d %d %d %d\n", oreCost, clayCost, obsOreCost, obsClayCost, geoOreCost, geoObsCost);
    }
  
  
  return 0;
}
