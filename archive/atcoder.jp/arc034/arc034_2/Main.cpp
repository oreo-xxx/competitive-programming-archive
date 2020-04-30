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

ll keta(ll n){
  string s = to_string(n);
  ll sum = 0;
  for(int i = 0; i < s.size(); ++i){
    sum+= (ll)(s[i]-'0');
  }
  return sum;
}

int main() {
  ll n;cin >> n;
  ll m = to_string(n).size();
  // i 桁でつくるには
  // j-i< n < j+9i
  set<ll> ans;
  for(int i = 1; i <= m; ++i){
    for(int j = 1; j <= 9*i; ++j){
      if(n-j+keta(n-j)==n)ans.insert(n-j);      
    }
  }
  cout << ans.size() << endl;
  for(auto it : ans){
    cout << it  << endl;
  }
}
