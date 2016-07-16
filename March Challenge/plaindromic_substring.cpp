#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,c[26],d[26];
    string a,b;
    int i;
    cin>>t;
    while(t--)
    {
        for(i=0; i<26; i++)
        {
            c[i]=0;
            d[i]=0;
        }
        cin>>a>>b;
        for(i=0; i<a.length(); i++)
        {
            c[a[i]-97]++;
        }
        for(i=0; i<b.length(); i++)
        {
            d[b[i]-97]++;
        }
        for(i=0; i<26; i++)
        {
            if(c[i]>0&&d[i]>0)
            {
                cout<<"Yes\n";
                break;
            }
        }
        if(i==26)
        cout<<"No\n";
    }
    return 0;
}
