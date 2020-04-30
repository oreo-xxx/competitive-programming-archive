#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

bool comp(P a, P b) { return a.second < b.second; }

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, M; cin >> N >> M;
    map<int, vector<int> > mp;
    for (int i = 0; i < N; ++i){
        int a, b; cin >> a >> b;
        mp[a].push_back(b);
    }

    ll ans = 0;
    priority_queue<int> que;
    for (int i = 0; i <= M; ++i){
        for(auto it : mp[i]){
            que.push(it);
        }
        if(!que.empty()){
            ans += que.top(); que.pop();
        }
    }
    cout << ans << endl;

    return 0;
}

