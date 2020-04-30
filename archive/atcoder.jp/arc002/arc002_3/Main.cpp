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

int N;
string s,l,r;
string c="ABXY";

int check(){
  int count=0;
  for(int i = 0; i < N-1; ++i){
    if( (s[i]==l[0] && s[i+1]==l[1]) || 
        (s[i]==r[0] && s[i+1]==r[1]) ){
        ++i;++count;
    }
  }
  return N-count;
}

int main() {
  cin >>N>> s;
  int n = 4;
  l.resize(2);
  r.resize(2);
  int ans = N;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      for(int k = 0; k < n; ++k){
        for(int m = 0; m < n; ++m){
          l[0]=c[i]; l[1]=c[j];
          r[0]=c[k]; r[1]=c[m];
          int tmp = check();
          ans = min(ans,tmp);
        }
      }
    }
  }
  cout << ans << endl;
}
