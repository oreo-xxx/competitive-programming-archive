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
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    int count = 0;
    for(int i = 0; i < n; ++i){
        if(p[i] != i + 1){
            ++count;
        }
    }

    if(count <= 2){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}
