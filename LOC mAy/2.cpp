#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%2==0)
            cout<<"JACK\n";
        else
            cout<<"JENNY\n";
    }
    return 0;
}
