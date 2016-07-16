#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long int a[50001];
long long int r[50001];
int main()
{
    long long int t,n,dif,fdif,k;
    scanf("%lld",&t);
    //t=50000;
    while(t--)
    {   //fflush(stdin);
        scanf("%lld",&n);
        //n=10;
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        sort(a,a+n);
//        for(int i=0;i<n;i++)
//            cout<<a[i]<<" ";
//        cout<<endl;
        dif=1;fdif=0;k=0;
        for(int i=0;i<n;i++)
            r[i]=0;
            a[n]=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==a[i+1])
            {
               r[k]++;
            }
            else
            {
                r[k]++;
                k++;
            }
        }
//        for(int i=0;i<k;i++)
//            cout<<r[i]<<" ";
//        cout<<endl;
        sort(r,r+k);
//        for(int i=0;i<k;i++)
//            cout<<r[i]<<" ";
//        cout<<endl;
        fdif=r[k-1];
        for(int i=k-2;i>=0;i--)
        {
            fdif=fdif-r[i];
            if(fdif<0)
                fdif=-fdif;
        }
//        printf("%lld\n",fdif);
        printf("%lld\n",fdif+(n-fdif)/2);
    }
    return 0;
}
