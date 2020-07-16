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

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    sum += a[i];
    a[i] *= n;
  }
  int ans = 0;
  ll tmp = INF;
  for(int i = 0; i < n; ++i){
    if(tmp > abs(sum - a[i])){
      tmp = abs(sum - a[i]);
      ans = i;
    }
  }
  cout << ans << endl;
}
