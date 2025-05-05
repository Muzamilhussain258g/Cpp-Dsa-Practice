// implement of directed weighted graph ussing adjacency list;

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

    // Vector of vertices (0 to vertex-1)
    vector<int> vertices(vertex);
    for (int i = 0; i < vertex; i++)
        vertices[i] = i;

    // Adjacency list: each vertex stores (destination, weight)
    vector<vector<pair<int, int>>> adjacencyList(vertex);

    int u, v, weight;
    cout << "Enter directed edges in the format (u v weight):\n";
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;
        adjacencyList[u].push_back({v, weight}); // directed edge u → v
    }

    // Print the adjacency list
    cout << "\nDirected Weighted Graph - Adjacency List:\n";
    for (int i = 0; i < vertex; i++)
    {
        cout << vertices[i] << " -> ";
        for (const auto& edge : adjacencyList[i])
        {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
