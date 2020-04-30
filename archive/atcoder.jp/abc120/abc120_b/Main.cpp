#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

//
int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int a, b, k;
    cin >> a >> b >> k;
    int count = 0;
    vector<int> ans;
    for(int i = min(a, b); i > 0; --i){
        if((a % i == 0) && (b % i == 0)){
            ans.push_back(i);
        }
    }
    cout << ans[k - 1] << endl;
    return 0;
}

