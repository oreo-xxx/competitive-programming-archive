#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
  int n,m;cin >>n>> m;
  string s, t;cin >>s>> t;
  
  map<char, int> mp1, mp2;

  for(int i = 0; i < n; ++i){
    ++mp1[s[i]];
  }
  for(int i = 0; i < m; ++i){
    ++mp2[t[i]];
  }
  
  int ans=0;
  for(auto it : mp1){
    if(mp2.count(it.first)==0){
      ans=-1;break;
    }
    ans=max(ans, (it.second+mp2[it.first]-1)/mp2[it.first]);
    
  }
  
  cout << ans << endl;
}
