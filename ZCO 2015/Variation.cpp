#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
long long int a[100005];
int main()
{
    long long int n,i,j,l,k,c=0;
   scanf("%lld %lld",&n,&k);
    for(int i=0;i<n;i++)
      scanf("%lld",&a[i]);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(abs(a[i]-a[j])>=k)
                    c++;
            }
        }
 
 
    printf("%lld",c);
    return 0;
}