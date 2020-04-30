#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 30;
const ll MOD = 1000000007;

ll dp[101010];

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    ll ans = 0;
    for(int i = 0; i <= k; ++i){
        int len = min(i, n);
        for(int l_width = 0; l_width <= len; ++l_width){
            priority_queue<ll, vector<ll>, greater<ll> > temoto;
            vector<ll> left, right;
            ll total = 0;
            for(int j = 0; j < l_width; ++j){
                temoto.push(v[j]);
                total += v[j];
                left.push_back(v[j]);
            }

            for(int j = 0; j < len - l_width; ++j){
                temoto.push(v[n - 1 - j]);
                total += v[n - 1 - j];
                right.push_back(v[n - 1 - j]);
            }

            for(int j = 0; j < k - len; ++j){
                if(temoto.empty()){
                    break;
                }
                ll top = temoto.top();
                if(top < 0){
                    temoto.pop();
                    total -= top;
                }
            }
            ans = max(ans, total);
        }
    }
    cout << ans << endl;
    return 0;
}

