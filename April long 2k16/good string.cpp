#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,A,K,ham;
    string s,s1,s2;
    cin>>t;
    while(t--)
    {   ham=0;
        cin>>A>>K;
        cin>>s;
        if(s.length()<3)
            {
//                for(int i=0;i<s.length();i++)
//                {
//                    if(s[i]!='a')
//                        ham++;
//                }
//                if(ham<=K)
                    cout<<"1\n"<<endl;
//                else
//                    cout<<"0\n";
            }
        else
            {
                cout<<"0\n";
            }
    }
    return 0;
}
