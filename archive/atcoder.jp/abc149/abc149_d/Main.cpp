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
  ll r,s,p;cin >> r >> s >> p;
  map<char, ll> mp;
  mp['s']=r;
  mp['p']=s;
  mp['r']=p;
  string t;cin >> t;
  //int m = n / k;
  ll ans = 0;
  for(int i = 0; i < k; ++i){
    char now = 'a';
    for(int j = i; j < n; j+=k){
      if(t[j]!=now){
        now=t[j];
        ans += mp[now];
      }
      else{
        now='a';
      }
    }
  }
  cout << ans << endl;
}
