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

ll n,W;
ll dp[201][200010]{};
ll v[201];
ll w[201];

vector<pll> make(int m, int idx){
  vector<pll> a;
  for(int b = 0; b < (1<<m); ++b){
    ll tv = 0, tw = 0;
    for(int i = 0; i < m; ++i){
      if(b&(1<<i)){
        tv+=v[i+idx];
        tw+=w[i+idx];
      }
    }
    a.push_back({tw,tv});
  }
  sort(a.begin(), a.end());
  for(int i = 1; i < a.size(); ++i){
    a[i].second = max(a[i].second , a[i-1].second );
  }
  return a;
}


ll s1(){
  int m = n/2;
  int k = n-m;
  vector<pll> v, v2;
  v = make(m, 0);
  v2 = make(k,m);
  int i = 0, j = v2.size()-1;
   ll ans = 0;
  while(i!= v.size()-1 &&  j!=0){
    while (v[i].first+v2[j].first>W){
      if(j==0)break;
      else --j;
    }
    while (v[i].first+v2[j].first<=W){
      ans = max(ans, v[i].second + v2[j].second );
      if(i== v.size()-1)break;
      else ++i;
    }
  }
  return ans;
}

ll s2(){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < W+1; ++j){
      dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
      if(j+w[i]<W+1)dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j]+v[i]);
    }
  }
  ll ans = 0;
  for(int i = 0; i < W+1; ++i){
    ans = max(ans, dp[n][i]);
  }
  return ans;
}

ll s3(){
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= 200000; ++j){
      dp[i][j]= INF;
    }
  }
  dp[0][0]=0;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j <= 200000; ++j){
      if(j<v[i])dp[i+1][j]=dp[i][j];
      else dp[i+1][j]=min(dp[i][j], dp[i][j-v[i]]+w[i]);
    }
  }
  ll ans = 0;
  for(int i = 0; i < 200001; ++i)if(dp[n][i]<=W)ans = i;
  return ans;
}

int main(){
  cin >> n >> W;
  ll M = 0;
  for(int i = 0; i < n; ++i){
    cin >> v[i] >> w[i];
    M = max(M, w[i]);
  }
  
  ll ans = 0;
  if(n<31){
    ans = s1();
  }
  else{
    if(M<1001){
      ans = s2();
    }
    else{
      ans = s3();
    }
  }
  cout << ans << endl;
}
