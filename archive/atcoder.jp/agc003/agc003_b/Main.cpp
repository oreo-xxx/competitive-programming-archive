#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 2;

void solve(){
    ll N; cin >> N;
    ll ans = 0;
    ll res = 0;
    for(int i = 0; i < N; ++i){
        ll a; cin >> a;
        ll tmp = min(a, res);
        ans += tmp;
        a -= tmp;

        ans += a/2;
        res = a%2;
    }
    cout << ans << endl;
    return;
}

int main() {
    #ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
    #else

    solve();

    #endif
    return 0;
}

