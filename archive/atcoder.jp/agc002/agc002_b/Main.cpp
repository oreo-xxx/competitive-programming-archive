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
    int N, M; cin >> N >> M;
    vector<int> nums(N, 1);
    vector<bool> can(N, false);
    can[0] = true;

    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        if (can[a]){
            can[b] = true;
            if (nums[a] == 1){
                can[a] = false;
            }
        }
        --nums[a];
        ++nums[b];
    }

    int res = 0;
    for (int i = 0; i < N; ++i){
        if (can[i] && nums[i] > 0){
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}
