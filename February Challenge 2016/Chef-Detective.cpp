#include<bits/stdc++.h>
using namespace std;
long long int a[100001];
int main()
{
    long long int n,in;
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&in);
        a[in]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=-1)
            printf("%d ",i);
    }
    return 0;
}
