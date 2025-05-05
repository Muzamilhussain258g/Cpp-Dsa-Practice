/*THIS IS THE REPRESENTATION OF DIRECTED UN WEIGHTED GRAPH*/

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

    vector<vector<bool>> AdjMatrix(vertex, vector<bool>(vertex, 0));

    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        AdjMatrix[u][v] = 1;
    }

    // for printing of adajacency matrix
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}