#include<bits/stdc++.h>
using namespace std;
int main()
{   long long int tt,n;char s[550]; char s2[550];
    cin>>tt;
    while(tt--)
    {
        cin>>s;
        cin>>s2;
        for(int i=0;i<strlen(s);i++)
        {
            s[i]=tolower(s[i]);
        }
        for(int i=0;i<strlen(s2);i++)
        {
            s2[i]=tolower(s2[i]);
        }
        if(strcmp(s,s2)>0)
        {
            cout<<"second\n";
        }
        else if(strcmp(s,s2)<0)
        {
            cout<<"first\n";
        }
        else
            cout<<"equal\n";

    }
    return 0;
}
