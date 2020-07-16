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
  int n,k; cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    int d; cin >> d;
    for(int j = 0; j < d; ++j){
      int c; cin >> c; --c;
      ++a[c];
    }
  }
  int ans = 0;
  for(int i = 0; i < n; ++i){
    if(a[i]==0)++ans;
  }
  cout << ans << endl;
}
