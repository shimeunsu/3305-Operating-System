#include<stdio.h>
 

void main()
{

    int q1[20]; //fcfs pr2
    int q2[20]; //rr. pr3
    int q3[20]; // sjf. pr1
    int tq = 5;
// setting priority levels
   q1[0] = 2;
   q2[0] = 3;
   q3[0] = 1;

// intializing for level 1 burst times. 
   q1[1]= 10;
   q1[2]= 5;
   q1[3]= 7;
   q1[4]= 20;
   q1[5]= 17;
   q1[6]= 9;
   q1[7]= 3;
   q1[8]= 11;
   q1[9]= 15;
   q1[10]= 1;
// intializing for level 2 processors
   q2[1]= 10;
   q2[2]= 5;
   q2[3]= 7;
   q2[4]= 20;
   q2[5]= 17;
   q2[6]= 9;
   q2[7]= 3;
   q2[8]= 11;
   q2[9]= 15;
   q2[10]= 1;
   q2[11] = tq; 
// intializing for level 3 processors
   q3[1]= 10;
   q3[2]= 5;
   q3[3]= 7;
   q3[4]= 20;
   q3[5]= 17;
   q3[6]= 9;
   q3[7]= 3;
   q3[8]= 11;
   q3[9]= 15;
   q3[10]= 1;


   //sjf();


   




  int count,j,n,time,remain,flag=0,time_quantum; 
  int wait_time=0,turnaround_time=0,at[11],bt[11],rt[11]; 

   n = 11; 
   time_quantum= 5; 
   bt[1]= 10;
   bt[2]= 5;
   bt[3]= 7;
   bt[4]= 20;
   bt[5]= 17;
   bt[6]= 9;
   bt[7]= 3;
   bt[8]= 11;
   bt[9]= 15;
   bt[10]= 1;
 

  remain=n; 
 
  
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);





   
}

   void sjf(void){
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
  

   bt[1]= 10;
   bt[2]= 5;
   bt[3]= 7;
   bt[4]= 20;
   bt[5]= 17;
   bt[6]= 9;
   bt[7]= 3;
   bt[8]= 11;
   bt[9]= 15;
   bt[10]= 1;


   p[1]= 1;
   p[2]= 2;
   p[3]= 3;
   p[4]= 4;
   p[5]= 5;
   p[6]= 6;
   p[7]= 7;
   p[8]= 8;
   p[9]= 9;
   p[10]= 10;



    //sorting burst time in ascending order using selection sort
    for(i=0;i<11;i++)
    {
        pos=i;
        for(j=i+1;j<11;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }


printf("the new order of the queue for q3\n");
     for(i=1 ; i < 11 ; i++){
        printf("p[%d] : %d\n", p[i],bt[i]);
    }

 
    wt[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<11;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/11;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");

    for(i=1;i<11;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/11;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);



}


void fcfs(void){
    

int n,p[20],bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
   bt[1]= 10;
   bt[2]= 5;
   bt[3]= 7;
   bt[4]= 20;
   bt[5]= 17;
   bt[6]= 9;
   bt[7]= 3;
   bt[8]= 11;
   bt[9]= 15;
   bt[10]= 1;

   for (i = 1; i < 11 ; i++){
    p[i] = i;
   }

   printf("Order of the processes selectedd by in Ready Queue 1\n");


   for (i = 1; i < 11 ; i++){
    printf("p[%d]\n", p[]);
   }

// setting up the processes 
 

   wt[0]=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for(i=1;i<11;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
 
    //calculating turnaround time
    for(i=0;i<11;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);
  

}