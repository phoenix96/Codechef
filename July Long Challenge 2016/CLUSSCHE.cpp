#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll net_cost[501][501];
struct b
{   int init_node;
    int power;
    int pos;
    int final_node;
} batch[501][501];
struct t
{
    int n;
    int load;
} tload[501];
bool load( const t & lhs, const t & rhs )
{
    return lhs.load<rhs.load;
}
bool power( const b & lhs, const b & rhs )
{
    return lhs.power>rhs.power;
}
bool pos( const b & lhs, const b & rhs )
{
    return lhs.pos<rhs.pos;
}
int main()
{
    ll n,m,b,c,temp;
    cin>>n>>m>>b>>c;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>net_cost[i][j];
    ll net=0;
    for(int j=0; j<n; j++)
    {
        tload[j].n=j;
        tload[j].load=0;
    }
    for(int i=0; i<m; i++)
    {
        fflush(stdin);
        for(int j=0; j<b; j++)
        {
            cin>>batch[i][j].init_node>>batch[i][j].power;
            batch[i][j].init_node--;
            batch[i][j].pos=j;
            batch[i][j].final_node=batch[i][j].init_node;
        }
        sort(batch[i],batch[i]+b,power);
        for(int j=0; j<b; j++)
        {

            if(i==0 && j==0)
                {
                    batch[i][j].final_node=batch[i][j].init_node;
                    tload[batch[i][j].init_node].load+=batch[i][j].power;
                    sort(tload,tload+n,load);
                    continue;
                }
            for(int k=0; k<n; k++)
            {
                if((net + net_cost[batch[i][j].init_node][tload[k].n])<=c)
                {
                    tload[k].load+=batch[i][j].power;
                    net+=net_cost[batch[i][j].init_node][tload[k].n];
                    batch[i][j].final_node=tload[k].n;
                    break;
                }
            }
            sort(tload,tload+n,load);
        }
        sort(batch[i],batch[i]+b,pos);
        for(int j=0; j<b; j++)
        {
            cout<<batch[i][j].final_node+1<<endl;
        }
    }
    return 0;
}
