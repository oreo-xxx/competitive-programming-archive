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
    int n; cin >> n;

    vector<int> a(3 * n);
    for(int i = 0;i < 3 * n; ++i){
        cin >> a[i];
    }

    vector<ll> sum_l(2 * n + 1, 0);
    priority_queue<ll, vector<ll>, greater<ll> > que_l;
    for (int i = 0; i < n; ++i) {
        sum_l[i + 1] = sum_l[i] + a[i];
        que_l.push(a[i]);
    }
    for (int i = n; i < 2 * n; ++i) {
        ll tmp = que_l.top();
        if (a[i] > tmp) {
            sum_l[i + 1] = sum_l[i] - tmp + a[i];
            que_l.pop();
            que_l.push(a[i]);
        }
        else{
            sum_l[i + 1] = sum_l[i];
        }
    }

    vector<ll> sum_r(2 * n + 1, 0);
    priority_queue<ll> que_r;
    for (int i = 0; i < n; ++i) {
        sum_r[i + 1] = sum_r[i] + a[3 * n - 1 - i];
        que_r.push(a[3 * n - 1 - i]);
    }
    for (int i = n; i < 2 * n; ++i) {
        ll tmp = que_r.top();
        if (a[3 * n - 1 - i] < tmp) {
            sum_r[i + 1] = sum_r[i] - tmp + a[3 * n - 1 - i];
            que_r.pop();
            que_r.push(a[3 * n - 1 - i]);
        }
        else sum_r[i + 1] = sum_r[i];
    }

    ll ans = -1 * INF64;
    for (int i = n; i <= 2 * n; ++i) {
        ans = max(ans, sum_l[i] - sum_r[3 * n - i]);
    }
    cout << ans << endl;

    return 0;
}

