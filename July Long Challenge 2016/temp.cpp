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
        ll max_power, max_power_init_node, max_power_pos, max_power_final_node;
        ll least_load, least_load_no;
        for(int j=0; j<b; j++)
        {
            max_power =  LONG_LONG_MIN;

            for(int k=0;k<b;k++)
            {
                if(batch[i][k].power>max_power)
                {
                    max_power = batch[i][k].power;
                    max_power_init_node = batch[i][k].init_node;
                    max_power_final_node = batch[i][k].final_node;
                    max_power_pos = batch[i][k].pos;
                }
            }

            least_load = LONG_LONG_MAX;

            for(int k=0;k<n;k++)
            {
                if(least_load > tload[k].load)
                {
                    least_load = tload[k].load;
                    least_load_no = k;
                }
            }
                batch[i][max_power_pos].power = INT_MIN;
                tload[least_load_no].load+= max_power;
                cout<<least_load_no+1<<endl;
        }
    }
    return 0;
}
