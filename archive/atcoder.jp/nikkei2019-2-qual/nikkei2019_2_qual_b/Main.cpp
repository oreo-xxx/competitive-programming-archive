#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 998244353;

const int CASES = 3;

void solve() {
    ll N; cin >> N;
    vector<ll> D(N);
    vector<ll> vec(N);
    for(int i = 0; i < N; ++i){
        cin >> D[i];
        ++vec[D[i]];
    }
    if(D[0] != 0){
        cout << 0 << endl;
        return;
    }

    ll ans = 1;
    if(vec[0] != 1){
        cout << 0 << endl;
        return;
    }
    for(ll i = 1; i < N; ++i){
        for(int j = 0; j < vec[i]; ++j){
            ans *= vec[i-1];
            ans %= MOD;
        }
        ans %= MOD;
    }

    cout << ans << endl;

    return ;
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

