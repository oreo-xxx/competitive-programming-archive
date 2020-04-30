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
  int m,k;cin >> m >> k;
  if(m==1){
    string ans = "-1";
    if(k==0) ans = "0 0 1 1";
    cout << ans << endl;
    return 0;
  }
  if(k>=(1<<m)){
    cout << -1 << endl;
    return 0;
  }
  for(int i = 0; i < (1<<m); ++i){
    if(i==k) continue;
    cout << i << ' ';
  }
  cout << k << ' ';
  for(int i = (1<<m)-1; i>=0; --i){
    if(i==k) continue;
    cout << i << ' ';
  }
  cout << k << endl;
}

