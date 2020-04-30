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
    int ans = max(10 * a + b + c, a + 10 * b + c);
    ans = max(ans, a + b + 10 * c);
    cout << ans << endl;
    return 0;
}

