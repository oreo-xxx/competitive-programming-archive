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
  ld p;cin >>p;
  ld lb =0, ub =2*p;
  ld ans=p;
  while(ub-lb>1e-12){
    ld x1 = (lb*2+ub)/3.0;
    ld x2 = (lb+ub*2)/3.0;
    ld y1 = x1 + p/pow(2.0, x1/1.5);
    ld y2 = x2 + p/pow(2.0, x2/1.5);
    if(y1>y2){
      lb=x1;
    }
    else{
      ub=x2;
    }
   }
  cout << setprecision(12) << ub+p/pow(2.0, ub/1.5) << endl;
}
