#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int e[100000];
int main()
{
    long long int t,error=0,j,ans=0,len,hlen;
    string s,s1,s2;
    cin>>t;
    while(t--)
    {
        error=0;
        ans=0;
        cin>>s;
        s1=s.substr(0,s.length()/2);
        s2=s.substr(s.length()/2+1,s.length());
        hlen=s.length()/2;
        len=s.length();
        if(ans%2==0)
        {
            if(s1==s2)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
        {
            for(int i=0; i<len; i++)
            {
                if(s[i]==s[hlen+i])
                    e[i]=1;
            }
            for(int i=0; i<len; i++)
            {

            }
        }


    }
    return 0;
}
