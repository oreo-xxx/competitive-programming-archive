#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    int ans = 0;
    for (int i = 1; i < N; ++i) {
        if (a[i] == a[i-1]) {
            a[i] = -1;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
