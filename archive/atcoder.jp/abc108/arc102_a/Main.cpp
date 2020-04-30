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
    int n, k; cin >> n >> k;
    map<int, ll> num;
    // num[x] = kで割ってxあまる数が1以上N以下に何個あるか
    for (int i = 1; i <= n; ++i) num[i%k]++;

    long long res = 0;
    for (int a = 0; a < k; ++a) {
        int b = (k-a) % k;
        int c = (k-a) % k;
        if ((b+c) % k != 0) continue;
        res += num[a] * num[b] * num[c];
    }
    cout << res << endl;
    return 0;
}

