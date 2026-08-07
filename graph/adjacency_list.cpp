#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);

    cout << "Enter edges:\n";

    for (int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);   // Remove for directed graph
    }

    cout << "\nAdjacency List\n\n";

    for (int i = 0; i < n; i++) {

        cout << i << " -> ";

        for (int neighbour : adj[i]) {

            cout << neighbour << " ";

        }

        cout << endl;
    }

    return 0;
}