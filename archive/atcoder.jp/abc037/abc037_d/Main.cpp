#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<vector<int>> G;
ll dp[1000001] = {};

ll rec(int v) {
    if (dp[v] != 0) {
        return dp[v];
    }
    dp[v] += 1;
    ll res = 0;
    for (auto next_v : G[v]) {
        res += rec(next_v);
        res%=MOD;
    }

    dp[v] += res;
    dp[v] %= MOD;
    return dp[v];
}

int main(){
  int H, W ;cin >>H >> W;
  int n = H * W;
  G.resize(n);
  vector<vector<int>> a(H, vector<int>(W));
  for(int i = 0; i < H; ++i)
    for(int j=0; j <W; ++j)
       cin >>a[i][j];

  for(int h = 0; h < H; ++h){
    for(int w = 0; w < W; ++w){
      for(int i = 0; i < 4; ++i){
        int nh = h+dy[i];
        int nw = w+dx[i];
        if(0<=nh&&nh<H
          && 0<=nw&&nw<W
          && a[nh][nw]>a[h][w])
        {
          G[h*W+w].push_back(nh*W+nw);
        }
      }
    }
  }
  ll res = 0;
  for (int v = 0; v < n; ++v) {
    res += rec(v);
    res %= MOD;
  }
  cout << res << endl;
  return 0;
}