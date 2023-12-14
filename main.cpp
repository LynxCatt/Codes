#include <bits/stdc++.h>
using namespace std;

int n;
int val[101];
bool sta[101][101];
vector<int> g[101];

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
    q.push({val[s], s});
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v : g[u]) {
            if (u == s && v == t) continue;
            if (u == t && v == s) continue;
            
        }
    }
    return dis[t] != 0x3f3f3f3f;
}

int main() {
    freopen("std.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k, n1s, n2s;
        cin >> k >> val[k] >> n1s >> n2s;
        for (int j = 1; j <= n1s; j++) {
            int x;
            cin >> x;
            g[x].push_back(k), g[k].push_back(x);
            sta[i][x] = 0;
        }
        for (int j = 1; j <= n2s; j++) {
            int x;
            cin >> x;
            g[x].push_back(k), g[k].push_back(x);
            sta[i][x] = 1;
        }
    }
}