/*
Link: https://codeforces.com/problemset/problem/1265/E
Idea: prob, modular arithmetic
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

int n, a;
V<int> probs;
ll nume, deno, MOD = 998244353;

ll inv(ll x) {
    ll p = MOD - 2, res = 1;
    while(p != 0) {
        if(p % 2 == 0) {
            x = x * x % MOD;
            p >>= 1;
        } else {
            res = x * res % MOD;
            x = x * x % MOD;
            p >>= 1;
        }
    }
    return res;
}

int main() {
    cin >> n;
    REP(i, 0, n) {cin >> a; probs.PB(a);}

    deno = 1; nume = 0;
    REP(i, 0, n) {
        nume *= 100;
        nume += deno;
        nume %= MOD;
        deno *= probs[i];
        deno %= MOD;
    }
    nume *= 100;
    nume %= MOD;
    ll res = nume * inv(deno) % MOD;
    cout << res << '\n';
    return 0;
}
