#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char towers[9][50] = {0};

void move_chars(int c, int f, int t)
{
  char* nc = malloc(sizeof(char)*(c+50));
  memset(nc, '\0', sizeof(char)*(c+50));
  printf("TODO: move %d from %d to %d\n", c, f, t);
  for(int i=0; i < c; i++)
    {
      //if(towers[f][i] == '\0')
      //break;
      nc[i] = towers[f][i];
      printf("towers[f][i]: %s nc: %s\nTAKING %c GOT %c\n", towers[f], nc, towers[f][i], nc[i]);
      towers[f][i] = '0';
      printf("POST: towers[f][i]: %s nc: %s\nTAKING %c GOT %c\n", towers[f], nc, towers[f][i], nc[i]);
    }
  for(int i=0; i < 50; i++)
    {
      if(towers[t][i] == '\0')
	break;
      printf("ADDING TO NC %c\n", towers[t][i]);
      nc[i+c] = towers[t][i];
    }
  printf("NC: %s\n", nc);
  for(int i=0; i < 50; i++)
    {
      if(nc[i] == '\0')
	break;
      printf("ADDING TO TOWER %c\n", nc[i]);
      towers[t][i] = nc[i];
    }
  free(nc);
}

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
  f = fopen("input5","r");

  char* line = NULL;
  size_t size;
  ssize_t read;

  int moving = 0;

  int index = 0;

  int lastInd = -1;
  
  while((read = getline(&line, &size, f)) != -1)
    {
      int lSize = strlen(line);
      
      if(lSize == 1)
	{
	  moving = 1;
	  for(int i=0; i < 9; i++)
	    printf("%s\n", towers[i]);
	  continue;
	}

      if(!moving)
	{
	  int count = 0;
	  
	  for(int i=1; i < lSize; i+=4)
	    {
	      if(count >= 9)
		count = 0;
	      if(line[i] != ' ')
		{
		  for(int j=0; j < 50; j++)
		    {
		      if(towers[count][j] == '\0')
			{
			  towers[count][j] = line[i];
			  break;
			}
		    }
		}
	      count++;
	    }
	}
      else
	{
	  int mCount = get_int(line, 0, &lastInd);
	  int mFrom = get_int(line, -1, &lastInd);
	  int mTo = get_int(line, -1, &lastInd);

	  printf("----------------------------------------------\n\n move %d from %d to %d \n\n ---------------------------------------------\n", mCount, mFrom, mTo);
	  move_chars(mCount, mFrom-1, mTo-1);
	  printf("-------------------------\n");
	  for(int i=0; i < 9; i++)
	    printf("%s\n", towers[i]);
	  printf("-------------------------\n");
	  //return 0;
	}
    }
  printf("-------------------------\n");
  for(int i=0; i < 9; i++)
    {
      for(int j=0; j < 50; j++)
	{
	  if(towers[i][j] != '\0')
	    printf("%c", towers[i][j]);
	}
      printf("\n");
    }
  printf("\n-------------------------\n");
}
