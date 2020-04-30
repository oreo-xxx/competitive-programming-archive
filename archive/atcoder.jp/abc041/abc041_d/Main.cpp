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

ll dp[(1<<20)]{};
int main(){
  ll n,m;cin >> n >> m;
  vector<int> a(n);
  for(int i = 0; i < m; ++i){
    int x,y;cin >> x >> y;
    --x;--y;
    a[x] = a[x]|(1<<y);
  }
  
  dp[0]=1;
  for(int i = 0; i < (1<<n); ++i){
    for(int j = 0; j < n; ++j){
      if(((i&(1<<j))==0) && ((i & a[j])==0) ){
        dp[i|(1<<j)] += dp[i];
      }
    }
  }
 
  cout << dp[(1<<n)-1] << endl;
}
