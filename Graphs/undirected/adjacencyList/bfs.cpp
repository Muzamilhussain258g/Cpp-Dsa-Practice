

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS traversal on an undirected graph
int bfs(const vector<vector<int>> &adjList)
{
    vector<int> ans; // for storing the ans

    vector<bool> visited(adjList.size(), 0);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int i = 0; i < adjList[node].size(); i++)
        {
            if (!visited[adjList[node][i]])
            {
                q.push(adjList[node][i]);
                visited[adjList[node][i]] = true;
            }
        }
    }
    cout << endl;
};

int main()
{
    // vector<int> vertexValues = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // for vertex

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

    bfs(adjList);
}