#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1001][1001];
ll pass[1001];
ll M,N;
int main()
{
    ll t,n,s;
    ll MOD =1000000000+7;
    cin>>t;
    while(t--)
    {
        cin>>N>>M>>s;
        for(int i=0; i<M; i++)
            cin>>pass[i];


        for(int i=0; i<=M; i++)
        {
            for(int j=0;j<N;j++)
            {
                dp[i][j]=0;
            }

        }

        dp[0][s-1]=1;


        for(int i=0; i<M; i++)
        {
            for(int j=0;j<N;j++)
            {
                if(dp[i][j]!=0)
                        {
                            if(j+pass[i]<N&&j+pass[i]>=0)
                                dp[i+1][j+pass[i]]=((dp[i+1][j+pass[i]])%MOD+(dp[i][j])%MOD)%MOD;
                            if(j-pass[i]<N&&j-pass[i]>=0)
                                dp[i+1][j-pass[i]]=((dp[i+1][j-pass[i]])%MOD+(dp[i][j])%MOD)%MOD;
                        }
            }
        }




        //for(int i=0; i<=M; i++)
        //{
            for(int j=0;j<N;j++)
            {
                cout<<dp[M][j]<<" ";
            }
            cout<<endl;

        //}











//        for(int i=0; i<N; i++)
//            cout<<dp[N][i]<<" ";
//        cout<<endl;
    }
    return 0;
}
