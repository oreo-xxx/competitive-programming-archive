#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//

int N;
vector<int> a;

void solve() {
    vector<int> res;
    for (int i = 0; i < N; ++i) {
        int pivot = -1;
        // 最大のa[j] == j 探索
        for (int j = a.size() - 1; j >= 0; --j) {
            if (a[j] == j) {
                pivot = j;
                break;
            }
        }
        if (pivot == -1) {
            cout << -1 << endl;
            return;
        }
        res.push_back(pivot + 1);
        a.erase(a.begin() + pivot);
    }
    
    // 逆順につめたため、反転
    reverse(res.begin(), res.end());

    for (auto v : res) cout << v << endl;
}


int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
        --a[i];
    }
    solve();
    return 0;
}
