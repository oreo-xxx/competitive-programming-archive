#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll N, K;cin >> N >> K;
    vector<ll> a(N);
    for (ll i = 0; i < N; ++i){
        cin >> a[i];
    }

    ll ans = 0;

    ll right = 0;
    ll sum = 0;
    for (ll left = 0; left < N; ++left) {
        while (right < N && sum < K) {
            sum += a[right];
            ++right;
        }
        if (sum < K) break;

        ans += N - right + 1;

        if (right == left){
            ++right;
        }
        else{
            sum -= a[left];
        }
    }

    cout << ans << endl;
    return 0;
}
