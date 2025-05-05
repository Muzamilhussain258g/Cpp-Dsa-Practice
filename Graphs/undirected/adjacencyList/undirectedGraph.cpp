// implement of undirected graph using adjacency list

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int vertex, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertex;

    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<vector<int>> AdjacencyList(vertex);

    int u, v;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        AdjacencyList[u].push_back(v);
        AdjacencyList[v].push_back(u); // since undirected
    }

    // print adjacency list
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < AdjacencyList[i].size(); j++)
        {
            cout << AdjacencyList[i][j] << " ";
                }
        cout << endl;
    }

    return 0;
}
