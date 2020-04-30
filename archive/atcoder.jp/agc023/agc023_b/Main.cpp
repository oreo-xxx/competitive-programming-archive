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

int n;
vector<string> s;

bool check(int y, int x){
  string s1,s2;
  for(int i = 0; i < n; ++i){
    s1 += s[y+i].substr(x+i, n-i);
    for(int j = i; j < n; ++j){
      s1 += s[y+j][x+i];
      s2 += s[y+j][x+i];
    }
    s2 += s[y+i].substr(x+i, n-i);
  }
  if(s1==s2){return true;}
  //cout << s1 <<" " << s2 << endl;
  return false;
}

int main() {
  cin >>n;
  vector<string> a(n);
  for(int i = 0; i < n; ++i){
    cin >>a[i];
  }
  
  s.resize(2*n);
  for(int i = 0; i < 2*n; ++i){
    s[i]=a[i%n] + a[i%n];
  }
  for(int i = 0; i < 2*n; ++i){
    //cout << s[i] << endl;
  }
  
  int ans = 0;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < 1; ++j){
      if(check(i,j)){
        ++ans;
      }
    }
  }
  cout << ans* n << endl;
}
