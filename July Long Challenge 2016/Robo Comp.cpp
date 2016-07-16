/*
DJKISTRA FROM GEEKS4GEEKS.ORG
*/
#include<bits/stdc++.h>
using namespace std;
int p[10000];
int movesk1[10000];
int movesk2[10000];
int n,m;
short matrix[100][100];
# define INF INT_MAX
class Graph
{
    int V;
    list< pair<int, int> > *adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    int shortestPath(int s, int flag);
};


Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}
int Graph::shortestPath(int src, int flag)
{
    set< pair<int, int> > setds;
    vector<int> dist(V, INF);
    for(int i=0;i<=10001;i++)
        p[i]=-1;
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
				p[v] = u ;
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    int c=0;
    for (int i = 0; i < V; ++i)
    {   int j=i; c=0;
        while(p[j]!=-1)
        {
                j=p[j];
                c++;
        }
        if(dist[i]==INF) c=INT_MAX;
        if(flag==1)
            movesk1[i]=c;
        else
            movesk2[i]=c;
    }
    movesk1[0]=0;
    movesk2[m-1]=0;
    return 0;
}
int check(int i, int j)
{
    if(i>=0&&i<n&&j>=0&&j<m)
        return 1;
    return 0;
}
int main()
{   ios_base::sync_with_stdio(false);
    int t,k1,k2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k1>>k2;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>matrix[i][j];

        int V = n*m;
        Graph g(V);
        int mo=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!matrix[i][j])
                {mo=0;
                    for(int ki=k1; ki>=0; ki--)
                    {
                        for(int kj=0; kj<k1-ki+1; kj++ )
                        {
                            if(ki==0&&kj==0)
                                continue;
                            else if(ki!=0 && kj==0)
                            {
                                //down
                                if(check(i+ki,j)&&(!matrix[i+ki][j]))
                                {
                                    ////cout<<"DRE"<<i*m+j<<"->"<<(i+ki)*m+j+kj<<" "<<" "<<ki<<" "<<kj<<endl;
                                    mo++;
                                    g.addEdge(i*m+j,(i+ki)*m+j,1);
                                }
                                //up
                                if(check(i-ki,j)&&(!matrix[i-ki][j]))
                                {
                                    ////cout<<"URE"<<i*m+j<<"->"<<(i-ki)*m+j+kj<<" "<<ki<<" "<<kj<<endl;
                                    mo++;
                                    g.addEdge(i*m+j,(i-ki)*m+j,1);
                                }
                            }
                            else if(kj!=0 && ki==0)
                            {   //right
                                if(check(i,j+kj)&&(!matrix[i][j+kj]))
                                {
                                    ////cout<<"DRE"<<i*m+j<<"->"<<(i+ki)*m+j+kj<<" "<<" "<<ki<<" "<<kj<<endl;
                                    mo++;
                                    g.addEdge(i*m+j,(i)*m+j+kj,1);
                                }
                                //left
                                if(check(i,j-kj)&&(!matrix[i][j-kj]))
                                {
                                    ////cout<<"DLE"<<i*m+j<<"->"<<(i)*m+j-kj<<" "<<ki<<" "<<kj<<endl;
                                    mo++;
                                    g.addEdge(i*m+j,(i)*m+j-kj,1);
                                }
                            }
                            else
                            {   //down-right
                                if(check(i+ki,j+kj)&&(!matrix[i+ki][j+kj]))
                                {
                                    ////cout<<"DRE"<<i*m+j<<"->"<<(i+ki)*m+j+kj<<" "<<" "<<ki<<" "<<kj<<endl;
                                    mo++;
                                    g.addEdge(i*m+j,(i+ki)*m+j+kj,1);
                                }
                                //up-right
                                if(check(i-ki,j+kj)&&(!matrix[i-ki][j+kj]))
                                {
                                    ////cout<<"URE"<<i*m+j<<"->"<<(i-ki)*m+j+kj<<" "<<ki<<" "<<kj<<endl;
                                    mo++;
                                    g.addEdge(i*m+j,(i-ki)*m+j+kj,1);
                                }
                                //down-left
                                if(check(i+ki,j-kj)&&(!matrix[i+ki][j-kj]))
                                {
                                    ////cout<<"DLE"<<i*m+j<<"->"<<(i+ki)*m+j-kj<<" "<<ki<<" "<<kj<<endl;
                                    mo++;
                                    g.addEdge(i*m+j,(i+ki)*m+j-kj,1);
                                }
                                //up-left
                                if(check(i-ki,j-kj)&&(!matrix[i-ki][j-kj]))
                                {
                                    ////cout<<"ULE"<<i*m+j<<"->"<<(i-ki)*m+j-kj<<" "<<ki<<" "<<kj<<endl;
                                    mo++;
                                    g.addEdge(i*m+j,(i-ki)*m+j-kj,1);
                                }

                            }
                        }
                    }

                }
                ////cout<<mo<<" ";

            }
            //cout<<endl;
        }
        ////cout<<"----------------------------------------------------------------";
        g.shortestPath(0,1);
        Graph g2(V);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!matrix[i][j])
                {
                    for(int ki=k2; ki>=0; ki--)
                    {
                        for(int kj=0; kj<k2-ki+1; kj++ )
                        {
                            if(ki==0&&kj==0)
                                continue;
                            else if(ki!=0 && kj==0)
                            {
                                //down
                                if(check(i+ki,j)&&(!matrix[i+ki][j]))
                                {
                                    ////cout<<"DRE"<<i*m+j<<"->"<<(i+ki)*m+j+kj<<" "<<" "<<ki<<" "<<kj<<endl;
                                    g2.addEdge(i*m+j,(i+ki)*m+j+kj,1);
                                }
                                //up
                                if(check(i-ki,j)&&(!matrix[i-ki][j]))
                                {
                                    ////cout<<"URE"<<i*m+j<<"->"<<(i-ki)*m+j+kj<<" "<<ki<<" "<<kj<<endl;
                                    g2.addEdge(i*m+j,(i-ki)*m+j+kj,1);
                                }
                            }
                            else if(kj!=0 && ki==0)
                            {   //right
                                if(check(i,j+kj)&&(!matrix[i][j+kj]))
                                {
                                    ////cout<<"DRE"<<i*m+j<<"->"<<(i+ki)*m+j+kj<<" "<<" "<<ki<<" "<<kj<<endl;
                                    g2.addEdge(i*m+j,(i+ki)*m+j+kj,1);
                                }
                                //left
                                if(check(i,j-kj)&&(!matrix[i][j-kj]))
                                {
                                    ////cout<<"DLE"<<i*m+j<<"->"<<(i)*m+j-kj<<" "<<ki<<" "<<kj<<endl;
                                    g2.addEdge(i*m+j,(i)*m+j-kj,1);
                                }
                            }
                            else
                            {   //down-right
                                if(check(i+ki,j+kj)&&(!matrix[i+ki][j+kj]))
                                {
                                    ////cout<<"DRE"<<i*m+j<<"->"<<(i+ki)*m+j+kj<<" "<<" "<<ki<<" "<<kj<<endl;
                                    g2.addEdge(i*m+j,(i+ki)*m+j+kj,1);
                                }
                                //up-right
                                if(check(i-ki,j+kj)&&(!matrix[i-ki][j+kj]))
                                {
                                    ////cout<<"URE"<<i*m+j<<"->"<<(i-ki)*m+j+kj<<" "<<ki<<" "<<kj<<endl;
                                    g2.addEdge(i*m+j,(i-ki)*m+j+kj,1);
                                }
                                //down-left
                                if(check(i+ki,j-kj)&&(!matrix[i+ki][j-kj]))
                                {
                                    ////cout<<"DLE"<<i*m+j<<"->"<<(i+ki)*m+j-kj<<" "<<ki<<" "<<kj<<endl;
                                    g2.addEdge(i*m+j,(i+ki)*m+j-kj,1);
                                }
                                //up-left
                                if(check(i-ki,j-kj)&&(!matrix[i-ki][j-kj]))
                                {
                                    g2.addEdge(i*m+j,(i-ki)*m+j-kj,1);
                                }

                            }
                        }
                    }
                }
            }
        }
        g2.shortestPath(m-1,2);

//        for(int i=0;i<n*m;i++)
//            {
//                ////cout<<movesk1[i]<<" ";
//            }
//            ////cout<<endl;
//
//        for(int i=0;i<n*m;i++)
//            {
//                ////cout<<movesk2[i]<<" ";
//            }
//            ////cout<<endl;
            int moves=INT_MIN,fans=INT_MAX;
            for(int i=0; i<n*m; i++)
            {
                    moves=max(movesk1[i],movesk2[i]);
                    fans=min(fans,moves);
            }
            if(fans!=INT_MAX)
                    cout<<fans<<endl;
            else
                    cout<<"-1\n";

    }
    return 0;
}
/*
100
10 10 0 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
10 10 1 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
10 10 2 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
10 10 3 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
10 10 4 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
15 15 5 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
10 10 6 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
10 10 7 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
10 10 8 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
10 10 9 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
21 21 10 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/
