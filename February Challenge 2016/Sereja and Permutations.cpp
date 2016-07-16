#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long int v[1000000];
long long int fac[11];
long long fact()
{
    fac[0]=1;
    for(int i=1;i<=10;i++)
        fac[i]=fac[i-1]*i;
    return 0;
}
int main()
{fact();
    long long int t,n,m,i,j,k,l,e,a,b,c,d,flag,f;
    scanf("%lld %lld",&n,&d);
    for(i=0; i<n; i++)
        scanf("%lld",&v[i]);
    scanf("%lld",&m);
    long long int temp;
    for(int ii=0; ii<m; ii++)
    {   f=0;
        scanf("%lld %lld",&b,&c);
        b--;
        temp=v[b];
        for(int ij=0;ij<n;ij++)
                cout<<v[ij]<<" ";
            cout<<endl;
        do
        {   v[b]=c;
            for(int ij=0;ij<n;ij++)
                cout<<v[ij]<<" ";
            cout<<endl;
            long long int mul=1,factor=1;
            for(int i=0;i<n-1;i++)
            {
                if(v[i]==v[i+1])
                    mul++;
                   else
                   {
                        factor*=fac[mul];
                   }
            }
            flag=0;
            for(i=0; i<n-1; i++)
            {
                if(v[i]+d<=v[i+1])
                {
                    flag=1;
                    break;
                }

            }
            if(flag==0) f=f+factor;
            //v[b]=temp;
        }
        while ( std::next_permutation(v,v+n));
        printf("%lld\n",f);

    }
    return 0;
}
