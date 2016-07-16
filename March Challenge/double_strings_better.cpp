#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int freq[26];
int main()
{
    long long int i,t,o,j,no,opos,lol,flag=0;
    string s,ls,rs;
    cin>>t;
    while(t--)
    {
        o=0,opos=-1;
        lol=0;
        cin>>s;
        for(i=0; i<26; i++)
            freq[i]=0;
        for(i=0; i<s.length(); i++)
            freq[s[i]-97]++;

        for(i=0; i<26; i++)
        {
            if(freq[i]%2!=0)
            {
                o++;
                opos=i;
                cout<<opos<<endl;
            }
        }
        cout<<o<<endl;
        if(o==0)
        {
            cout<<s.substr(0,s.length()/2)<<","<<s.substr(s.length()/2)<<endl;

            if(s.substr(0,s.length()/2)==s.substr(s.length()/2))
            {
                cout<<"YES\n";
            }
            else
                cout<<"NO\n";
        }
        else if(o==1)
        {   flag=0;no=0;i=0;
            ls=s.substr(0,s.length()/2+1);
            cout<<"Left String: "<<ls<<endl;
            rs=s.substr(s.length()/2+1,s.length()/2+1);
            cout<<"Right String: "<<rs<<endl;
            if(ls[0]!=rs[0])
            {
                cout<<"swapped!"<<endl;
                rs=s.substr(0,s.length()/2);
                ls=s.substr(s.length()/2);
                cout<<"Left String: "<<ls<<endl;
                cout<<"Right String: "<<rs<<endl;
            }
            for(int j=0; j<rs.length(); i++,j++)
            {
                cout<<ls[i]<<" "<<rs[j]<<endl;
                if(ls[i]!=rs[j])
                {
                    cout<<"NE"<<endl;
                    j--;
                    flag++;
                    if(flag>1)
                    {
                        // cout<<"BREAKED!"<<endl;
                        no=1;
                        break;
                    }
                }
            }
            cout<<s.substr(1,s.length()/2)<<endl;
            cout<<s.substr(s.length()/2+1,s.length())<<endl;
            if(s.substr(1,s.length()/2)==s.substr(s.length()/2+1,s.length()))
                no=0;
            if(no==1) cout<<"NO\n";
            else
                cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;
}

