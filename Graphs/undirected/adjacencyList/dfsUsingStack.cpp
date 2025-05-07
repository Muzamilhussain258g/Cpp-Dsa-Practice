#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>> adj)
{
    vector<int> ans;
    vector<bool> visited(adj.size(), false);
    stack<int> s;

    s.push(0);
    visited[0] = true;

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        cout << node << "   ";

        for (int i = 0; i < adj[node].size(); i++)
        {
            int neightbor = adj[node][i];

            if (!visited[neightbor])
            {
                s.push(neightbor);
                visited[neightbor] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> adjacencyList = {
        {1, 2},
        {0, 5, 7},
        {0, 3, 4},
        {2},
        {2},
        {1, 6},
        {5, 8},
        {1, 8},
        {6, 7}};

    dfs(adjacencyList);
}