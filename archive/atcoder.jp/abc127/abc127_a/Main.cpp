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

    int a, b; cin >> a >> b;

    int ans = 0;
    if(a >= 13){
        ans = b;
    }
    else if(a <= 5){
        ans = 0;
    }
    else{
        ans = b/2;
    }
    cout << ans << endl;

    return 0;
}

