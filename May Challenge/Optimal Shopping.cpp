#include<bits/stdc++.h>
#define ll long long
#define rj(i,n) for(ll i=0;i<n;i++)
using namespace std;
vector<ll> adj[100001];
vector<ll> ans;
ll ans_in;
ll w[1000001];
ll graph[1001][1001];
vector <ll> shop_cost[100001];
ll matrix[1001][1001];
vector <ll> dfs;









// Graph class represents a directed graph using adjacency list representation
class GraphDFS
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    GraphDFS(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int v);    // DFS traversal of the vertices reachable from v
};

GraphDFS::GraphDFS(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void GraphDFS::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void GraphDFS::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    dfs.push_back(v);


    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void GraphDFS::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}

/*int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}*/


























// A structure to represent a node in adjacency list
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};

// A structure to represent an adjacency liat
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode =
        (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph( int V )
{
    struct Graph* graph = ( struct Graph* ) malloc( sizeof(struct Graph) );
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Structure to represent a min heap node
struct MinHeapNode
{
    int  v;
    int key;
};

// Structure to represent a min heap
struct MinHeap
{
    int size;      // Number of heap nodes present currently
    int capacity;  // Capacity of min heap
    int *pos;     // This is needed for decreaseKey()
    struct MinHeapNode **array;
};

// A utility function to create a new Min Heap Node
struct MinHeapNode* newMinHeapNode(int v, int key)
{
    struct MinHeapNode* minHeapNode =
        (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}

// A utilit function to create a Min Heap
struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap =
        (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
        (struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// A utility function to swap two nodes of min heap. Needed for min heapify
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size &&
            minHeap->array[left]->key < minHeap->array[smallest]->key )
        smallest = left;

    if (right < minHeap->size &&
            minHeap->array[right]->key < minHeap->array[smallest]->key )
        smallest = right;

    if (smallest != idx)
    {
        // The nodes to be swapped in min heap
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *idxNode = minHeap->array[idx];

        // Swap positions
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        // Swap nodes
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

// A utility function to check if the given minHeap is ampty or not
int isEmpty(struct MinHeap* minHeap)
{
    return minHeap->size == 0;
}

// Standard function to extract minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    if (isEmpty(minHeap))
        return NULL;

    // Store the root node
    struct MinHeapNode* root = minHeap->array[0];

    // Replace root node with last node
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // Update position of last node
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;

    // Reduce heap size and heapify root
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Function to decreasy key value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
void decreaseKey(struct MinHeap* minHeap, int v, int key)
{
    // Get the index of v in  heap array
    int i = minHeap->pos[v];

    // Get the node and update its key value
    minHeap->array[i]->key = key;

    // Travel up while the complete tree is not hepified.
    // This is a O(Logn) loop
    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key)
    {
        // Swap this node with its parent
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swapMinHeapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);

        // move to parent index
        i = (i - 1) / 2;
    }
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
bool isInMinHeap(struct MinHeap *minHeap, int v)
{
    if (minHeap->pos[v] < minHeap->size)
        return true;
    return false;
}
// A utility function used to print the constructed MST
void printArr(int arr[], int n)
{
    GraphDFS g(n);
    for (int i = 1; i < n; ++i)
    {
        g.addEdge(arr[i],i);
        g.addEdge(i,arr[i]);
        matrix[i][arr[i]]=1;
        matrix[arr[i]][i]=1;
    }
    // cout<<"dfs"<<endl;
    g.DFS(0);
    //printf("%d - %d\n", arr[i], i);
}

// The main function that constructs Minimum Spanning Tree (MST)
// using Prim's algorithm
void PrimMST(struct Graph* graph)
{
    int V = graph->V;//Get the number of vertices in graph
    int parent[V];   //Array to store constructed MST
    int key[V];      //Key values used to pick minimum weight edge in cut

    // minHeap represents set E
    struct MinHeap* minHeap = createMinHeap(V);

    // Initialize min heap with all vertices. Key value of
    // all vertices (except 0th vertex) is initially infinite
    for (int v = 1; v < V; ++v)
    {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    // Make key value of 0th vertex as 0 so that it
    // is extracted first
    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0]   = 0;

    // Initially size of min heap is equal to V
    minHeap->size = V;

    // In the followin loop, min heap contains all nodes
    // not yet added to MST.
    while (!isEmpty(minHeap))
    {
        // Extract the vertex with minimum key value
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v; // Store the extracted vertex number

        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their key values
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;

            // If v is not yet included in MST and weight of u-v is
            // less than key value of v, then update key value and
            // parent of v
            if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v])
            {
                key[v] = pCrawl->weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    // print edges of MST
    printArr(parent, V);
}

// Driver program to test above functions
/*int main()
{
    // Let us create the graph given in above fugure
    int V = 9;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    PrimMST(graph);

    return 0;
}*/




















int main()
{
    ll n, m, k, f, p,shop,cost,a,b,weight;
    cin>>n>>m>>k>>f;
    // V=n;
    /*
    5 4 5 100
    5 100 1 11 2 22 3 33 4 44 5 55
    4 100 1 11 2 1 3 33 4 44
    3 100 4 3 2 1 3 0
    1 23 4 2
    5 122 1 11 2 22 3 33 4 44 5 1
    1 2 100
    1 3 100
    1 4 100
    1 5 100
    */
    rj(i,k)
    {
        ll cost_min = 1e9, shop_min=0;
        cin>>p>>w[i];
        rj(j,p)
        {
            cin>>shop>>cost;
            if(cost < cost_min)
            {
                cost_min=cost;
                shop_min=shop;
            }
//            shop_cost[shop][j+1]=cost;
        }
        shop_cost[shop_min].push_back(i);
        // cout<<"p and w[i] done and minimum found"<<endl;
    }
    struct Graph* graph = createGraph(n);
    rj(i,m)
    {
        cin>>a>>b>>weight;
        addEdge(graph, a-1, b-1, weight);
    }
    PrimMST(graph);



    ans.push_back(dfs[0]);
    for(int i=1; i<dfs.size(); i++)
    {
        cout<<dfs[i]<<" ";
        if(matrix[dfs[i]][dfs[i-1]])
                {
                    ans.push_back(dfs[i]);
                    continue;
                }
        for(int j=i-2; j>=0; j--)
        {
            ans.push_back(ans[i]);

            if(matrix[ans[i]][dfs[i]])
            {
                    ans.push_back(dfs[i]);
                    for(int k=0;k<i-j-1;k++)
                    {
                        ans.push_back(ans[k+j]);
                    }
                    break;
            }
        }

    }
cout<<endl;
for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";



cout<<"bakchodi hi jeevan hai!";





    ll flag=0;
    vector<ll> ans2;
    vector<ll> fans;
    rj(i,ans_in)
    {

        //cout<<i<<endl;
        if(ans[i]!=0)
            fans.push_back(ans[i]+1);


        if(ans[i]==(n-1)||flag==1)
        {
            ans2.push_back(ans[i]+1);
            flag=1;
        }
        for(vector<ll>::iterator j = shop_cost[ans[i]].begin(); j!= shop_cost[ans[i]].end(); j++)
            fans.push_back(-1*(*j+1));
    }
    //cout<<"out"<<endl;
    for(ll j = ans2.size()-2; j >=0; j--)
    {
        //cout<<ans2[j]<<" ";
        fans.push_back(ans2[j]);
    }
    // cout<<"final out"<<endl;
    cout<<fans.size()<<endl;
    for(ll i=0; i<fans.size(); i++)
        cout<<fans[i]<<" ";

    return 0;
}
