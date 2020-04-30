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
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int ans = 0;
  for(int i = 0; i <= a; ++i){
    for(int j = 0; j <= b; ++j){
      for(int k = 0; k <= c; ++k){
        int tmp = 500*i+100*j+50*k;
        if(x == tmp)++ans;
      }
    }
  }
  cout << ans << endl;
}
