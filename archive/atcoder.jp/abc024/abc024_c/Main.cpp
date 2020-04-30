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
  int n,d,k;
  cin >> n >> d >> k;
  vector<int> l(d), r(d);
  for(int i = 0; i < d; ++i){
    cin >> l[i] >> r[i];
  }
  for(int i = 0; i < k; ++i){
    int s, t;cin >> s >> t;
    bool f = true;
    if(s>t)f = false;
    for(int j = 0; j < d; ++j){
      if(f){
        if(l[j]<= s && s<= r[j]){
          s = min(r[j], t);
        }
      }
      else{
        if(l[j]<= s && s<= r[j]){
          s = max(l[j], t);
        }
      }
      if(s == t){
        cout << j+1 << endl;
        break;
      }
    }
  }
}
