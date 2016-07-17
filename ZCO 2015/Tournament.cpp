#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a[200001];
int main()
{   long long int n,s=0,fs=0,k;
    cin>>n;
    k=n;
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        fs+=k*a[i]-s;
        k--;
        s-=a[i];
    }
    fs=-fs;
    cout<<fs;
    return 0;
}