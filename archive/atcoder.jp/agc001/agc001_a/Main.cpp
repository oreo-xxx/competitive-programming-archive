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
    vector<ll> L(N * 2);

    for (int i = 0; i < N * 2; ++i){
        cin >> L[i];
    }

    sort(L.begin(), L.end());
    ll ans = 0;

    for (int i = 0; i < N * 2; i += 2){
        ans += L[i];
    }

    cout << ans << endl;
    return 0;
}
