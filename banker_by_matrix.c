/******************************Bankers Algorithm********************************/
/***************************** Bhavya Jindal ***********************************/
/**********************************************************************************/
#include<stdio.h>

void main(){
    int n=5,m=3;
    int allocation[5][3]={{0,1,0},
                    {2,0,0},
                    {3,0,2},
                    {2,1,1},
                    {0,0,2}
                    };
    int max[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    int ind=0;
    int need[5][3];
    int available[3]={0};
    int finish[5]={0};
    int total[3]={10,5,7};
    int ans[5];
    int work[3]={0};

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];

        }

    }
    printf("\nAllocation array is :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",allocation[i][j]);
        }
        printf("\n");
    }
    printf("\nMax array is :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j <m;j++)
        {
            printf("%d ",max[i][j]);
        }
        printf("\n");
    }

    printf("\nNeed array is :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            work[i]+=allocation[j][i];
        }
    }
    for(int i=0;i<3;i++)
    {
        available[i]=total[i]-work[i];
        printf("%d ",available[i]);
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                int flag=0;
                for(int j=0;j<m;j++)
                {
                    if(need[i][j]>available[j])
                        flag=1;
                        break;
                }
                if(flag==0)
                {
                    ans[ind++]=i+1;
                    for(int y=0;y<m;y++)
                    {
                        available[y]+=allocation[i][y];
                    }
                    finish[i]=1;
                }
            }
        }
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(finish[i]==1)
        {
            c++;
        }
    }
    if(c==5){
        printf("\n\nThere is no deadlock and Safe Sequence is : ");
        for(int i=0;i<5;i++)
        {
            printf("%d ",ans[i]);
        }
    }
    else
    {
        printf("\n\nNo Safe Sequence is present");
    }
    printf("\n");


}
/***********************************************************************************/
