#include <bits/stdc++.h>
#define pack {head[u], v, lim, w}
using namespace std;

inline char gtc() {
	static char buf[100005], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100005, stdin), p1 == p2) ? EOF : *p1 ++ ;
}

template<typename Type>
inline void read(Type &x) {
	char c; bool t;
	x = t = 0, c = gtc();
	while (c < '0' || c > '9') t |= (c == '-'), c = gtc();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = gtc();
	x = t ? -x : x;
}

const int inf = 0x3fffffff;

int n;

struct edg{
	int nxt, to, lim, w;
}g[5000];
int head[120], cnt;

void add(int u, int v, int lim, int w) {
	g[++cnt] = pack;
	head[u] = cnt;
}

struct node{
	int x, y, z;
}pt[120];

inline int Distance(int i, int j) {
	return ceil(sqrt(
				(pt[i].x-pt[j].x)*(pt[i].x-pt[j].x)+
				(pt[i].y-pt[j].y)*(pt[i].y-pt[j].y)+
				(pt[i].z-pt[j].z)*(pt[i].z-pt[j].z)));
}

int dis[120];
pair<int, int> q[5000];
int front;
/*         u,   dis      */
/* <- front......back <- */

void spfa() {
    q[++front] = make_pair(0, 0);
	dis[0] = 0;
	while (front) {
		int u = q[front].first, d = q[front].second;
		front--;
		for (int i = head[u]; i; i = g[i].nxt) {
			int v = g[i].to;
			int goTime = max(d, g[i].lim)+g[i].w;
			if (dis[v] > goTime) {
				dis[v] = goTime;
                q[++front] = make_pair(v, dis[v]);
				if (q[front].second > q[1].second) swap(q[1], q[front]);
			}
		}
	}
	return ;
}

int main() {
	// freopen("std.in", "r", stdin);
	int T;
	read(T);
	while (T--) {
		for (int i = 0; i <= 2*n+1; i++) {
			dis[i] = inf, head[i] = 0;
		}
		cnt = 0;
		read(n);
		for (int t, d, i = 1; i <= n; i++) {
			read(pt[i*2].x), read(pt[i*2].y), read(pt[i*2].z);
			read(pt[i*2+1].x), read(pt[i*2+1].y), read(pt[i*2+1].z);
			read(t), read(d);
			add(i*2, i*2+1, t, d);
			add(i*2, i*2+1, -inf, Distance(i*2, i*2+1));
			add(i*2+1, i*2, -inf, Distance(i*2, i*2+1));
			for (int j = 1; j < i; j++) {
				add(i*2, j*2+1, -inf, Distance(i*2, j*2+1));
				add(j*2+1, i*2, -inf, Distance(i*2, j*2+1));
				add(i*2+1, j*2, -inf, Distance(i*2+1, j*2));
				add(j*2, i*2+1, -inf, Distance(i*2+1, j*2));
			}
		}
		read(pt[0].x), read(pt[0].y), read(pt[0].z);
		read(pt[1].x), read(pt[1].y), read(pt[1].z);
		add(0, 1, -inf, Distance(0, 1));
		for (int i = 1; i <= n; i++) {
			add(0, i*2, -inf, Distance(0, i*2));
			add(i*2+1, 1, -inf, Distance(1, i*2+1));
		}
		spfa();
		printf("%d\n", dis[1]);
	}
}
