#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:

    Graph(int vertices)
    {
        V=vertices;
        adj.resize(V);
    }

    // Add edge for undirected graph
    void addEdge(int u,int v)
    {
        if(u>=0 && u<V && v>=0 && v<V)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    // Recursive DFS
    void DFSUtil(int node,vector<bool>& visited)
    {
        visited[node]=true;
        cout<<node<<" ";

        for(int neighbor:adj[node])
        {
            if(visited[neighbor]==false)
            {
                DFSUtil(neighbor,visited);
            }
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(V,false);

        cout<<"DFS Traversal: ";
        DFSUtil(start,visited);
        cout<<endl;
    }
  
    // Recursive BFS
    void BFSRecursive(queue<int>& q,vector<bool>& visited)
    {
        if(q.empty()==true)
        {
            return;
        }

        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(int neighbor:adj[node])
        {
            if(visited[neighbor]==false)
            {
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }

        BFSRecursive(q,visited);
    }

    void BFS(int start)
    {
        vector<bool> visited(V,false);
        queue<int> q;

        visited[start]=true;
        q.push(start);

        cout<<"BFS Traversal: ";
        BFSRecursive(q,visited);
        cout<<endl;
    }
};

int main()
{
    int V,E;
    cout<<"Enter number of vertices: ";
    cin>>V;
    Graph g(V);
    cout<<"Enter number of edges: ";
    cin>>E;
    cout<<"Enter edges (u v):"<<endl;

    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    int start;
    cout<<"Enter starting vertex: ";
    cin>>start;

    if(start>=0 && start<V)
    {
        g.DFS(start);
        g.BFS(start);
    }
    else
    {
        cout<<"Invalid starting vertex!"<<endl;
    }
    return 0;
}
/*
DFS Algorithm
    Create visited array.
    Mark current node visited.
    Print node.
    Recursively visit adjacent unvisited nodes.
BFS Algorithm
    Create queue and visited array.
    Insert source node into queue.
    Remove node from queue.
    Visit adjacent unvisited nodes.
    Add adjacent nodes into queue.
    Repeat until queue becomes empty.
Applications of DFS
    Path finding
    Cycle detection
    Topological sorting
    Maze solving
Applications of BFS
    Shortest path
    Social networking
    GPS navigation
    Web crawling
Advantages
DFS
    Requires less memory
    Easy recursive implementation
BFS
    Finds shortest path
    Level-order traversal
*/