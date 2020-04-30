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
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        // same を抜ける
        while (i + 1 < N && A[i] == A[i + 1]){
            ++i;
        }

        // up
        if (i + 1 < N && A[i] < A[i + 1]) {
            while (i + 1 < N && A[i] <= A[i + 1]){
                ++i;
            }
        }

        // down
        else if (i + 1 < N && A[i] > A[i + 1]) {
            while (i + 1 < N && A[i] >= A[i + 1]){
                ++i;
            }
        }
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
