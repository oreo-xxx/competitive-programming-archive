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
    int N, C, K; cin >> N >> C >> K;
    vector<int> T(N);
    for (int i = 0; i < N; ++i){
        cin >> T[i];
    }

    sort(T.begin(), T.end());
    int ans = 0;
    for (int i = 0; i < N;) {
        ++ans;
        int start = i;
        while (i < N && T[i] - T[start] <= K && i - start < C){
            ++i;
        }
    }
    cout << ans << endl;

    return 0;
}
