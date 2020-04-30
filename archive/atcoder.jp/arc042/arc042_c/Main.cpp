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

int dp[5050][10050]{};

int main(){
  int n,k;
  cin >> n >> k;
  vector<pint> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i].first >> a[i].second ;
    a[i].first *= -1;
  
  }
  sort(a.begin(), a.end());
 
  
  for(int i = 0; i < n; ++i){
    for(int j = 0; j <= k; ++j){
      dp[i+1][j-a[i].first] = max(dp[i+1][j-a[i].first], dp[i][j]+a[i].second);
    }
    for(int j = 0; j < k+ 200; ++j){
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
    }
  }
  int ans = 0;
  for(int i = 0; i < k + 200; ++i){
    ans = max(ans, dp[n][i]);
  }
  cout << ans << endl;
}
