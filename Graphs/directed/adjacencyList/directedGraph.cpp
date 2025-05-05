// implement of directed graph using adjacency list

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

    // Vector for vertex labels (0 to vertex-1)
    vector<int> vertices(vertex);
    for (int i = 0; i < vertex; i++)
        vertices[i] = i;

    // Adjacency list vector (edges from each vertex)
    vector<vector<int>> adjacencyList(vertex);

    int u, v;
    cout << "Enter directed edges (u v):\n";
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adjacencyList[u].push_back(v); // directed edge u → v
    }

    // Print adjacency list
    cout << "\nDirected Graph - Adjacency List:\n";
    for (int i = 0; i < vertex; i++)
    {
        cout << vertices[i] << " -> ";
        for (int j = 0; j < adjacencyList[i].size(); j++)
        {
            cout << adjacencyList[i][j];
            if (j != adjacencyList[i].size() - 1)
                cout << ", ";
        }
        cout << endl;
    }

    return 0;
}
