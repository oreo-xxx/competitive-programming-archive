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
    int N, x; cin >> N >> x;
    vector<int> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (x >= a[i]) {
            ++ans;
            x -= a[i];
        }
        else{
            break;
        }
    }
    if (ans == N && x != 0){
        --ans;
    }

    cout << ans << endl;
    return 0;
}
