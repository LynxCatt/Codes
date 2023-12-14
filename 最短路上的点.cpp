#include <bits/stdc++.h>
#define pack {v, head[u]}
using namespace std;
using ll = long long;

int n, m;
struct node{
	int to, nxt;
}g[1000010];
int head[2000010], cnt;

void add(int u, int v) {
	g[++cnt] = pack;
	head[u] = cnt;
}

int dis[1000010];
int tot[1000010];

void bfs() {
	memset(dis, 0x3f, sizeof dis);
	queue<int> q;
	q.push(1);
	dis[1] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = g[i].nxt) {
			int v = g[i].to;
			if (dis[v] == dis[u]+1) {
				tot[v] = (tot[v]+tot[u])%100003;
			} else if (dis[v] == 0x3f3f3f3f) {
				tot[v] = tot[u];
				dis[v] = dis[u]+1;
				q.push(v);
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (u == v) continue;
		add(u, v), add(v, u);
	}
	tot[1] = 1;
	bfs();
	for (int i = 1; i <= n; i++) {
		printf("%d\n", tot[i]);
	}
}