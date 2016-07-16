#include<bits/stdc++.h>
using namespace std;
int lh[27];
int rh[27];
int main()
{   ios_base::sync_with_stdio(false);
    int t,n,k,ans,flag;
    string s;
    cin>>t;
    while(t--)
    {   cin>>s;
        flag=0;
        for(int i=1;i<=26;i++)
        {
            lh[i]=0;
            rh[i]=0;
        }
        if(s.length()%2!=0) s.erase(s.begin()+s.length()/2);
        for(int i=0;i<s.length()/2;i++)
        {   //cout<<s[i];
            lh[s[i]-97]++;
        }
        //cout<<endl;
        for(int i=s.length()/2;i<s.length();i++)
        {   //cout<<s[i];
            rh[s[i]-97]++;
        }
        //cout<<endl;
        for(int i=1;i<=26;i++)
        {
            if(lh[i]!=rh[i])
            {   //cout<<i<<endl;
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
        }
        if(flag!=1)
        cout<<"YES"<<endl;
    }
    return 0;
}
