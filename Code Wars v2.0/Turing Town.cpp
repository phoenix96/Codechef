#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    long long int in,g=0,s=0,k=0;
    scanf("%lld",&in);
    if(in==0)
    {
        printf("%lld galleons %lld sickles %lld knuts",g,s,k);
        return 0;
    }
    k=in%29;
    s=in/29;
    g=s/17;
    s=s%17;
    printf("%lld galleons %lld sickles %lld knuts",g,s,k);
    return 0;
}
