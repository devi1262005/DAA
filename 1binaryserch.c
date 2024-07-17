#include<stdio.h>
int main(){
int a[10], key, i,n,flag=0,high,low=0,mid;
printf("Enter element count(max 10):");
scanf("%d",&n);
high=n;
printf("Enter %d elements: \n",n);
for(i=0;i<n;i++){
	scanf("%d",&a[i]);
}
printf("Enter the element to find:");
scanf("%d",&key);
for(i=0;i<n;i++){
while(low<=high){
    mid=(high+low)/2;
if(a[mid]==key){
    flag=1;
    break;
}
else if(a[mid]<key){
    low=mid+1;
}
else if(a[mid]>key){
    high=mid-1;
}
}
if(flag==1){
    printf("Element %d found at position %d",key,mid+1);

}
else{
    printf("Element not found");
}
return 0;
}

















}
