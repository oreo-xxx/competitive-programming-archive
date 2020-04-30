#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>;
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

bool check(ll n){
  if(n==1){return false;}
  for(ll i = 2; i*i <= n; ++i){
    if(n%i==0){return false;}
  }
  return true;
}

int main() {
  ll n;cin >>n;
  ll tmp = (n+1)* n/2;
  if(check(tmp)){
    cout << "WANWAN" << endl;
  }
  else{
    cout << "BOWWOW" << endl;
  }
}
