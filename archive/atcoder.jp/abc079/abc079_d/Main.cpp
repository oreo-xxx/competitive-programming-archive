#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;



int main(){
      int h, w; cin >> h >> w;
    int  V = 10, E = 10;
    // initialization of Floyd-Warshall
    vector<vector<long long> > dp(V, vector<long long>(V));
    
    // input
    for(int i = 0; i < V; ++i){
        for (int e = 0; e < E; ++e) {
            int c; cin >> c;
            dp[i][e] = c;
        }
    }
    // Floyd-Warshall
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    
    ll ans = 0;
    for(int i = 0; i < h; ++i){
     	for(int j = 0; j < w; ++j){
     	     int a; cin >>a;
              if(a==-1){continue;}
              ans += dp[a][1];
        }
    }
    cout << ans << endl;
    return 0;
}