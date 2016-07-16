// GEEK4GEEKS IMPLEMENTATION OF GRAPH
//http://www.geeksforgeeks.org/find-if-there-is-a-path-between-two-vertices-in-a-given-graph/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Graph
{
    ll V;    // No. of vertices
    list<ll> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(ll V);  // Constructor
    void addEdge(ll v, ll w); // function to add an edge to graph
    bool isReachable(ll s, ll d);
};

Graph::Graph(ll V)
{
    this->V = V;
    adj = new list<ll>[V];
}

void Graph::addEdge(ll v, ll w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// A BFS based function to check whether d is reachable from s.
bool Graph::isReachable(ll s, ll d)
{
    // Base case
    if (s == d)
      return true;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (ll i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<ll> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // it will be used to get all adjacent vertices of a vertex
    list<ll>::iterator i;

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            // If this adjacent node is the destination node, then
            // return true
            if (*i == d)
                return true;

            // Else, continue to do BFS
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    // If BFS is complete without visiting d
    return false;
}
int main()
{
    ll n,a,b,q;
    cin>>n;
    Graph g(n);
    for(ll i=0;i<n-1;i++)
    {
        cin>>a>>b;
        g.addEdge(a-1,b-1);
    }
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        if(g.isReachable(a-1, b-1))
            cout<<a<<" taught "<<b<<endl;
        else if(g.isReachable(b-1, a-1))
            cout<<b<<" taught "<<a<<endl;
        else
            cout<<"No idea"<<endl;
    }
    return 0;
}
