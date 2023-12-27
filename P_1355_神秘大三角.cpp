#include <iostream>
using namespace std;

struct point{
	int x, y;
	point() {}
	point(int a, int b):x(a), y(y){}
	point operator-(point b) {
		return point(x-b.x, y-b.y);
	}
}v[3], p;

double cross(point a, point b) {
	return a.x*b.y - a.y*b.x;
}

int main() {
	for (int i = 0; i < 3; i++) scanf("(%d,%d)\n", &v[i].x, &v[i].y);
	scanf("(%d,%d)\n", &p.x, &p.y);
	int l = 0, r = 0;
	for (int i = 0; i < 3; i++) {
		int res = cross(p-v[i], p-v[(i+1)%3]);
		if (res > 0) r++;
		if (res < 0) l++;
	}
	if (l == 3 || r == 3) {
		printf("1");
	} else if (l > 0 && r > 0) {
		printf("2");
	} else if (l + r == 1) {
		printf("4");
	} else {
		printf("3");
	}
}	