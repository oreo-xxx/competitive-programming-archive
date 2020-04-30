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
  ll n; cin >> n;
  if(n<=2){
    cout << 0 << endl;
    return 0;
  }
  vector<ll> a(n+1);
  a[2]=1;
  for(int i = 3; i <= n; ++i){
    a[i]=a[i-1]+a[i-2]+a[i-3];
    a[i] %= 10007;
  }
  cout << a[n-1] << endl;
}
