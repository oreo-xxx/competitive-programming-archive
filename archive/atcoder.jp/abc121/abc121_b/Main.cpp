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
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        vector<int> a(m);
        for(int i = 0; i < m; ++i){
            cin >> a[i];
        }
        ll tmp = c;
        for(int i = 0; i < m; ++i){
            tmp += a[i] * b[i];
        }
        if(tmp > 0){
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}

