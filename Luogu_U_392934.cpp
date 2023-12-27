#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Accept";
    } else if (n == 2) {
        cout << "Wrong Answer";
    } else if (n == 3) {
        exit(1);
        cout << "Runtime Error";
    } else if (n == 4) {
        cout << "Unknown Error";
    }
}