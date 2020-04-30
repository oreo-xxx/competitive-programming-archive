#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
    string  n, m; cin >>n>> m;
    int ans = 0;
    for(int i = 0; i < n.size(); ++i){
        if(n[i]==m[i])++ans;
    }
    cout << ans << endl;
}
