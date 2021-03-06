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
  ll n,k; cin >>n>> k;
  vector<ld> a(n);
  for(int i = 0; i < n; ++i){
    cin >>a[i];
  }
  sort(a.begin(),a.end(),greater<ld>());
  ld ans=0.0;
  for(int i = 0; i < k; ++i){
    ans+= a[i] / pow(2.0, i+1);
  }
  cout << setprecision(12) <<  ans << endl;
}
