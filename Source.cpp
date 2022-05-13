#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct dinh {
    int parent = -1;
    int color = 0;
    int d = INT_MAX;
};

vector <dinh> BFS(vector <vector<int>> g, int s0) {
    queue <int> q;
    vector <dinh> dothi(g.size());

    q.push(s0);
    dothi[s0].color = 1;
    dothi[s0].d = 0;

    while (!q.empty()) {
        int s = q.front();
        for (auto& si : g[s]) {
            if (dothi[si].color == 0) {
                q.push(si);
                dothi[si].color = 1;
                dothi[si].parent = s;
                dothi[si].d = dothi[s].d + 1;
            }
        }
        dothi[s].color = 2;
        q.pop();
    }

    return dothi;
}

int main() {
    int n;
    cin >> n;
    vector <vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }

    vector <dinh> res = BFS(adj, 0);

    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (auto& s : res) {
        cout << s.d << " ";
    }
    cout << endl;
    for (auto& s : res) {
        cout << s.parent << " ";
    }
    cout << endl;

    return 0;
}