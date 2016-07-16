#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
pair<int,int> M[201][201][11][11];
ll P[1001][1001];
ll fast_pow[15];
/* Modular Inverse Implementation (fast_pow)from codeaccepted wordpress : https://codeaccepted.wordpress.com/2014/02/15/output-the-answer-modulo-109-7
Algorithm for RMQ taken from Quora:
https://www.quora.com/How-do-I-implement-Two-Dimensional-Range-Minimum-Queries-having-complexity-of-O-1-per-query
*/
ll pre2()
{
    fast_pow[0]=1;
    for(int i=1;i<15;i++)
        fast_pow[i]=fast_pow[i-1]*2ll;
}
pair<ll,ll> m2(pair <ll,ll>x, pair<ll,ll> y)
{
    if(P[x.first][x.second]>=P[y.first][y.second])
        return x;
    return y;
}
pair<ll,ll> m4(pair<ll,ll> x, pair<ll,ll> y, pair<ll,ll> z, pair<ll,ll> d)
{
    pair<ll,ll> t= m2(x,y);
    pair<ll,ll> t2= m2(z,d);
    return m2(t,t2);
}
void pre()
{ pre2();
    ll i,j,x,y;
	for ( i = 0 ;fast_pow[i]<=n;i++)
		for (j = 0; fast_pow[j]<=m;j++)
			for (x = 0 ; x+fast_pow[i]-1<n;x++)
				for (y = 0 ;y+fast_pow[j]-1<m;y++)
					{
                    if      (i == 0 && j == 0)
                            M[x][y][i][j] = make_pair(x,y);
					else if (i == 0)
                            M[x][y][i][j] = m2(M[x][y][i][j-1], M[x][y+fast_pow[(j-1)]][i][j-1]);
					else if (j == 0)
                            M[x][y][i][j] = m2(M[x][y][i-1][j], M[x+ fast_pow[(i-1)]][y][i-1][j]);
                    else
                            M[x][y][i][j] = m4(M[x][y][i-1][j-1], M[x + fast_pow[(i-1)]][y][i-1][j-1],
                            M[x][y+fast_pow[(j-1)]][i-1][j-1], M[x + fast_pow[(i-1)]][y+fast_pow[j-1]][i-1][j-1]);
					}
}

ll RMQ(ll x, ll y, ll x1, ll y1){
	ll k=log(x1-x+1);
	ll l=log(y1-y+1);
	pair<ll,ll> ans = m4(M[x][y][k][l], M[x1-fast_pow[k]+1][y][k][l], M[x][y1-fast_pow[l]+1][k][l],    M[x1-fast_pow[k]+1][y1-fast_pow[l]+1][k][l]);
	return P[ans.first][ans.second];
}


ll sum[1001][1001];

int main()
{
    ll q,a,b,sol,sol2,temp;
    cin>>n>>m;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
            {
                cin>>P[i][j];
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+P[i][j];
            }
    pre();
    cin>>q;
    while(q--)
    {
        sol=0;
        temp=LONG_LONG_MAX;
        cin>>a>>b;
        for(ll i = 0; i < n-a+1; i++)
            {
            for(ll j = 0; j < m-b+1; j++)
                {
                    sol=RMQ(i,j,i+a-1,j+b-1);
                    sol2=sum[i+a-1][j+b-1]-sum[i+a-1][j-1]-sum[i-1][j+b-1]+sum[i-1][j-1];
                    //cout<<sol<<" "<<sol*(a*b)-sol2<<endl;
                    temp=min(sol*(a*b)-sol2,temp);
                }
            }
        cout<<temp<<endl;
    }
    return 0;
}
