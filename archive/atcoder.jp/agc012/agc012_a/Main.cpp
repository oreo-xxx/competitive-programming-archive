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
    vector<ll> A(N * 3);

    for (int i = 0; i < N*3; ++i){
        cin >> A[i];
    }

    sort(A.begin(), A.end(), greater<ll>());
    ll ans = 0;

    for (int i = 0; i < N; ++i){
        ans += A[2 * i + 1];
    }

    cout << ans << endl;
    return 0;
}
