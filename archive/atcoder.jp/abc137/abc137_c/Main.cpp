#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; ++i){
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }
    sort(s.begin(), s.end());

    ll ans = 0;
    for (ll i = 0; i < N;){
        ll j = i + 1;
        for(; j < N; ++j){
            if(s[i] != s[j]) break;
        }
        ans += (j - i) * (j - i - 1) / 2LL;
        i = j;
    }
    cout << ans << endl;

    return 0;
}

