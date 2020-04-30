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

int dp[5050][5050];
int dp2[5050][5050];

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; ++i)cin >> a[i];
  sort(a.begin(),a.end());
  dp[0][0]= 1;
  dp2[0][0]= 1;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j <= k; ++j){
      if(j-a[i]>= 0){
        dp[i+1][j]|= dp[i][j-a[i]];
      }
      dp[i+1][j]|= dp[i][j];
      if(j-a[n-1-i]>=0){
        dp2[i+1][j]|= dp2[i][j-a[n-1-i]];
      }
      dp2[i+1][j]|= dp2[i][j];
    }
  }
  int ans = 0;
  
  for(int i = 0; i < n; ++i){
    if(a[i]>=k){
      ++ans;
      continue;
    }
    vector<int> sum(5050);
    for(int j = 0; j <= k; ++j){
      sum[j+1] = sum[j] + dp2[n-1-i][j];
    }
    
    for(int j = 0; j < k; ++j){
      if(dp[i][j]==1 && sum[k-j]-sum[k-a[i]-j]>0){
        ++ans;
        break;
      }
    }
  }
  cout << n-ans << endl;
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= k; ++j){
      //cout << dp2[i][j]<< ' ';
    }
    //cout << endl;
  }
  
}
