#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  FILE *fptr;
  fptr = fopen("input1","r");
  
  /*fseek(fptr, 0, SEEK_END);
  
  int size = ftell(fptr);
  
  fseek(fptr, 0, SEEK_SET);*/
  
  //char fStr[size];

  char* line = NULL;
  size_t size;
  ssize_t read;
  int index = 0;
  int sum = 0;

  int lastSums[3] = {0};
  //int lastSum = 0;
  int lastIndexs[3] = {0};
  while((read = getline(&line, &size, fptr)) != -1)
    {
      if(strlen(line) > 1)
	{
	  int m = atoi(line);
	  sum += m;

	  for(int i=0; i < 3; i++)
	    {
	      if(sum > lastSums[i])
		{
		  printf("sum: %d %d lastSums[%d]: %d %d\n", sum, index, i, lastSums[i], lastIndexs[i]);
		}
	    }
	  
	  /*if(sum > lastSum)
	    {
	      //printf("sum: %d %d\n", sum, index);
	      for(int i=2; i > 0; i--)
		{
		  lastSums[i] = lastSums[i-1];
		  }
		  lastSums[0] = sum;
	      lastIndex = index;
	      }*/
	}
      else
	{
	  
	  for(int i=0; i < 3; i++)
	    {
	      if(sum > lastSums[i])
		{
		  /*int g = 1;
		  for(int j=0; j < 3; j++)
		    {
		      if(index == lastIndexs[j])
			{
			  g = 0;
			}
		    }
		  if(g)
		    {
		      lastSums[i] = sum;
		      lastIndexs[i] = index;
		      }*/
		  int tsmall = sum;
		  int tind = 0;
		  for(int j=0; j < 3; j++)
		    {
		      
		      if(lastSums[j] < tsmall)
			{
			  tsmall = lastSums[j];
			  tind = j;
			  //lastSums[j] = sum;
			  //lastIndexs[j] = index;
			}
		    }
		  lastSums[tind] = sum;
		  lastIndexs[tind] = index;
		  break;
		}
	    }
	  printf("%d: %d\n", index, sum);
	  index++;
	  sum = 0;
	}
    }

  int s = 0;
  for(int i=0; i < 3; i++)
    {
      printf("%d %d\n", lastIndexs[i], lastSums[i]);
      s += lastSums[i];
    }
  printf("%d\n", s);
  
  return 0;
}
