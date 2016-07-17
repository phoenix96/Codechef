/*                                                                              Rishabh Jain
                                                                Jaypee Institute of Information Technology
*/


#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
    bool debug = false;
#else
    bool debug = true;
#endif
typedef long long ll;
//definition
#define vll vector < ll >
#define pll pair<ll, ll>
#define rr freopen("input.txt", "r", stdin)
#define wr freopen("output.txt", "w", stdout)

//important constants
#define MOD 1000000007
#define INF 1LL<<57LL
#define MAX 1000000
#define pi 3.14159265358979
#define ESP (1e-9)

//looping
#define fr(i,a) for(i=0;i<a;i++)
#define fe(i,a) for(i=0;i<=a;i++)
#define fu(i,a,n) for(i=a;i<n;i++)
#define fue(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>a;i--)
#define fde(i,n,a) for(i=n;i>=a;i--)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define pb push_back
#define gcd(a,b)  __gcd(a,b)
#define all(vi) vi.begin(), vi.end()
#define mem(i,n) memset(i,n,sizeof(i))
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)

#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define llmax numeric_limits<ll>::max()
#define llmin numeric_limits<ll>::min()

ll dp[1001][1001];
ll pass[1001];
ll M,N;
int main()
{   if(!debug)
    {
        rr;wr;
    }
    ll t,n,s;
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
            for(int j=0;j<N;j++)
            {
                cout<<dp[M][j]<<" ";
            }
            cout<<endl;
    }
    return 0;
}
