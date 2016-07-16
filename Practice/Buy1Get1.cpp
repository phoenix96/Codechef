#include<bits/stdc++.h>
int alpha[52];
using namespace std;
int main()
{
    long long t,ans;
    string s;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {ans=0;
        for(int i=0;i<52;i++)
            alpha[i]=0;
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            alpha[s[i]-'A']++;
            else if(s[i]>='a'&&s[i]<='z')
                alpha[s[i]-'a'+26]++;
        }
//        for(int i=0;i<52;i++)
//            cout<<alpha[i]<<",";
//        cout<<endl;
        for(int i=0;i<52;i++)
        {
            ans+=ceil(alpha[i]*1.0/2.0);
        }
        cout<<ans<<endl;
    }
    return 0;
}
