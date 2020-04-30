#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 4;

vector<ll> ans;

void dfs(ll idx, ll now){
    if(idx == 10) return;
    for(int i = -1; i <= 1; ++i){
        ll tmp = now%10 + i;
        if(tmp == -1 || tmp == 10) continue;
        ll now2 = 10 * now + tmp;
        ans.push_back(now2);
        dfs(idx + 1, now2);
    }
}

void solve() {
    ll K; cin >> K;
    string s = "3234566667";
    int n = s.size();
    for(int i = 1; i < 10; i++) {
        ans.push_back(i);
        dfs(0, i);
    }
    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
    cout << ans[K-1] << endl;
    return;
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
#else

    solve();

#endif
    return 0;
}
