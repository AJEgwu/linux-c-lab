#include <stdio.h>

long long fact(long long n){
    if (n < 0) return 0;
    return (n <= 1) ? 1 : n * fact(n-1);
}

int main(void){
    long long n;
    if (scanf("%lld", &n) != 1) return 1;
    printf("%lld\n", fact(n));
    return 0;
}
