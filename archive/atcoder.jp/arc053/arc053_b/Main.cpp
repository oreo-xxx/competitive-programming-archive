#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
  string s;cin >>s;
  int n=s.size();
  map<char, int> mp;

  for(int i = 0; i < n; ++i){
    ++mp[s[i]];
  }
  int odd=0,even =0;
  for(auto it : mp){
    even += it.second/2;
    if(it.second%2==1){
      odd += 1;
    }
  }
  int ans = 1;
  if(odd == 0){
    cout << n << endl;
    return 0;
  }
  else{
    int tmp =even/odd;
    ans = 1 + 2 * tmp;
  }
  cout << ans << endl;
}
