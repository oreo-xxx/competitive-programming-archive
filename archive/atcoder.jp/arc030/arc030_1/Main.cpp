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
  int n,k;cin >> n >> k;

  if(k==1){
    cout << "YES" << endl;
    return 0;
  }
  --n;
  int t = 1;
  
  while(n > 0){
    if(t==k){
      cout << "YES" << endl;
      return 0;
    }
    n -= 2;
++t;
  }
  cout << "NO" << endl;
}
