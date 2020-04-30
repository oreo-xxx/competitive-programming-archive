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
  string s;cin >> s;
  int n = s.size();
  for(int i = 0; i < n; ++i){
    if(s[i]=='o'){s[i]='1';}
    else{s[i]='0';}
  }
  vector<bitset<10>> a(n);
  for(int i = 0; i < n; ++i){
    string t = s;
    rotate(t.begin(),t.begin()+i, t.end());
    bitset<10> bs(t);
    a[i]=bs;
  }
  int ans = 100;
  for(int i = 0; i < (1<<n); ++i){
    bitset<10> b(i), tmp;    
    for(int j = 0; j < n; ++j){
      if(b[j]==1){
        tmp |=  a[j];
      }
    }
    if(tmp.count()==n){
      ans=min(ans, (int)b.count());
    }
  }
  cout << ans << endl;
}
