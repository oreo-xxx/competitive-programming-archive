#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int MOD = 1000000007;

map<int, vector<int> > mp;
bool isChecked[1000];
bool flag;

bool dfs(int i, int prev){
    isChecked[i] = true;
    bool ret = true;
    for(auto itr : mp[i]){
        if(itr == prev){
            continue;
        }
        if(isChecked[itr]){
            flag = false;
            continue;
        }
        dfs(itr, i);
    }
    return ret;
}

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    memset(isChecked, 0, sizeof(isChecked));

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(isChecked[i]){
            continue;
        }
        flag = true;
        dfs(i, -1);
        if(flag){
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}

