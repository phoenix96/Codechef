#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll matrix[10002];
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
int main()
{




    ll t,k1,k2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k1>>k2;
        for(ll i=0; i<n*m; i++)
        {
            cin>>matrix[i];
        }
        //BFS
        // Mark all the vertex as not visited
        V = n*m;
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                list<int> queue; // Create a queue for BFS
                visited[s] = true; // Mark the current node as visited and enqueue it
                queue.push_back(s);
                list<int>::iterator i;// 'i' will be used to get all adjacent vertices of a vertex
                while(!queue.empty())
                {
                    // Dequeue a vertex from queue and print it
                    s = queue.front();
                    cout << s << " ";
                    queue.pop_front();

                    // Get all adjacent vertices of the dequeued vertex s
                    // If a adjacent has not been visited, then mark it visited
                    // and enqueue it
                    for(i = adj[s].begin(); i != adj[s].end(); ++i)
                    {
                        if(!visited[*i])
                        {
                            visited[*i] = true;
                            queue.push_back(*i);
                        }
                    }
                }


            }
        }

//ans here

    }


}
