#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll C, D;
    cin >> C >> D;
    ll res = 0;
    ll left = 140, right = 170;
    for (int i = 0; i < 60; ++i) {
        ll tmp = min(D, right) - max(C, left);
        if (tmp > 0) res += tmp;
        left *= 2, right *= 2;
        if (left > 10e15) break;
    }
    cout << res << endl;
    return 0;
}

