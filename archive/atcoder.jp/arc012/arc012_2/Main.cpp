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
  int n; ld a,b,l;
  cin >> n>> a >> b >> l;
  for(int i = 0; i < n; ++i){
    ld t = l/a;
    l = b * t;
  }
  cout << fixed << setprecision(10) << l << endl;
}
