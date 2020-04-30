#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    vector<long long> left(N), right(N);
    for (int i = 0; i < N; ++i) cin >> left[i] >> right[i];
    sort(left.begin(), left.end(), greater<long long>());
    sort(right.begin(), right.end());
    long long res = 0, tmp = 0;

    // left スタート
    tmp = 0;
    for (int i = 0; i < N; ++i) {
        tmp += left[i]; res = max(res, tmp);
        tmp -= right[i]; res = max(res, tmp);
    }

    // right スタート
    tmp = 0;
    for (int i = 0; i < N; ++i) {
        tmp -= right[i]; res = max(res, tmp);
        tmp += left[i]; res = max(res, tmp);
    }

    cout << res * 2 << endl;
    return 0;
}
