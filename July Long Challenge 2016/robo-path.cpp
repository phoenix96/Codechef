#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
/* DJKISTRA FROM GEEKS4GEEKS.ORG */
# define INF INT_MAX

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;

public:
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v, int w);

    // prints shortest path from s
    int shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
int Graph::shortestPath(int src)
{
    set< pair<int, int> > setds;
    vector<int> dist(V, INF);

    setds.insert(make_pair(0, src));
    dist[src] = 0;
    while (!setds.empty())
    {
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        int u = tmp.second;

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    return dist[m-1];
}



ll check(ll i, ll j)
{
    if(i>=0&&i<n&&j>=0&&j<m)
        return 1;
    return 0;
}
ll matrix[101][101];
int main()
{
    ll t,k1,k2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k1>>k2;
        for(ll i=0; i<n; i++)
            for(ll j=0; j<m; j++)
                cin>>matrix[i][j];


        ll V = n*m;
        Graph g(V);
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                for(ll k=1; k<=k1; k++)
                {
                    if(!matrix[i][j])
                    {
                        //up
                        if(check(i-1,j)&&(!matrix[i-1][j]))
                        {
                            //cout<<"E"<<i*m+j<<"->"<<(i-1)*m+j<<endl;
                            g.addEdge(i*m+j,(i-1)*m+j,1);
                        }
                        //down
                        if(check(i+1,j)&&(!matrix[i+1][j]))
                        {
                            //cout<<"E"<<i*m+j<<"->"<<(i+1)*m+j<<endl;
                            g.addEdge( i*m+j,     (i+1)*m+j, 1);
                        }
                        //left
                        if(check(i,j-1)&&(!matrix[i][j-1]))
                        {
                            //cout<<"E"<<i*m+j<<"->"<<(i)*m+j-1<<endl;
                            g.addEdge( i*m+j, i*m+j-1, 1);
                        }
                        //right
                        if(check(i,j+1)&&(!matrix[i][j+1]))
                        {
                            //cout<<"E"<<i*m+j<<"->"<<i*m+j+1<<endl;
                            g.addEdge( i*m+j, i*m+j+1, 1);
                        }
                    }
                }
                for(ll k=0; k<k2; k++)
                {

                }
            }
        }
        ll ans = g.shortestPath(0);
        if(ans==INF)
        {
            cout<<"-1\n";
            continue;
        }
        else
        {
            ll movesbyk1=0, movesbyk2=0,moves,fans=LONG_LONG_MAX;
            for(int i=0; i<=ans; i++)
            {
                movesbyk1=movesbyk2=0;
                if(k1!=0)
                    movesbyk1 = ceil(i*1.0 / (k1*1.0));
                if(k2!=0)
                    movesbyk2 = ceil((ans-i)*1.0 / (k2*1.0));
                moves=max(movesbyk1, movesbyk2);
                fans=min(fans,moves);
            }
            cout<<fans<<endl;
        }

    }
    return 0;
}
