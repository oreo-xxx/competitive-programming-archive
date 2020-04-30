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
  int n,m,a,b;
  cin >> n >> m >> a >> b;
  for(int i = 0; i < m; ++i){
    if(n<=a)n+=b;
    int c;cin >> c;
    n -= c;
    if(n<0){
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << "complete" << endl;
}
