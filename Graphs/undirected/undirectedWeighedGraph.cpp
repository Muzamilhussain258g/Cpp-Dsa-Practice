/*THIS IS THE REPRESENTATION OF UNDIRECTED WEIGHED GRAPH*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int vertex, edges;
    cout << "Enter the number of vertex ";
    cin >> vertex;

    cout << "Enter the number of edges ";
    cin >> edges;

    vector<vector<int>> AdjMatrix(vertex, vector<int>(vertex, 0));

    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;
        AdjMatrix[u][v] = weight;
        AdjMatrix[v][u] = weight;
    }

    // for printing the adjacency matrix
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}