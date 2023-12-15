#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, q;
int dis[110][110];

int main() {
	// freopen("std.in", "r", stdin);
	memset(dis, 0x3f, sizeof dis);
	scanf("%d%d", &n, &m);
	for (int u, v, i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		dis[u][v] = dis[v][u] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	scanf("%d", &q);
	for (int u, v, i = 1; i <= q; i++) {
		scanf("%d%d", &u, &v);
		int ans = 2;
		for (int k = 1; k <= n; k++) {
			if (dis[u][k] + dis[k][v] == dis[u][v]) ans++;
		}
		printf("%d\n", ans);
	}
}