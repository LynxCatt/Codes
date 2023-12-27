#include <bits/stdc++.h>
using namespace std;

bool xp, xm, yp, ym;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        xp = xm = yp = ym = 0;
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            if (x > 0) xp = 1;
            else xm = 1;
            if (y > 0) yp = 1;
            else ym = 1;
        }
        cout << (xp+xm+yp+ym<=3?"YES\n":"NO\n");
    }
}