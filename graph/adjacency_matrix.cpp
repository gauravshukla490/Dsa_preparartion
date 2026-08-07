#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> mat(n , vector<int>(n,0));

    cout << "Enter edges:\n";

    for (int i = 0; i < n; i++) {

        int u, v;
        cin >> u >> v;

        mat[u][v]=1;
        mat[v][u]=1;
    }

    cout << "\nAdjacency matrix\n\n";

    for (int i = 0; i < n; i++) {


        for (int j = 0 ; j < n ; j++) {

            cout << mat[i][j]<< " ";

        }

        cout << endl;
    }

    return 0;
}