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
  int n;cin >> n;
  vector<int> a(n), b(n), c(n-1);
  for(int i = 0; i < n; ++i){
    cin >> a[i]; --a[i];
  }
  for(int i = 0; i < n; ++i){
    cin >> b[i];
  }
  for(int i = 0; i < n-1; ++i){
    cin >> c[i];
  }
  int ans = 0, prev= -2;
  for(int i = 0; i < n; ++i){
    ans += b[a[i]];
    if(prev+1==a[i]){
      ans += c[prev];
    }
    prev=a[i];
  }
  cout << ans << endl;
}
