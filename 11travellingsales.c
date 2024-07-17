#include<stdio.h>
int arr[10][10], completed[10],n,cost=0;
void takeInput()
{
int i,j;
printf("Enter the number of villages:");
printf("Enter the Cost Matrix: \n");
for(i=0;i<n;i++){
printf("\n Enter the elements of Row %d",i+1);
for(j=0;j<n;j++)
scanf("%d",arr[i][j]);
 completed[i]=0;
 }
 printf("\n \n THe cost list is:");
 for(i=0;i<n;i++){
        printf("\n");
    printf("\t %d",arr[i][j]);

 }

}
void mincost(int city)
    {
        int i,ncity;
        completed[city]==1;
        printf("%d-->",city+1);
        ncity=least(city);
        if(ncity==999){
            ncity=0;
            printf("%d",ncity+1);
            cost+=arr[city][city];
            return;
        }
        mincost(ncity);
    }
    int least(int c){
    int i,nc=999;
    int min=999,kmin;
    for(i=0;i<n;i++)
    {

        if(arr[c][i]!=0&&(completed[i]==0)){
            if(arr[c][i]+arr[i][c]<min)
                min=arr[i][0]+arr[c][i];
                kmin=arr[c][i];
                nc=i;

        }
        if(min!=999)
            cost+=kmin;
        return nc;
    }

    }
    int main(){
    takeInput();
    printf("\n \n The path is: \n");
    mincost(0);
    return 0;

    }

