#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll net_cost[501][501];
struct b
{
    int init_node;
    int power;
} batch[501][501];
int main()
{
    ll n,m,b,c,temp;
    cin>>n>>m>>b>>c;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>net_cost[i][j];
        }
    }
    for(int i=0; i<m; i++)
    {
        fflush(stdin);
        for(int j=0; j<b; j++)
        {
            cin>>batch[i][j].init_node>>batch[i][j].power;
        }
        for(int j=0; j<b; j++)
        {
            cout<<batch[i][j].init_node<<endl;
        }
    }
    return 0;
}
