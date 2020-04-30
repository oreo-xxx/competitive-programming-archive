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
const int INF32 = 1 << 30;
const ll MOD = 1000000007;

ll dp[2][1025][11]{};

int main(){
  int n,m,y,z;
  cin >> n >> m >> y >> z;
  map<int, int> mp;
  map<char, int> mp2;
  for(int i = 0; i < m; ++i){
    char c; int p; cin >> c >> p;
    mp[i+1]=p;
    mp2[c]=i+1;
  }
  string s; cin >> s;
  int M = (1<<m);
  for(int i = 0; i < 2; ++i){
    for(int j = 0; j < M; ++j){
      for(int k = 0; k <= m; ++k){
        dp[i][j][k]= -INF32;
      }
    }
  }

  dp[0][0][0]=0;
  
  for(int i = 0; i < n; ++i){
    
    int col = mp2[s[i]];
    int idx = col-1;
    int bit = (1<<idx);
    
    for(int j = 0; j < M; ++j){
      for(int k = 0; k <= m; ++k){
        if(dp[i%2][j][k]==-INF32)continue;
        int score = mp[col];
        if(col==k)score += y;
        if( j!= M-1 && (j^bit) == M-1)score += z;
        dp[(i+1)%2][j|bit][col]=max(dp[(i+1)%2][j|bit][col], dp[i%2][j][k]+score);
        dp[(i+1)%2][j][k]= max(dp[(i+1)%2][j][k], dp[i%2][j][k]);
      }
    }
  }
  ll ans = 0;
  for(int i = 0; i < M; ++i){
    for(int j = 0; j <= m; ++j){
      ans = max(ans, dp[n%2][i][j]);
    }
  }
  cout << ans << endl;
}
