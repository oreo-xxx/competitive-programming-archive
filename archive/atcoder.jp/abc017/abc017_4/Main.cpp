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

int dp[101010];
int sum[101010];

int main(){
  int n,m;cin >> n >> m;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  vector<int> L(n);
  map<int, int> mp;
  int l = 0;
  for(int r = 0; r < n; ++r){
    ++mp[a[r]];
    while(l<n && mp[a[r]]>1){
      --mp[a[l]];
      ++l;
    }
    L[r]=l;
  }
  dp[0]=1;
  sum[1]=1;
  for(int i = 1; i <= n; ++i){
    dp[i] = (sum[i]-sum[L[i-1]]+MOD) % MOD;
    sum[i+1]= (sum[i]+ dp[i])%MOD; 
  }
  for(int i = 0; i < n; ++i){
    //cout << dp[i] << endl;
  }
  cout << dp[n] << endl;
}
