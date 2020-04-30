#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 4;

void solve(){
    ll Q, H, S, D, N; cin >> Q>> H >> S >> D >> N;
    Q *= 4;
    H *= 2;
    ll tmp = min(Q, min(H, S));
    ll ans1 = N * tmp;
    ll ans2 = (N/2) * D + (N%2)*tmp;
    cout << min(ans1, ans2) << endl;
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

