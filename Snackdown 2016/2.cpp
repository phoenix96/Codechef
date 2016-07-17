#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,n;
    char ch;
    ll ans = 97;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=97;
        for(int i=0;i<n;i++)
        {
            printf("%c",ans);
            ans++;
            if(ans==123)
                ans=97;
        }
        cout<<endl;
    }
    return 0;
}
