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
  s.push_back('B');
  string t;
  for(int i = 0; i < n; ++i){
    if(s[i]=='B'&& s[i+1]=='C'){
      t+='D';
      ++i;
    }
    else t+=s[i];
  }
  int m = t.size();
  ll ans=0, count=0;
  for(int i = 0; i < m; ++i){
    if(t[i]=='A'){
      ++count;
    }
    else if(t[i]=='D'){
      ans+=count;
    }
    else{
      count=0;
    }
  }
  cout << ans << endl;
}
