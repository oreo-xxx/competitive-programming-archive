#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    vector<double> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }

    double tmp = 0;
    for(int i = 0; i < N; ++i){
        tmp += (1.0 / A[i]);
    }

    double ans = 1.0 / tmp;

    cout << ans << endl;

    return 0;
}
