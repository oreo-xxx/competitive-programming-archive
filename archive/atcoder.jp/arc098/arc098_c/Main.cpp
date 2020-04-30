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

int n,k,q;

void func(vector<ll>& dst, vector<ll>& src){
  int m = src.size();
  sort(src.begin(), src.end());
  for(int i = 0; i+k-1 < m; ++i){
    dst.push_back(src[i]);
  }
}

int main(){
  cin >> n >> k >> q;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)cin >> a[i];
  
  ll ans = INF;
  for(int i = 0; i < n; ++i){
    vector<ll> tmp, vec;
    for(int j = 0; j < n; ++j){
      if(a[j]<a[i]){
        func(vec,tmp);
        tmp.clear();
      }
      else {
        tmp.push_back(a[j]);
      }
    }
    func(vec,tmp);
    if(vec.size()<q)continue;
    sort(vec.begin(), vec.end());
    ans = min(ans, vec[q-1]-vec[0]);
  }
  cout << ans << endl;
}
