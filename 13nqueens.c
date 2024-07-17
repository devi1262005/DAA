#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void nqueen(int);
int place(int, int);
int x[20];
int main() {
int n;
printf("N QUEEN PROBLEM\n");
printf("Enter the number of queens: ");
scanf("%d", &n);
printf("The solutions are:\n");
nqueen(n);
getch();
return 0;
}
void nqueen(int n) {
int k, i;
k = 1;
x[k] = 0;
while (k > 0) {
x[k] = x[k] + 1;
 while (x[k] <= n && !place(k, n)) {
x[k] = x[k] + 1;
        }
if (x[k] <= n) {
if (k == n) {
for (i = 1; i <= n; i++) {
printf("%d ", x[i]);
}
printf("\n");
}
else
{
k = k + 1;
 x[k] = 0;
}
}
else
{
k = k - 1;
}
}
}
int place(int k, int n) {
int i;
for (i = 1; i <= k - 1; i++) {
if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k)) {
return 0;
}
}
return 1;
}
