#include<bits/stdc++.h>
using namespace std;
long long dp[2001][2001];
long long m3(long long a, long long b, long long c)
{
    long long ans = (a<b)?(a<c)?a:c:(b<c)?b:c;
    return ans;
}

int main()
{
    long long t;
    string s1,s2;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        for(int i=0;i<=s1.length();i++)
        {
            for(int j=0;j<=s2.length();j++)
            {
                if(i==0)
                {
                    dp[i][j]=j;
                }
                else if(j==0)
                {
                    dp[i][j]=i;
                }
                else if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=1+m3(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]);
                }
                //cout<<dp[i][j]<<" ";
            }
        }
         cout<<dp[s1.length()][s2.length()]<<endl;
    }
    return 0;
}
