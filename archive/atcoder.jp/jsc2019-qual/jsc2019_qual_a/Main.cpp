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
    int M, D; cin >> M >> D;
    if (D < 20){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    for(int i = 0; i <= M; ++i){
        for(int j = 20; j <= D; ++j){
            if(j % 10 < 2){
                continue;
            }
            if(i == (j % 10) * (j / 10)){
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
