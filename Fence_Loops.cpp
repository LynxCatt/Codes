#include <bits/stdc++.h>
using namespace std;

int n;
int g[101][101];

struct node{
    int dis, u;
    bool operator<(const node &b) const {
        return dis > b.dis;
    }
};
priority_queue<node> q;
int dis[101];
bool vis[101];
int s, t;

bool dijkstra() {
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    q.push({0, s});
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.top().u; 
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v = 1; v <= n; v++) {
            if (!g[u][v]) continue;
            if (u == s && v == t) continue;
            if (u == t && v == s) continue;
            int w = g[u][v];
            if (dis[v] > dis[u]+w) {
                dis[v] = dis[u]+w;
                q.push({dis[v], v});
            }
        }
    }
    return dis[t] != 0x3f3f3f3f;
}

struct edge{
    int u, v;
}edg[8080];
int cnt;

int main() {
    freopen("std.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k, v, n1s, n2s, x;
        cin >> k >> v >> n1s >> n2s;
        for (int j = 1; j <= n1s+n2s; j++) {
            cin >> x;
            if (g[x][k] && g[k][x]) {
                edg[++cnt] = {k, x};
            }
            g[x][k] += v, g[k][x] += v;
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= cnt; i++) {
        s = edg[i].u, t = edg[i].v;
        if (dijkstra()) {
            ans = min(ans, (dis[t]+g[s][t])/2);
        }
    }
    cout << ans;
}