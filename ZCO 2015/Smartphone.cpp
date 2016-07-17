#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long int a[500000];
int main()
{   ios_base::sync_with_stdio(false);
    long long int n;
    cin>>n;
    //n=50000;
    for(int i=0;i<n;i++)
        cin>>a[i];
    //    memset(a,0,sizeof(a));
        //cout<<a[0]<<" ";
    sort(a,a+n);
    long long int m=a[0]*n;
    for(long long int j=1;j<n;j++)
    {
        if(a[j]*(n-j)>m)
            m=a[j]*(n-j);
    }
    cout<<m<<"\n";
    return 0;
}