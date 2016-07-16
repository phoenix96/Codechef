#include<bits/stdc++.h>
using namespace std;
int f[26];
long long fac(long long n)
{
    long long int ret = 1;
    for(long long  int i = 1; i <= n; ++i)
        ret *= i;
    return ret;
}
int main()
{
    long long t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        long long o=0,e=0;
        for(int i=0; i<26; i++)
            f[i]=0;
        for(int i=0; i<s.length(); i++)
            f[s[i]-97]++;
        for(int i=0; i<26; i++)
        {   //cout<<f[i]<<",";
            if(f[i]%2!=0)
                o++;
        }
        if(o>1)
        {
            cout<<"-1\n";
            continue;
        }
        else
        {
            long long ans = fac(s.length()/2);
            for(int i=0; i<26; i++)
            {
                if(f[i]%2==0)
                {
                    ans/=fac(f[i]/2);
                }
            }
            cout<<ans<<endl;
        }

    }
    return 0;
}

