#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, uint>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve(){

    string s; cin >> s;
    ll n = s.length();

    vector<ll> a(26);
    for (char c : s) ++a[c - 'a'];

    ll ans = n * (n-1) / 2;

    for (ll l : a) {
        ans -= l * (l-1) / 2;
    }
    cout << ans + 1 << '\n';
    
    /*
    ll ans_ = 1;
    vector<ll> cnt(26);
    for(int i = n - 1; i >= 0; --i) {
        int si = s[i] - 'a';
        for(int j = 0; j < 26; ++j){
            if (j != si) ans_ += cnt[j];
        }
        ++cnt[si];
    }
    cout << ans_ << '\n';
     */
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

