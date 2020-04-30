#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif


    int n; cin >> n;
    vector<int> t(n);
    for(int i = 0; i < n; ++i){
        cin >> t[i];
    }

    ll ans = INF;
    for(ll bit = 0; bit < (1 << n); ++bit){
        ll left = 0;
        ll right = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) {
                left += t[i];
            }else{
                right += t[i];
            }
        }
        ans = min(ans, max(left, right));
    }
    cout << ans << endl;
    return 0;
}

