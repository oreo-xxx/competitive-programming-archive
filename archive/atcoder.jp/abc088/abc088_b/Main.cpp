#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

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

    int n; cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), greater<int>());
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            ans += vec[i];
        } else {
            ans -= vec[i];
        }
    }
    cout << ans << endl;
    return 0;
}
