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

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h+1);
  for(int i = 0; i < h; ++i){
    cin >> s[i];
    s[i] += '#';
  }
  
  for(int i = 0; i <= w; ++i){
    s[h][i]='#';
  }
  
  vector<vector<bool> > dp(h, vector<bool> (w));
  dp[h-1][w-1]= false;
  for(int i = h-1; i >= 0; --i){
    for(int j = w-1; j >= 0; --j){
      // 負けに渡せたら勝ち
      bool flag = true;
      if(s[i+1][j] != '#' && dp[i+1][j]==false){
        dp[i][j]=true;
        flag= false;
      }
      if(s[i][j+1] != '#' && dp[i][j+1]==false){
        dp[i][j]=true;
        flag= false;
      }
      if(s[i+1][j+1] != '#' && dp[i+1][j+1]==false){
        dp[i][j]=true;
        flag= false;
      }
      if(flag){
        dp[i][j]=false;
      }
    }
  }
  string ans= "Second";
  if(dp[0][0])ans = "First";
  cout << ans << endl;
}
