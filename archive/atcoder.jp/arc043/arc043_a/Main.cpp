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
  int n; ld a,b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  ld sum = 0;
  for(int i = 0; i < n; ++i){
    cin >> v[i];
    sum += v[i];
  }
  sort(v.begin(), v.end());
  ll d = v[n-1]-v[0];
  if(d==0){
    cout << -1 << endl;
    return 0;
  }
  ld ans = b/(ld)d;
  sum *= ans;
  sum /= (ld)n;
  ld ans2 = (a-sum);
  cout << fixed << setprecision(10);
  cout << ans << " " << ans2 << endl;
}
