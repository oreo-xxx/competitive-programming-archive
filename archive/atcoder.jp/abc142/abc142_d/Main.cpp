#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

set<ll> prime_factorize(long long n) {
    set<ll> se;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        while (n % p == 0) { n /= p; }
        se.insert(p);
    }
    if (n != 1) se.insert(n);
    return se;
}

void solve(){
    ll A, B;
    cin >> A >> B;
    set<ll> seA = prime_factorize(A);
    set<ll> seB = prime_factorize(B);

    seA.insert(1);
    seB.insert(1);

    ll ans = 0;
    for(auto it : seA){
        auto it2 = seB.find(it);
        if (it2 != seB.end()) {
            ++ans;
        }
    }
    cout << ans << '\n';

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

