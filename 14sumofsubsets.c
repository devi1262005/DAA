#include<stdio.h>
#include<conio.h>
void sos(int,int,int);
int w[10],m,x[20];
void main()
{
int n,i,r=0,k=1,s=0;
printf("SUM OF SUBSETS");
printf("\nEnter the no of values");
scanf("%d",&n);
printf("\nEnter the values ");
for(i=1;i<=n;i++)
{
scanf("%d",&w[i]);
}
printf("\n Enter the value of m:");
scanf("%d",&m);
for(i=1;i<=n;i++)
{
r=r+w[i];
}
sos(s,k,r);
getch();
}
void sos(int s,int k,int r)
{
int j;
 x[k]=1;
if((s+w[k])==m)
{
printf("the solutions is:\n");
for(j=1;j<=k;j++)
{
printf("%d",x[j]);
printf("\n");
}
}
else if((s+w[k]+w[k+1])<=m)
sos((s+w[k]),(k+1),(r-w[k]));
if(((s+r-w[k])>=m)&&((s+w[k+1])<=m))
{
x[k] =0;
sos(s,k+1,(r-w[k]));
}
}
