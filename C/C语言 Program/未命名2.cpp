#include<stdio.h>
#define SIZE    10000
int prime[SIZE];
void init()
{
    int i, a, n;
    prime[0] = 2;
    for(n = 1, a = 3; n < SIZE; a += 2)
    {
        for(i = 0; i < n; i++)
            if(a % prime[i] == 0) break;
        if(i == n) prime[n++] = a;
    }
}
void print(int a)
{
    int i;
    printf("%d = ", a);
    for(i = 0; i < SIZE && a % prime[i]; i++);
    if(i == SIZE)
    {
        printf("over flow.\n");
        return;
    }
    printf("%d", prime[i]);
    for(a /= prime[i]; a > 1 && i < SIZE; i++)
        for(; a % prime[i] == 0; a /= prime[i])
            printf(" * %d", prime[i]);
    printf("\n");
    if(a > 1) printf("over flow.\n");
}
int main()
{
    int a;
    init();
    printf("input number : ");
    scanf("%d", &a);
    print(a);
    return 0;
}
