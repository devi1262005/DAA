#include<stdio.h>
void allpath();
int cost[20][20],n;
void main(){
int i,j;
int a[10][10];
printf("All pair shortest path:\n");
printf("Enter the number of nodes:");
scanf("%d",&n);
printf("Enter the cost matrix:");
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        scanf("%d",&cost[i][j]);
    }
}
allpath();
}
void allpath()
{
    int i,j,k,a[20][20];
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            a[i][j]=cost[i][j];
        }
    }
        for(k=1;k<=n;k++){
            for(j=1;j<=n;j++){
                if(a[i][j]<(a[i][k]+a[k][j])){
                a[i][j]=a[i][j];
                }
                else{
                    a[i][j]=(a[i][k]+a[k][j]);
                }
                }

            }
            printf("Step %d \n",k);
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    printf("%d \t ",a[i][j]);
                }
            }

       }

