#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve() {
    ll N;
    cin >> N;
    ll root = sqrt(N);
    ll pair1 = 0;
    ll pair2 = 0;
    for (ll i = root; root > 0; --i) {
        if (N % i == 0) {
            pair1 = i;
            pair2 = N / i;
            break;
        }
    }
    ll ans = pair1 + pair2 - 2;
    cout << ans << endl;
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

