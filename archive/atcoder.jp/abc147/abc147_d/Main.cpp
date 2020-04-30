#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

void solve() {
    ll N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    long long res = 0;
    for (ll d = 60; d >= 0; --d) {
        vector<ll> sum(N+1);
        long long mask = 1LL<<d;
        for (int i = 0; i < N; ++i){
            sum[i+1] = sum[i];
            if (A[i] & mask){
                sum[i+1] += 1;
            }
        }

        for (int i = 0; i < N-1; ++i){
            if((A[i] & mask) != 0 ){

                ll tmp = ((mask%MOD) * ((N-i-1) - (sum[N] - sum[i+1]))) % MOD;
                res += tmp;
                res %= MOD;
            }
            else{
                ll tmp = ((mask%MOD) * (sum[N] - sum[i+1])) % MOD;
                res += tmp;
                res %= MOD;
            }
        }
    }
    cout << res%MOD << endl;
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
#else

    solve();

#endif
    return 0;
}
