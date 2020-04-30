#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

struct FloatingMedian{
    priority_queue<ll> zen;
    priority_queue<ll, vector<ll>, greater<ll> > kou;
    ll zensum = 0;
    ll kousum = 0;

    ll const med(){
        return zen.top();
    }

    void push(ll n){
        if (zen.size() > kou.size()) {
            // kou に
            int t = zen.top();
            if (n >= t) {
                kou.push(n); kousum += n;
            }
            else {
                zen.pop(); zensum -= t;
                zen.push(n); zensum += n;
                kou.push(t); kousum += t;
            }
        }
        else {
            // zen に
            if (zen.empty()){
                zen.push(n);
                zensum += n;
            }
            else {
                int t = kou.top();
                if (n <= t) {
                    zen.push(n); zensum += n;
                }
                else {
                    kou.pop(); kousum -= t;
                    kou.push(n); kousum += n;
                    zen.push(t); zensum += t;
                }
            }
        }
    }
};

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int Q; cin >> Q;

    long long sum = 0;
    FloatingMedian floatingmedian;

    for (int i = 0; i < Q; ++i) {
        ll type; cin >> type;
        if (type == 1) {
            ll a, b; cin >> a >> b;
            floatingmedian.push(a);
            sum += b;
        }
        else {
            ll x = floatingmedian.med();
            ll tmp1 = x * floatingmedian.zen.size() - floatingmedian.zensum;
            ll tmp2 = x * floatingmedian.kou.size() - floatingmedian.kousum;
            ll res = tmp1 - tmp2 + sum;
            cout << x << " " << res << endl;
        }
    }
    return 0;
}
