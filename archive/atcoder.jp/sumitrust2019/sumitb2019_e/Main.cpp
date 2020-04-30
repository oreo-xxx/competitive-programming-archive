#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    ll r=0, b=0, g=0;
    ll ans = 1LL;
    for (int i = 0; i < n; ++i) {
        if(a[i] == r) {
            ll tmp = 1;
            if(r == g){++tmp;}
            if(r == b){++tmp;}
            ++r;
            ans *= tmp;
        }
        else if(a[i] == g) {
            ll tmp = 1;
            if(g == b){++tmp;}
            ++g;
            ans *= tmp;
        }
        else if(a[i] == b) {
            ++b;
        }
        else{
          ans = 0;
        }
        ans %= MOD;
    }
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

