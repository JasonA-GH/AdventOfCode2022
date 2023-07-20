#include <stdio.h>
#include <string.h>


const char alpha[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

char get_same3(char* c, char* c2, char* c3)
{
  int size = strlen(c);
  int size2 = strlen(c2);
  int size3 = strlen(c3);

  for(int i=0; i < size; i++)
    {
      for(int j=0; j < size2; j++)
	{
	  if(c[i] != c2[j])
	    continue;
	  for(int k=0; k < size3; k++)
	    {
	      if(c2[j] != c3[k])
		continue;
	      printf("FOUND %c\n", c3[k]);
	      return c3[k];
	    }
	}
    }
  return '\0';
}

char get_same(char* c)
{
  int size = strlen(c);

  for(int i=0; i < size/2; i++)
    {
      for(int j=size/2; j < size; j++)
	{
	  if(c[i] == c[j])
	    return c[i];
	}
    }
  return '\0';
}

int main()
{
  FILE *fptr;
  fptr = fopen("input3","r");
 
  char* line = NULL;
  size_t size;
  ssize_t read;

  int aSize = strlen(alpha);

  int sum = 0;

  int c = 0;

  char l1[100] = {0};
  char l2[100] = {0};
  char l3[100] = {0};
  
  while((read = getline(&line, &size, fptr)) != -1)
    {
      switch(c)
	{
	case 0:
	  //l1 = line;
	  strcpy(l1, line);
	  break;
	case 1:
	  strcpy(l2, line);
	  break;
	case 2:
	  strcpy(l3, line);
	  break;
	}
      c++;

      if(c > 2)
	{
	  char same = get_same3(l1, l2, l3);
      
	  //char same = get_same(line);
	  for(int i=0; i < aSize; i++)
	    {
	      if(alpha[i] == same)
		{
		  sum += (i+1);
		  printf("ASD %d\n", sum);
		  break;
		}
	    }
	  c = 0;
	}
    }

  printf("%d\n", sum);
  
  return 0;
}
