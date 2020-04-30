#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
  ll n,k;cin >>n>> k;
  vector<ll> a(n), sum(n+1);
  for(int i = 0; i < n; ++i)cin >>a[i];
  ll idx =-1;
  for(int i =0; i < n-1; ++i){
    if(a[i]+a[i+1]>=k){
      idx = i;
      break;
    }
  }
  if(idx == -1){
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  for(int i = 0; i < idx; ++i){
    cout << i+1 << endl;
  }
  for(int i = n-2; i >= idx; --i){
    cout << i+1 << endl;
  }
}
