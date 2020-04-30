#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>;
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
  int n;cin >>n;
  map<ll, int> mp;
  for(int i = 0; i < n; ++i){
    int a;cin >>a;
    ++mp[-1*a];
  }
  ll ans=1;int count=0;
  for(auto it : mp){
    if(ans==1&&it.second/2>=2){
      ans = it.first * it.first;
      count=2;
      break;
    }
    if(it.second/2>=1){
      ans*=it.first;
      ++count;
      if(count==2){
      break;
      }
    }
  }
  if(count!=2)ans=0;
  cout << ans << endl;
}
