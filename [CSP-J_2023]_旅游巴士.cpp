#include <bits/stdc++.h>
using namespace std;

int n, m, k;

vector<pair<int, int>> g[10010];

struct node{
    int dis, u;
    bool operator < (const node& b) const {
        return dis > b.dis;
    }
};

priority_queue<node> q;
int dis[10010][101];
bool vis[10010][101];

void dijkstra() {
    memset(dis, 0x3f, sizeof dis);
    q.push({0, 1});
    dis[1][0] = 0;
    while (!q.empty()) {
        int u = q.top().u, d = q.top().dis;
        q.pop();
        if (vis[u][d%k]) continue;
        vis[u][d%k] = 1;
        for (pair<int, int> i : g[u]) {
            int v = i.first, a = i.second;
            int newTime = d;
            if (a > d) newTime = ((a-d+k-1)/k)*k+d;
            newTime++;
            if (dis[v][newTime%k] > newTime) {
                dis[v][newTime%k] = newTime;
                q.push({dis[v][newTime%k], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int u, v, a, i = 1; i <= m; i++) {
        cin >> u >> v >> a;
        g[u].push_back({v, a});
    }
    dijkstra();
    if (dis[n][0] == 0x3f3f3f3f) dis[n][0] = -1;
    cout << dis[n][0];
}