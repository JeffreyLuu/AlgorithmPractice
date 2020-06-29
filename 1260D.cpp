/*
Problem link: https://codeforces.com/problemset/problem/1260/D
Idea: binary search, greedy
Further improvement: Use segment union for the check part
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

int m, n, k, t, a, b, c, l, r, mid;
V<int> A;
V<tuple<int, int, int> > traps;

bool check(int val) {
    // cout << "val " << val << endl;
    int time = 0;
    int le = 0, ri = 0, further = -1; // [le..ri)
    while(ri < k) {
        // cout << le << ' ' << ri << ' ' << further << ' ' << time << endl;
        if(get<2>(traps[ri]) <= val) {
            ri++;
            if(further == -1) le++;
            continue;
        }
        a = get<0>(traps[ri]); b = get<1>(traps[ri]);

        if(a > further) {
            if(further >= 0) time += (further - get<0>(traps[le])+1) * 2;
            if(time + n+1 > t) return false;
            le = ri;
            further = b;
        }
        else if (b < further) {
            ri++;
        } else {
            further = b; ri++;
        }
    }
    if(get<0>(traps[le]) <= further) time += 2*(further - get<0>(traps[le]) + 1);
    // cout << time + n + 1 << endl;
    return time + n + 1 <= t;
}

int main() {
    cin >> m >> n >> k >> t;
    REP(i, 0, m) {cin >> c; A.PB(c);}
    sort(A.begin(), A.end());
    REP(i, 0, k) {
        cin >> a >> b >> c;
        traps.PB(make_tuple(a, b, c));
    }
    sort(traps.begin(), traps.end());
    l = 0; r = m;
    while(l< r-1) {
        mid = l+(r-l)/2;
        int val = A[mid];
        if(check(val)) r = mid;
        else l = mid;
    }
    if(r == 1) {
        int val = A[0];
        if(check(val)) cout << m << endl;
        else cout << m-1 << endl;
    }
    else cout << m - r << endl;
    return 0;
}
