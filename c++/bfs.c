#include <iostream> [cite: 640]
#include <vector> [cite: 641]
#include <queue> [cite: 642]
using namespace std; [cite: 643]

int main() { [cite: 644]
    int n, e; [cite: 645]
    cout << "Enter number of nodes: "; [cite: 646]
    cin >> n; [cite: 647]
    cout << "Enter number of edges: "; [cite: 648]
    cin >> e; [cite: 649]

    vector<vector<int>> adj (n); [cite: 650]
    cout << "Enter edges (u v):\n"; [cite: 651]
    for (int i=0; i<e; i++) { [cite: 652]
        int u, v; [cite: 653]
        cin >> u >> v; [cite: 654]
        adj[u].push_back(v); [cite: 655]
        adj[v].push_back(u); // undirected [cite: 656]
    } [cite: 657]

    int start; [cite: 658]
    cout << "Enter starting node: "; [cite: 659]
    cin >> start; [cite: 660]

    vector<bool> visited(n, false); [cite: 661]
    queue<int> q; [cite: 662]

    visited[start] = true; [cite: 664]
    q.push(start); [cite: 665]

    cout << "\nBFS Traversal: "; [cite: 666]
    while (!q.empty()) { [cite: 667]
        int node = q.front(); [cite: 668]
        q.pop(); [cite: 669]
        cout << node << " "; [cite: 670]

        for (int x : adj[node]) { [cite: 671]
            if (!visited[x]) { [cite: 672]
                visited[x] = true; [cite: 686]
                q.push(x); [cite: 687]
            } [cite: 682]
        } [cite: 683]
    } [cite: 663, 684]

    return 0; [cite: 685]
}