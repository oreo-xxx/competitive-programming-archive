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
    int n; cin >> n;

    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }
    double ans = 0;
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            double tmp = sqrt( (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) );
            ans = max(ans, tmp);
        }
    }
    cout << setprecision(10) << ans << endl;
    return 0;
}

