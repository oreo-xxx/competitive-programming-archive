#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;


const ll INF64 = 1LL << 60;
const int INF32 = 1 << 30;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int p, q, r;cin >> p >> q >> r;

    int tmp1 = p+q;
    int tmp2 = p+r;
    int tmp3 = r+q;

    int ans = min(tmp1, tmp2);
    ans = min(ans, tmp3);
    cout << ans << endl;
    return 0;
}

