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
    map<string, int> mp;

    int n; cin >> n;
    for(int i = 0;i < n; ++i){
        string s; cin >> s;
        ++mp[s];
    }

    int m; cin >> m;
    for(int i = 0;i < m; ++i){
        string s; cin >> s;
        --mp[s];
    }

    int ans = 0;
    for(auto itr : mp){
        ans = max(ans, itr.second);
    }
    cout << ans << endl;

    return 0;
}

