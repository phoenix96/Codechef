#include<bits/stdc++.h>
using namespace std;
 long long ans,pans;
 long long M=1000000007;
 long long fac[100000];
 long long pre()
 {
     fac[0]=1;
     fac[1]=1;
     for(int i=2;i<100000;i++)
     {
         fac[i]=((fac[i-1]%M)*(i%M))%M;
     }
    // cout<<fac[4]<<endl;
     return 0;
 }
// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int v);    // DFS traversal of the vertices reachable from v
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    long long mul=0;
    //cout<<v<<endl;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {   //cout<<*i<<" ";
        if(!visited[*i])
        {
            mul++;
        }
    }
    //cout<<endl<<mul<<endl;
    ans=(ans*(fac[mul]%M))%M;
    // Recur for all the vertices adjacent to this vertex
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}

//int main()
//{
//    // Create a graph given in the above diagram
//    Graph g(4);
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 2);
//    g.addEdge(2, 0);
//    g.addEdge(2, 3);
//    g.addEdge(3, 3);
//
//    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
//    g.DFS(2);
//
//    return 0;
//}




int main()
{
    long long t,n,a,b,k;
    pre();
    cin>>t;
    while(t--)
    {   cin>>n;
        ans=1;pans=-1;
        Graph g(n);
        for(int i=0; i<(n-1); i++)
        {           cin>>a>>b;
                    g.addEdge(a-1,b-1);
                    g.addEdge(b-1,a-1);
        }
        cin>>k;
        g.DFS(k-1);
        cout<<ans<<endl;


    }
    return 0;

}
