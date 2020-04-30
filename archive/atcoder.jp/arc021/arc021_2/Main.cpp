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
  vector<int> a(n),b(n);
  for(int i = 0; i < n; ++i)cin >> b[i];
  for(int i = 0; i < n-1; ++i){
    a[i+1]= a[i]^b[i];
  }
  if((a[0]^a[n-1])!=b[n-1]){
    cout << -1 << endl;
    return 0;
  }
  for(int i = 0; i < n; ++i){
    cout << a[i] << endl;
  }
}
