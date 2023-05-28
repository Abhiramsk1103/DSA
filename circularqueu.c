#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define N  10
#define M  20
int q[N];
int ran[M];
int f=-1;
int r=-1;
int n,i,c,j,x,o,k;
FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
main()
{

    fp1=fopen("queue.txt","w+");
    fp2=fopen("enque.txt","w+");
    fp3=fopen("dqueu.txt","w+");
    fp4=fopen("operations.txt","w+");
    fp5=fopen("input.txt","w+");
    fp6=fopen("peep.txt","w+");
 printf("enter range of inputs\n");
 scanf("%d",&n);
   srand(clock());
 for(i=0;i<M;i++)
 {
     ran[i]=rand()%(n+1);
 }

 for(i=0;i<M;i++)
 {
     printf("%d ",ran[i]);
    fprintf(fp5,"%d ",ran[i]);
 }
 printf("\n");
 while(1)
 {
      printf("\n");
     printf("1-enter\n");
     printf("2-delete\n");
     printf("3-peek\n");
     printf("4-display\n");
     printf("5-file display and exit\n");
     printf("\n");
     printf("enter choice:-");
     scanf("%d",&o);

     if(o==1)
     {
         x=ran[j];
         j++;
         enqueue(x);
         fprintf(fp4,"enqueue ");

     }
     else if(o==2)
     {
         dqueue();
         fprintf(fp4,"dqueue ");
     }
     else if(o==3)
     {
         peek();
         fprintf(fp4,"peep ");
     }
     else if(o==4)
     {
         if(f==-1&&r==-1)
         {
             printf("queue empty\n");
         }
         else
         {
            i=f;
         printf("current queue is\n");
      while(i!=r)
         {
             c=1;
            printf("%d ",q[i]);
             i=(i+1)%N;
         }
           printf("%d ",q[i]);
          printf("\n");
         }
     }
     else if(o==5)
     {

         fprintf(fp4,"exit ");
          printf("final queue is\n");
          printf("\n");

                i=f;
         while(i!=r)
         {
             printf("%d ",q[i]);
             fprintf(fp1,"%d ",q[i]);
             i=(i+1)%N;
         }
                      printf("%d ",q[i]);
             fprintf(fp1,"%d ",q[i]);
         exit(0);
     }
 }
}
void enqueue (x)
{
         if((r+1)%N==f)
         {
             printf("queue full\n");
              printf("\n");

         }
         else if(f==-1&&r==-1)
         {
             f=0;
             r=0;
             q[r]=x;
             fprintf(fp2,"%d ",x);
             printf("%d\n",x);
             printf("\n");
         }
         else
         {
             r=(r+1)%N;
             q[r]=x;
             fprintf(fp2,"%d ",x);
             printf("%d\n",x);
              printf("\n");

         }
}
void dqueue()
{
    if(f==-1&&r==-1)
    {
        printf("queue empty\n");
         printf("\n");
    }
    else if(f==r)
    {
        printf("%d", q[f]);
        fprintf(fp3,"%d ",q[f]);
        printf("\n");
        f=-1;
        r=-1;

    }
    else
    {
        printf("%d ",q[f]);
        fprintf(fp3,"%d ",q[f]);
         printf("\n");
         f=(f+1)%N;
    }
}
void peek()
{
    if(f==-1&&r==-1)
    {
        printf("queue empty\n");
    }
    else
    {
        printf("%d ",q[f]);
        fprintf(fp6,"%d ",q[f]);
         printf("\n");
    }
}

