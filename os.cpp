#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int bt[20],at[10],n,i,j,temp,p[10],st[10],ft[10],wt[10],ta[10];
    int WT=0,TA=0;
    float AWT,ATA;
    char pn[10][10],t[10];
    //Asking user for number of processes
    printf("Enter the number of process:");
    scanf("%d",&n);
    //Asking user to enter process details
    for(i=0;i<n;i++)
    {
        printf("Enter ProcessName :");
        scanf("%s",pn[i]);
        printf("Enter ArrivalTime :");
        scanf("%d",&at[i]);
        printf("Enter BurstTime :");
        scanf("%d",&bt[i]);
        printf("Enter Priority :");
        scanf("%d",&p[i]);
        printf("\n");
    }
    //Swapping processes according to priority
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0;i<n;i++)
 
    {
 
        if(i==0)
        {
            st[i]=at[i];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+bt[i];
            ta[i]=ft[i]-at[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+bt[i];
            ta[i]=ft[i]-at[i];
        }
        WT+=wt[i];
        TA+=ta[i];
    }
    AWT=(float)WT/n;
    ATA=(float)TA/n;
    printf("\nProcessName\tArrivalTime\tBurstTime\tPriority\tWaitingTime\tTurnAroundTime");
    for(i=0;i<n;i++)
	{
        printf("\n%s\t%2d\t\t%2d\t\t%2d\t\t%2d\t\t%2d",pn[i],at[i],bt[i],p[i],wt[i],ta[i]);
	}
    printf("\nAverage Waiting Time is : %f",AWT);
    printf("\nAverage Turn Around Time is : %f",ATA);
    getch();
}
