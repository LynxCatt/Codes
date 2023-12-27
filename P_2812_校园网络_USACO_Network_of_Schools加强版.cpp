#include <bits/stdc++.h>
using namespace std;

int n, m;
bitset<10001> g[10001];
int dfn[10001], low[10001], dfncnt;
int st[10001], top;
bool inst[10001];
int tag[10001], tagcnt;
bool ind[10001], oud[10001];

void tarjan(int u) {
	dfn[u] = low[u] = ++dfncnt;
	st[++top] = u;
	inst[u] = 1;
	for (int i = 1; i <= n; i++) {
		if (!g[u][i]) continue;
		if (!dfn[i]) {
			tarjan(i);
			low[u] = min(low[u], low[i]);
		} else if (inst[i]) low[u] = min(low[u], dfn[i]);
	}
	if (dfn[u] == low[u]) {
		tagcnt++;
		while (1) {
			int v = st[top--];
			inst[v] = 0;
			tag[v] = tagcnt;
			if (u == v) break;
		}
	}
}

struct node{
	int x, y;
}e[5000050];
int cnt;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		while (1) {
			int k;
			cin >> k;
			if (k == 0) break;
			g[i][k] = 1;
			e[++cnt] = {i, k};
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= cnt; i++) {
		if (tag[e[i].x] != tag[e[i].y]) {
			oud[tag[e[i].x]] = 1;
			ind[tag[e[i].y]] = 1;
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= tagcnt; i++) {
		if (!oud[i]) ans1++;
		if (!ind[i]) ans2++;
	}
	if (tagcnt == 1) cout << ans2 << endl << 0;
	else cout << ans2 << endl << max(ans1, ans2);
}