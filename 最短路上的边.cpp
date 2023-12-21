#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9+7;

int n, m;

struct node{
    int to, nxt, w;
}g[5010];
int head[1510], cnt;

void add(int u, int v, int w) {
    g[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

bitset<5010> shortestPathEdges;

struct nod{
    int dis, u;
    bool operator<(const nod& b) const {
        return dis > b.dis;
    }
};
priority_queue<nod> q;
int dis[1510];
bitset<1510> vis;

void dijkstra(int st) {
    memset(dis, 0x3f, sizeof dis);
    vis.reset();
    q.push({0, st});
    dis[st] = 0;
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = g[i].nxt) {
            int v = g[i].to, w = g[i].w;
            if (dis[v] > dis[u]+w) {
                dis[v] = dis[u]+w;
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    freopen("std.in", "r", stdin);
    cin >> n >> m;
    for (int u, v, w, i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        // Check
        for (int u = 1; u <= n; u++) {
            for (int i = head[u]; i; i = g[i].nxt) {
                int v = g[i].to, w = g[i].w;
                if (abs(dis[u]-dis[v]) == w) shortestPathEdges[i] = 1;
            }
        }
    }

    return 0;
}