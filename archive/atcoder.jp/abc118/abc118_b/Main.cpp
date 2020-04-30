#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

//
int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        for(int i = 0; i < k; ++i){
            int a; cin >> a;
            ++mp[a];
        }
    }
    int ans = 0;
    for(auto itr : mp){
        if(itr.second == n){
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}

