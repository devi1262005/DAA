#include<stdio.h>
int fib(int n) {
int fibArray[n+1];
fibArray[0] = 0;
fibArray[1] = 1;
for(int i = 2; i <= n; i++) {
fibArray[i] = fibArray[i-1] + fibArray[i-2];
    }
return fibArray[n];
}
int main() {
int n;
printf("Enter the number of terms: ");
scanf("%d", &n);
printf("Fibonacci Series: ");
for(int i = 0; i < n; i++) {
printf("%d ", fib(i));
    }
    return 0;
}
