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

int dp[1000]{};

int main(){
  int n; cin >> n;
  int ng1,ng2,ng3;
  cin >> ng1 >> ng2 >> ng3;
  if(n==ng1||n==ng2||n==ng3){
    cout << "NO" << endl;
    return 0;
  }
  dp[0]=0;
  for(int i = 1; i <= n; ++i){
    dp[i]=INF32;
  }
  for(int i = 0; i < n; ++i){
    if(i==ng1||i==ng2||i==ng3){
      dp[i]=INF32;
      continue;
    }
    dp[i+1]=min(dp[i+1],dp[i]+1);
    dp[i+2]=min(dp[i+2],dp[i]+1);
    dp[i+3]=min(dp[i+3],dp[i]+1);
  }
  string ans = "NO";
  if(dp[n]<=100)ans = "YES";
  //cout << dp[n] << endl;
  cout << ans << endl;
}
