#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    const int MAX = 101010;
    vector<long double> p(MAX);
    for (int i = 1; i < MAX; ++i){
        p[i] = p[i-1] + log10(i);
    }

    int N, M; cin >> N >> M;
    long double prob = -p[N];
    for (int i = 0; i < M; ++i) {
        int r; cin >> r;
        prob += p[r];
    }
    prob += log10(M) * N;
    cout << ceil(prob) << endl;
}
