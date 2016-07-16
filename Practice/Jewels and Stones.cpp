#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    string s1,s2;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        long long flag=0;
        for(size_t j=0; j<s2.length(); j++)
        {
            for(size_t i=0; i<s1.length(); i++)
            {
                if(s2[j]==s1[i])
                {
                    flag++;
                    break;
                }
            }
        }
        cout<<flag<<endl;

    }
    return 0;
}
