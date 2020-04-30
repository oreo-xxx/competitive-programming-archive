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

int dp[3050][6050];
int dp2[3050][6050];

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i] >> b[i];
  }
 
  
  for(int i = 0; i < n; ++i){
    for(int j = 0; j <= k; ++j){
      dp[i+1][j+a[i]] = max(dp[i+1][j+a[i]], dp[i][j]+b[i]);
      dp2[i+1][j+a[n-1-i]] = max(dp2[i+1][j+a[n-1-i]], dp2[i][j]+ b[n-1-i]);
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      dp2[i+1][j] = max(dp2[i+1][j], dp2[i][j]);
    }
  }
  int ans = 0;
  for(int i = 0; i < n; ++i){
    vector<int> sum(5050);
    for(int j = 0; j <= k; ++j){
      sum[j+ 1] = max(sum[j], dp2[n-1-i][j]);
    }
    
    for(int j = 0; j < k; ++j){
      ans = max(ans, dp[i][j]+sum[k-j]+b[i]);
    }
    ans = max(ans, dp[i+1][k]);
    ans = max(ans, sum[k]);
    //cout << ans << endl;
  }
  cout << ans << endl;
  
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= k; ++j){
      //cout << dp[i][j]<< ' ';
    }
    //cout << endl;
  }
  
}
