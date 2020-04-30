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
  int n;string s;
  cin >> n >> s;
  ll ans = 1, now = 0;
  for(int i = 0; i < 2*n; ++i){
    bool f = false;
    if(s[i]=='B'&& now%2==0)f = true;
    if(s[i]=='W'&& now%2!=0)f = true;
    if(f)++now;
    else{
      ans = (ans*now)%MOD;
      --now;
    }
  }
  if(now != 0)ans= 0;
  for(int i = 1; i <= n; ++i){
    ans= (ans*i)% MOD;
  }
  cout << ans << endl;
}
