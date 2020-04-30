#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 30;
const ll MOD = 1000000007;

ll dp[101010];

bool hasElement(const vector<int>& vec, int target){
    return binary_search(vec.begin(), vec.end(), target);
}

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n, m;cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; ++i){
        cin >> a[i];
    }

    dp[0] = 1;
    if(hasElement(a, 1)){
        dp[1] = 0;
    }
    else{
        dp[1] = 1;
    }

    for(int i = 2; i <= n; ++i){
        if(!hasElement(a, i)){
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
    }

    cout << dp[n] << endl;
    return 0;
}

