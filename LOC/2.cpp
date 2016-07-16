#include<bits/stdc++.h>
using namespace std;
int check(string s)
{
    if(s.length()<=1)
        return 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]<'A'||s[i]>'Z')
            return 0;
    }
    return 1;
}
int main()
{
    long long int t,m,n;
    string s,s2;
    int caps=0;
    getline(cin, s);
    s.push_back(' ');
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            if(check(s2)==1)
                caps++;
                s2.clear();
        }
        else
        {
            s2.push_back(s[i]);
        }
    }
    cout<<caps<<endl;
   // getchar();
    exit(0);
}
