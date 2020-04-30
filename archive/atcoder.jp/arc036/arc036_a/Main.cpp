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
  int n,k;cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; ++i)cin >> a[i];
  
  int sum = 0;
  for(int i = 0; i < n; ++i){
    sum += a[i];
    if(i<2) continue;
    if(sum<k){
      cout << i+1 << endl;
      return 0;
    }
    sum -= a[i-2];
  }
  cout << -1 << endl;
}
