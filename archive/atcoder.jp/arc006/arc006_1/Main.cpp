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
  int n = 6;
  map<int, int> mp;
  for(int i = 0; i < n; ++i){
    int e; cin >> e;
    ++mp[e];
  }
  int b;cin >> b;
  map<int, int> mp2;
  for(int i = 0; i < n; ++i){
    int t; cin >> t;
    ++mp2[t];
  }
  int ans = 0;
  for(auto it : mp2){
    if(mp.count(it.first)){
      ++ans;
    }
  }
  int res = 0;
  if(ans==6){
    res = 1;
  }
  else if(ans == 5){
    if(mp2.count(b)){
      res= 2;
    }
    else{
      res = 3;
    }
  }
  else if(ans == 4){
    res = 4;
  }
  else if(ans== 3){
    res = 5;
  }
  cout << res << endl;
}
