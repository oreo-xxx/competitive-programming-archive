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
  string s;cin >>s;
  int n=s.size();
  ll ans = 0;
  for(int i = 0; i < n; ++i){
    if(s[i]=='U'){
      ans+=2*i;
      ans+=n-i-1;
    }
    else{
      ans+=i;
      ans+=2*(n-i-1);
    }
  }
  cout << ans << endl;
}
