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

int M = 1000001;
int main(){
  int n; cin >> n;
  vector<int> ends(n);
  map<int, vector<pint>> jobs;
  for(int i = 0; i < n; ++i){
    int s; cin >> s >> ends[i];
    jobs[s].push_back({ends[i],i});
  }
  vector<pint> dp(M+1);
  dp[M]={0,INF32};
  for(int i = M-1; i>=0; --i){
    dp[i]=dp[i+1];
    for(pint job : jobs[i]){
      if(dp[i].first < dp[job.first].first+1){
        dp[i].first=dp[job.first].first+1;
        dp[i].second = job.second;
      }
      else if(dp[i].first==dp[job.first].first+1){
        dp[i].second = min(dp[i].second, job.second);
      }
    }
  }
  
  cout << dp[0].first << endl;
  int now = 0;
  while(true){
    if(dp[now].second > M)break;
    if(now!=0)cout << " ";
    cout << dp[now].second + 1;
    now= ends[dp[now].second];    
  } 
  cout << endl;
}
