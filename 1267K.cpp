/*
https://codeforces.com/problemset/problem/1267/K
Idea: combinatorics, complement
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
typedef unsigned long long ull;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define V vector

int t;
ll k, res, tmp, L;
map<int, int> rema;
V<ll> fact(25, 1);

ll calc() {
    tmp = 1;
    int cnt = 0;
    cnt += rema[0] + rema[1];
    REP(i, 2, L) {
        tmp *= cnt;
        cnt--;
        cnt += rema[i];
    }
    REP(i, 0, L) {
        tmp /= fact[rema[i]];
    }
    return tmp;
}

int main() {
    cin >> t;
    tmp = 1;
    REP(i, 2, 20) {
        tmp *= i;
        fact[i] = tmp;
    }
    REP(i, 0, t) {
        cin >> k;
        rema.clear();
        int curr = 2, r = 0;
        while (k != 0) {
            r = k % curr;
            rema[r] += 1;
            k /= curr;
            curr++;
        }
        L = curr-1;
        res = calc();
        res--;
        if(rema[0] > 0) {
            rema[0]--;
            res -= calc();
        }
        cout << res << '\n';
    }

    return 0;
}
