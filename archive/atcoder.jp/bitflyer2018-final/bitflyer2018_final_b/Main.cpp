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

long long N, Q;
vector<long long> X;
vector<long long> sum;
long long c, d;

long long solve() {
    int left =  upper_bound(X.begin(), X.end(), c-d) - X.begin();
    int mid =   upper_bound(X.begin(), X.end(), c)   - X.begin();
    int right = upper_bound(X.begin(), X.end(), c+d) - X.begin();

    long long res14 = (left + (N - right)) * d;
    long long res2 = c * (mid-left) - (sum[mid] - sum[left]);
    long long res3 = (sum[right] - sum[mid]) - c*(right-mid);
    return res14 + res2 + res3;
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N >> Q;
    X.resize(N);
    for (int i = 0; i < N; ++i) cin >> X[i];

    sum.resize(N+1); sum[0] = 0;
    for (int i = 0; i < N; ++i){
        sum[i+1] = sum[i] + X[i];
    }

    for (int q = 0; q < Q; ++q) {
        cin >> c >> d;
        cout << solve() << endl;
    }
    return 0;
}
