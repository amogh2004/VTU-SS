#include<stdio.h>

struct process
{
  int all[6],max[6],need[6],finished;
}p[10];

int avail[6],sseq[10],ss=0,check1=0,check2=0,n,work[6];
int nor;
int safeseq(void);

int main()
{
  int ch,i=0,j=0,k,pid,ch1;
  do{
    printf("\n\n\t1.Input");
    printf("\n\n\t 2.safe state or not");
    printf("\n\n\t3.print");
    printf("\n\n\t4.exit");
    printf("\n\n\t enter ur choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("\n\n\tenter number of proccesses:");
              scanf("%d",&n);
              printf("\n\n\tenter the number of resources:");
              scanf("%d",&nor);
              printf("\n\n\tenter the available resources:");
              for(j=0;j<n;j++)
              {
                for(k=0;k<nor;k++)
                {
                  if(j==0)
                  {
                    printf("\n\n\tfor resources type %d:",k);
                    scanf("%d",&avail[k]);
                  }
                  p[j].max[k]=0;
                  p[j].all[k]=0;
                  p[j].need[k]=0;
                  p[j].finished=0;
                }
              }

              for(i=0;i<n;i++)
              {
                printf("\n\n\tenter max and allocated resources for P %d:",i);
                for(j=0;j<nor;j++)
                {
                  printf("\n\n\tenter the max of resources %d:",j);
                  scanf("%d",&p[i].max[j]);
                  printf("\n\n\tallocation of resources %d:",j);
                  scanf("%d",&p[i].all[j]);
                  if(p[i].all[j]>p[i].max[j])
                  {
                    printf("\n\n\tallocation should be less < or == max");
                    j--;
                  }

                  else
                    p[i].need[j]=p[i].max[j]-p[i].all[j];
                    //avail[j]=avail[j]-p[i].all[j];
                }
              }
              break;

      case 2: if(safeseq()==1)
                printf("\n\n\tthe system is in safe state");
              else
                printf("\n\n\tthe system i not in safe state");
              break;

      case 3: printf("\n\n\tnumber of processes:%d",n);
              printf("\n\n\tnumberof resources:%d",nor);
              printf("\n\n\tpid\tmax\t allocated\t need");
              for(i=0;i<n;i++)
              {
                printf("t P%d:",i);
                for(j=0;j<nor;j++)
                  printf("%d",p[i].max[j]);
                printf("\t");

                for(j=0;j<nor;j++)
                  printf("%d",p[i].all[j]);
                printf("\t");

                for(j=0;j<nor;j++)
                  printf("%d",p[i].need[j]);
              }

              printf("\tavailable:");
              for(i=0;i<nor;i++)
                printf("%d",avail[i]);
              break;

      case 4: break;
     }
   }while(ch!=5);
 }
 int safeseq()
 {
  int tj,tk,i,j,k;
  ss=0;

  for(j=0;j<nor;j++)
    work[j]=avail[j];

  for(j=0;j<n;j++)
    p[j].finished=0;

  for(tk=0;tk<nor;tk++)
  {
    for(j=0;j<n;j++)
    {
      if(p[j].finished==0)
      {
        check1=0;

        for(k=0;k<nor;k++)
          if(p[j].need[k]<=work[k])
            check1++;
          if(check1==nor)
          {
            for(k=0;k<nor;k++)
            {
              work[k]=work[k]+p[j].all[tk];
              p[j].finished=1;
            }
            sseq[ss]=j;
            ss++;
          }
      }
    }
  }

  check2=0;
  for(i=0;i<n;i++)
    if(p[i].finished==1)
      check2++;
  printf("\t");

  if(check2>=n)
  {
    printf("\n\nthe system is in safe state");
    for(tj=0;tj<n;tj++)
      printf("P%d",sseq[tj]);
    return 1;
  }

  else
    printf("\n\n\t the systemis not in safe state");
  return 0;
}
