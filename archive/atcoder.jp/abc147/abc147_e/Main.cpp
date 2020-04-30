#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int M=13000;
bool dp[81][81][M] {false};

int main(){
  int h,w;cin >> h >> w;
  Graph a(h, vector<int>(w));
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      cin >> a[i][j];
    }
  }
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      int b;cin >> b;
      a[i][j]= abs(a[i][j]-b);
    }
  }
  
  dp[0][0][0]=true;
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      for(int k = 0; k < M-80; ++k){
        dp[i][j+1][k+a[i][j]] |= dp[i][j][k];
        dp[i][j+1][abs(k-a[i][j])] |= dp[i][j][k];
      }
      for(int k = 0; k < M-80; ++k){
        if(i==h-1)break;
        dp[i+1][j+1][k+a[i+1][j]] |= dp[i][j+1][k];
        dp[i+1][j+1][abs(k-a[i+1][j])] |= dp[i][j+1][k];
      }
    }
  }
  for(int i = 0; i < M; ++i){
    if(dp[h-1][w][i]){
      cout << i << endl;
      break;
    }
  }
}
