#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,error=0,j,ans=0;
    string s,s1,s2;
    cin>>t;
    while(t--)
    {   error=0;
        ans=0;
        cin>>s;
        j=s.length()/2;
        ans=s.length();
        for(int i=0; i<ans-1;)
        {   cout<<"Comp "<<s[i]<<s[j]<<"\n";
            if(s[i]==s[j])
            {   cout<<"Equal"<<endl;
                j++;
                i++;
                continue;
            }
            else
            {   error++;
                if((i<(s.length()-1))&&(j<(s.length()))&&(s[i+1]==s[j]))
                {   if(i!=ans/2+1) s.erase(i,1);
                    else error--;
                    cout<<s<<endl;
                    cout<<i<<" "<<j<<" incremented i\n";
                    i++;
                }
                else if((i<(s.length()))&&(j<(s.length()-i-1))&&(s[i]==s[j+1]))
                {   if(j!=ans/2) s.erase(j,1);
                    else error--;
                    cout<<s<<endl;
                    cout<<i<<" "<<j<<" incremented j\n";
                    j++;
                }
                else
                {
                    cout<<"error"<<endl;
                    error=2;
                }
                if(error>1) break;
            }
        }
        if(error>1) cout<<"NO\n";
        else cout<<"YES\n";
    }
}
