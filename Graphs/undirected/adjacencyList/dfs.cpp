#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>> adj, vector<int> &ans, vector<bool> &Visited)
{
    Visited[node] = 1;
    ans.push_back(node);

    for (int i = 0; i < adj[node].size(); i++)
    {
        int neightbor = adj[node][i];
        if (!Visited[neightbor])
        {
            dfs(neightbor, adj, ans, Visited);
        }
    }
}

int main()
{
    // vector<int> vertexValues = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // for vertex

    vector<int> ans;
    vector<vector<int>> adjList = {
        // for vertex adjacency list
        {1, 2},
        {0, 5, 7},
        {0, 3, 4},
        {2},
        {2},
        {1, 6},
        {5, 8},
        {1, 8},
        {6, 7}};

    vector<bool> isVisited(adjList.size(), false);

    dfs(0, adjList, ans, isVisited);

    cout << "DFS Traversal: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}