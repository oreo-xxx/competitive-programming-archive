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
  ld a,b,c;
  cin >> a >> b >> c;
  ld lb = 0, ub = 500;
  while(ub-lb>1e-12){
    ld mb = (lb+ub)/2.0;
    if(a*mb + b*sinl(c*M_PI*mb)>100.0){
      ub = mb;
    }
    else {
      lb = mb;
    }
  } 
  cout << fixed << setprecision(10) << ub << endl;
  //cout << a*ub + b*sin(c*M_PI*ub)<< endl;
  
}
