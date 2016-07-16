#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll matrix[101][101];
ll moves_req_by_k1[101][101];
ll moves_req_by_k2[101][101];
//util
ll check(ll i, ll j)
{
    if(i>=0&&i<n&&j>=0&&j<m)
        return 1;
    return 0;
}
//util
ll xytoin(ll x, ll y)
{
   return x*m+y;
}
pair <ll,ll> intoxy(queue q)
{
    in = *(q.begin());
    pair<ll,ll> p;
    p.first = in/m;
    p.second = in%m;
}
int movesk1(set<ll> q, ll moves, ll visited[])
{
    if(q.empty())
        return 1;
    pair index = intoxy(q);
    ll i = index.first;
    ll j = index.second;
    visited[i*m+j]=1;
    //up
    if(check(i-1,j)&&(!matrix[i-1][j])&&2)
    {
         moves_req_by_k1[i-1][j] = ceil(moves*1.0/k1*1.0);
         q.insert(xytoin(i-1,j));
    }
    //down
    if(check(i+1,j)&&(!matrix[i+1][j]))
    {
         moves_req_by_k1[i-1][j] = ceil(moves*1.0/k1*1.0);
         q.insert(xytoin(i-1,j));
    }
    //left
    if(check(i,j-1)&&(!matrix[i][j-1]))
    {
        moves_req_by_k1[i-1][j] = ceil(moves*1.0/k1*1.0);
        q.insert(xytoin(i-1,j));
    }
    //right
    if(check(i,j+1)&&(!matrix[i][j+1]))
    {
        moves_req_by_k1[i-1][j] = ceil(moves*1.0/k1*1.0);
        q.insert(xytoin(i-1,j));
    }
    q.erase(q.find(i*m+j));
}
int main()
{
    ll t,k1,k2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k1>>k2;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                moves_req_by_k1[i][j]=moves_req_by_k2[i][j]=LONG_LONG_MAX;
            }
        }
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                if(!matrix[i][j])
                    moves_req_by_k1[i][j]= ceil((i+j)*1.0/k1*1.0);
                cout<<moves_req_by_k1[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                moves_req_by_k2[i][j]= ceil((i+j)*1.0/k2*1.0);
            }
        }
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                cout<<moves_req_by_k2[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
        ll moves=0;
        ll ans=LONG_LONG_MAX;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                if(!matrix[i][j])
                {
                    moves=max(moves_req_by_k1[i][j],moves_req_by_k2[i][j]);
                    ans=min(ans,moves);
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
/*
2
4 4 1 1
0 1 1 0
0 1 1 0
0 1 1 0
0 0 0 0
4 4 1 1
0 1 1 0
0 1 1 0
0 1 1 0
1 0 0 1


5
-1
*/
