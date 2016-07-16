#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll M[10][10][1001][1001];
ll P[1001][1001];
/*

THIS WAS  GOOD QUESTION. TOOK ME 4-5 DAYS TO SOLVE!!!!

Algorithm for RMQ taken from Quora:

https://www.quora.com/How-do-I-implement-Two-Dimensional-Range-Minimum-Queries-having-complexity-of-O-1-per-query


Also, referred mainly from:

http://stackoverflow.com/questions/37754330/maximum-element-in-all-axb-sub-matrices-of-nxm-matrix?lq=1

*/
ll m2(ll x, ll y)
{
    if(x>y)
        return x;
    return y;
}
ll m4(ll x,ll y,ll z,ll d)
{
    ll t= m2(x,y);
    ll t2= m2(z,d);
    return m2(t,t2);
}
void pre()
{
    for(ll i=0; (1<<i) <= n; i++)
        for(ll j=0; (1<<j) <= m; j++)
            for(ll x=0; x + (1<<i)-1 < n; x++)
                for(ll y = 0; y + (1<<j) -1 < m; y++)
                {
                    i=(ll)i;
                    j=(ll)j;
                    if (i == 0 && j == 0)
                            M[i][j][x][y] = P[x][y];
                    else if (i == 0)
                            M[i][j][x][y] = m2(M[i][j-1][x][y], M[i][j-1][x][(y+(1<<(j-1)))]);
                    else if (j == 0)
                            M[i][j][x][y] = m2(M[i-1][j][x][y], M[i-1][j][(x+ (1<<(i-1)))][y]);
                    else
                            M[i][j][x][y] = m4(M[i-1][j-1][x][y], M[i-1][j-1][(x + (1<<(i-1)))][y], M[i-1][j-1][x][(y+(1<<(j-1)))], M[i-1][j-1][(x + (1<<(i-1)))][(y+(1<<(j-1)))]);
                }
}

ll RMQ(ll x, ll y, ll x1, ll y1)
{
ll	k = 31-__builtin_clz(x1 - x + 1);
ll l = 31-__builtin_clz(y1 - y + 1);
ll max_element = m4(M[k][l][x][y], M[k][l][(x1 - (1<<k) + 1)][y], M[k][l][x][(y1 - (1<<l) + 1)], M[k][l][(x1 - (1<<k) + 1)][(y1 - (1<<l) + 1)]);
return max_element;
}
ll sum[1001][1001];
int main()
{   ios_base::sync_with_stdio(false);
    ll q,a,b,sol,sol2,temp;
    cin>>n>>m;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
            {
                cin>>P[i][j];
                if(i==0&&j==0)
                    sum[i][j]=P[i][j];
                else if(i==0)
                    sum[i][j]=sum[i][j-1]+P[i][j];
                else if(j==0)
                    sum[i][j]=sum[i-1][j]+P[i][j];
                else
                    sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+P[i][j];
            }
    pre();
    cin>>q;
    while(q--)
    {
        sol=0;
        temp=1e15;
        cin>>a>>b;
        for(ll i = 0; i < n-a+1; i++)
            {
            for(ll j = 0; j < m-b+1; j++)
                {
                sol=RMQ(i,j,i+a-1,j+b-1);
                if(i==0&&j==0)
                    sol2=sum[i+a-1][j+b-1];
                else if(i==0)
                    sol2=sum[i+a-1][j+b-1]-sum[i+a-1][j-1];
                else if(j==0)
                    sol2=sum[i+a-1][j+b-1]-sum[i-1][j+b-1];
                else
                    sol2=sum[i+a-1][j+b-1]-sum[i+a-1][j-1]-sum[i-1][j+b-1]+sum[i-1][j-1];

                    temp = min(sol*a*b - sol2, temp);
                }
            }
        cout<<temp<<endl;
    }
    return 0;
}
