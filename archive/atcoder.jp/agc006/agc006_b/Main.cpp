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
    int N, x;
    cin >> N >> x;

    if (x <= 1 || x >= N*2-1) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> res(2 * N - 1, -1);

    res[N-2] = 1;
    res[N-1] = x;
    res[N] = 2 * N - 1;

    int iter = 0;
    for (int v = 2; v < 2 * N - 1; ++v) {
        if (v == x) continue;
        while (res[iter] != -1){
            ++iter;
        }
        res[iter] = v;
    }

    cout << "Yes" << endl;
    for (auto v : res){
        cout << v << endl;
    }

    return 0;
}
