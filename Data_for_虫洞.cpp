#include <bits/stdc++.h>
using namespace std;

int T = 1, N = 50;

mt19937 seed(random_device{}());
uniform_int_distribution<int> pos(-10000, 10000);
uniform_int_distribution<int> tdmaker(-1000000, 1000000);

set<tuple<int, int, int>> st;

void rand_pos() {
	int x, y, z;
	while (1) {
		x = pos(seed), y = pos(seed), z = pos(seed);
		if (st.count({x, y, z})) continue;
		st.insert({x, y, z});
		break;
	}
	cout << x << " " << y << " " << z << " ";
}

int main() {
	// freopen("std.in", "w", stdout);
	cout << T << endl;
	while (T--) {
		st.clear();
		cout << N << endl;
		for (int i = 1; i <= N; i++) {
			rand_pos(), rand_pos();
			cout << tdmaker(seed) << " " << tdmaker(seed) << endl;
		}
		rand_pos(), rand_pos();
		cout << endl;
	}
}