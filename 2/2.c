#include <stdio.h>

char change(char e, char z)
{
  //A
  //XYZ
  //CAB
  //B
  //XYZ
  //ABC
  //C
  //XYZ
  //BCA

  char c;
  
  switch(z)
    {
    case 'X':
      c = e-1;
      break;
    case 'Y':
      return e;
    case 'Z':
      c = e+1;
    }

  if(c >= 'D')
    c = 'A';
  else if(c < 'A')
    c = 'C';
  return c;
  /*
  
  switch(e)
    {
    case 'A':
      switch(z)
	{
	case 'X':
	  return 
	}
	}*/
}

int get_score(char e, char z)
{
  char y = change(e, z);
  
  if(e == y)
    {
      return 3 + (e-'A')+1;
    }
  if((e == 'A' && y == 'B') || (e == 'B' && y == 'C') || (e == 'C' && y == 'A'))
    //Win
    return 6 + (y-'A')+1;
  else
    return (y-'A')+1;
  return -1;
}

int main()
{
  FILE *fptr;
  fptr = fopen("input2a","r");
 
  char* line = NULL;
  size_t size;
  ssize_t read;

  int sum = 0;

  while((read = getline(&line, &size, fptr)) != -1)
    {
      sum += get_score(line[0], line[1]);//printf("%d\n", get_score(line[0], line[1]));
    }
  printf("%d\n", sum);

  return 0;
}
