#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

//
int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int a, b, c;
    cin >> a >> b >> c;
    int ans = min( INF32, abs(b-a) + abs(c-b));
    ans = min(ans, abs(c-a) + abs(b-c));

    ans = min(ans, abs(a-b) + abs(c-a));
    ans = min(ans, abs(c-b) + abs(a-c));

    ans = min(ans, abs(b-c) + abs(a-b));
    ans = min(ans, abs(a-c) + abs(b-a));
    cout << ans << endl;
    return 0;
}

