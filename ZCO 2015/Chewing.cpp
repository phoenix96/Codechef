#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long int a[100005];
int main()
{
    long long int n,i,j,l,k,c=0;
    //n=2000; k=7;
   scanf("%lld %lld",&n,&k);
    for(int i=0;i<n;i++)
      scanf("%lld",&a[i]);
        sort(a,a+n);
        if(a[0]>=k) {
            cout<<"0";
            return 0;
        }
    for(i=1;i<n;i++)
    {
        if(a[0]+a[i]>=k)
            break;
        if(a[i]+a[i-1]<k)
            c++;
    }
    //cout<<c<<endl;
    j=c+1;
    c=(c+1)*c/2;
    //cout<<c<<endl;
    for(;j<i;j++)
    {
        for(l=j-1;l>=0;l--)
        {   //cout<<a[j]<<"+"<<a[l]<<endl;
            if(a[j]+a[l]<k)
                break;
        }
        c+=(l+1);
    }
    printf("%lld",c);
    return 0;
}
