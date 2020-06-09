#include<stdio.h>
#include<stdlib.h>

void FIFO()
{
  char s[200];
  char F[200];
  int l,f,i,j=0,k,flag=0,cnt=0;

  printf("\nEnter the number of frames : ");
  scanf("%d",&f);
  printf("\nEnter the length of the string: ");
  scanf("%d",&l);
  printf("\nEnter the string: ");
  scanf("%s", s);

  for(i=0;i<f;i++)
    F[i]=' ';

  printf("\n\tPAGE\t\tFRAMES\t\t\tFAULTS");
  for(i=0;i<l;i++)
  {
    for(k=0;k<f;k++)
      if(F[k]==s[i])
        flag=1;

    if(flag==0)
    {
      printf("\n\t%c\t",s[i]);
      F[j]=s[i];
      j++;

      for(k=0;k<f;k++)
      printf("\t%c",F[k]);
      printf("\tPage-fault%d",cnt);
      cnt++;
    }

    else
    {
      flag=0;
      printf("\n\t%c\t",s[i]);
      for(k=0;k<f;k++)
        printf("\t%c",F[k]);
      printf("\tNo page-fault");
    }

    if(j==f)
    j=0;
  }
}

int findLRU(int time[], int n)
{
  int i, minimum = time[0], pos = 0;
  for(i = 1; i < n; ++i)
  {
    if(time[i] < minimum)
    {
      minimum = time[i];
      pos = i;
    }
  }

  return pos;
}

int lru()
{
  int no_of_frames, no_of_pages, frames[10], counter = 0;
  int time[10], flag1, flag2, i, j, pos, faults = 0, page;
  char s[200];

  printf("\nEnter number of frames: ");
  scanf("%d", &no_of_frames);
  printf("\nEnter number of pages: ");
  scanf("%d", &no_of_pages);
  printf("\nEnter reference string: ");
  scanf("%s", s);

  for(i = 0; i < no_of_frames; ++i)
    frames[i] = -1;
  for(i = 0; i < no_of_pages; ++i)
  {
    flag1 = flag2 = 0;
    page = s[i] - '0';
    for(j = 0; j < no_of_frames; ++j)
    {
      if(frames[j] == page)
      {
        counter++;
        time[j] = counter;
        flag1 = flag2 = 1;
        break;
      }
    }

    if(flag1 == 0)
    {
      for(j = 0; j < no_of_frames; ++j)
      {
        if(frames[j] == -1)
        {
          counter++;
          faults++;
          frames[j] = page;
          time[j] = counter;
          flag2 = 1;
          break;
        }
      }
    }

    if(flag2 == 0)
    {
      pos = findLRU(time, no_of_frames);
      counter++;
      faults++;
      frames[pos] = page;
      time[pos] = counter;
    }

    printf("\n");
    for(j = 0; j < no_of_frames; ++j)
      printf("%d\t", frames[j]);
  }
  printf("\n\nTotal Page Faults = %d", faults);
  return 0;
}

int main()
{
  int ch,YN=1,i,l,f;
  char F[10],s[25];
  do
  {
    printf("\nOptions : ");
    printf("\n\n1:FIFO\n2:LRU \n3:EXIT");
    printf("\n\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: FIFO();
              break;
      case 2: lru();
              break;
      default: exit(0);
    }
    printf("\n\nPress 1 to continue.. 0 to exit ");
    scanf("%d",&YN);
  }while(YN==1);

  return(0);
}
