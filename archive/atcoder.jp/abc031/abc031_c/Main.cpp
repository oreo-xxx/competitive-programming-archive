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
  int n;cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  int ans = -INF32;
  for(int i = n-1; i >= 0; --i){
    int tmp = 0;
    int M = -INF32;
    for(int j = 0; j < n; ++j){
      if(i == j) continue;
      int l = min(i,j);
      int r = max(i,j);
      int tak = 0, ao = 0;
      int step = 0;
      for(int k = l; k <= r; ++k){
        if(step%2==0) tak += a[k];
        else ao += a[k];
        ++step;
      }
      if(M<ao){
        M = ao;
        tmp = tak;
      }
    }
    //cout << tmp << endl;
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
