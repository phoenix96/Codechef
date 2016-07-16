#include<bits/stdc++.h>
using namespace std;
int main()
{   long long int M=1000000000+7;
    long long int tt,l,ans,sim,c;
    cin>>tt;
    char s[1000],s1[1000],s2[1000];
    while(tt--)
    {
        ans=0;
        sim=0;
        cin>>s;
        sort(s,s+(strlen(s)));
        int p=1;
        strcpy(s1,s);
        l=strlen(s);
        long long ris=0;
        long long ans2=0;
            do
            {
                c=0;
                for(int i=0; i<l; i++)
                {
                    if(s[i]!=s1[i])
                        c++;
                }
                if(c==4)
                {
                    ans2++;
                    ans2=ans2%M;
                }
                else if(c>4&&p==1)
                {
                    ans++;
                    ans=ans%M;
                }
            }
            while(next_permutation(s1,s1+l));

        cout<<(ans+(2LL*ans2/3LL))%M<<endl;
    }
    return 0;

}

