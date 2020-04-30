#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;
vector<int> a, b;
int main() {
int N;
    cin >> N;
    a.resize(N); for (int i = 0; i < N; ++i) cin >> a[i];
    b.resize(N); for (int i = 0; i < N; ++i) cin >> b[i];
    int res = 0;
    for (int digit = 29; digit >= 0; --digit) {
        int bekihigh = 1<<(digit+1);
        int bekilow = 1<<digit;
        for (int i = 0; i < N; ++i) a[i] %= bekihigh, b[i] %= bekihigh;
        sort(b.begin(), b.end());
        long long num = 0;
        for (int i = 0; i < N; ++i) {
            int add = 0;
            if (bekilow - a[i] >= 0) {
                add += lower_bound(b.begin(), b.end(), bekihigh-a[i])
                        - lower_bound(b.begin(), b.end(), bekilow-a[i]);
            }
            else {
                add += lower_bound(b.begin(), b.end(), bekihigh-a[i]) - b.begin();
                add += lower_bound(b.begin(), b.end(), bekihigh)
                        - lower_bound(b.begin(), b.end(), bekihigh + bekilow - a[i]);
            }
            num += add;
        }
        if (num & 1) res += bekilow;
    }
    cout << res << endl;
}
