#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int s[100001];
int main()
{   ios_base::sync_with_stdio(false);
    long long int n,h;
    cin>>n>>h;
    for(int i=0;i<n;i++)
        cin>>s[i];
    long long int k=1;
    long long int c=0;
    int oc=0;
    while(k)
    {
        cin>>k;
        switch(k)
        {
            case 1: if(c!=0) c--; break;
            case 2: if(c!=(n-1)) c++; break;
            case 3: if(oc==0&&s[c]!=0) {s[c]--; oc=1; }break;
            case 4: if(oc==1&&s[c]!=h) {s[c]++; oc=0; }break;
            default: break;
        }
    }
    for(int i=0;i<n;i++)
        cout<<s[i]<<" ";
 
}