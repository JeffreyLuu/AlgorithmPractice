/*
Problem link: https://codeforces.com/problemset/problem/1260/C
Idea: number theory, gcd
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
// #include <unordered_set>
#include <map>
// #include <unordered_map>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <cstring>
#include <stack>

using namespace std;
typedef long long ll;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define V vector

int r, b, k, T, g, mini, maxi;

int gcd(int m, int n) {
    if(m == 0) return n;
    if(m>n) return gcd(n, m);
    return gcd(n%m, m);
}

int main() {
    cin >> T;
    REP(i, 0, T) {
        cin >> r >> b >> k;
        g = gcd(r, b);
        mini = min(r, b);
        maxi = max(r, b);

        if (k-1 < (float)(maxi-g)/mini) {
            // this is a bit ugly, but this is needed as float point number can be inaccurate
            if((k-1) * mini < maxi - g) cout << "REBEL\n";
            else cout << "OBEY\n";
        }
        else cout << "OBEY\n";
    }
    return 0;
}
