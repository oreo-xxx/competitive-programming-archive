#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//
uint64_t dp[101010][13]; // mod13

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll N, A, B; cin >> N >> A >> B;
    if (A > B){
        cout << 0 << endl;
    }
    else if(N == 1){
        if(A == B){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    else{
        ll max_ = A + (N - 1) * B;
        ll min_ = (N - 1) * A + B;
        ll ans = max_ - min_ + 1;
        cout << ans << endl;
    }
    return 0;
}
