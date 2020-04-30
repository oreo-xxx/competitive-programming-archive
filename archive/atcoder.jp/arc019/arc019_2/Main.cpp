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
  int m = n/2;
  int num = 0;
  for(int i = 0; i < m; ++i){
    if(s[i]!=s[n-1-i]){
      ++num;
    }
  }
  
  int ans = 0;
  if(num>1){
    ans= 25* n;
  }
  else if(num==0){
    ans = 25*m*2;
  }
  else{
    ans= 24*2;
    ans += 25*(m-1)*2;
    if(n%2==1){
      ans+= 25;
    }
  }
  
  cout << ans << endl;
}
