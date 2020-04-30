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
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    bool ok = false;
    for (ll i = 0; i < N; i++) {
        //i回は大きくなり,N - 1 - i回は小さくなる
        ll max = A + i * D - (N - 1 - i) * C;
        ll min = A + i * C - (N - 1 - i) * D;
        if (min <= B && B <= max) {
            ok = true;
            break;
        }
    }

    if (ok){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}
