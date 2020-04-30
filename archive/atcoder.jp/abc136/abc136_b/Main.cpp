#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

/// Lib
///

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string n; cin >> n;
    int n_num = stoi(n);

    int ans = 0;
    for(int i = 1; i <= n_num; ++i){
        string tmp = to_string(i);
        int tmp_keta = tmp.size();
        if(tmp_keta % 2 != 0){
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
