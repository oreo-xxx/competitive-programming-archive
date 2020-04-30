#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

ll dp[2][101010];
vector<vector<int> >g;
void dfs(int v, int p){
	for(auto e : g[v]){
		if(e == p){continue;}
		dfs(e, v);
		(dp[0][v] *= (dp[0][e] + dp[1][e]))%=MOD;
		(dp[1][v] *= dp[0][e])%=MOD;
    }
}

int main(){
     int n;cin >>n;
     g.resize(n);
     for(int i = 0; i < n-1; ++i){
         int a, b; cin >>a >>  b;
         --a; --b;
         g[a].push_back(b);
         g[b].push_back(a);
    }
    
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 101010; ++j){
            dp[i][j]=1;
        }
    }
    dfs(0, -1);
    ll ans = (dp[0][0]+dp[1][0])% MOD;
    cout << ans << endl;
}