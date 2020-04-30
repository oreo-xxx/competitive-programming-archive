#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
  int n; cin >>n;
  map<int, int> mp;
  for(int i = 0; i < n; ++i){
    int a;cin >>a;
    ++mp[a-1];
    ++mp[a];
    ++mp[a+1];
  }
  int ans=0;
  for(auto it : mp){
    ans=max(ans,it.second);
  }
  cout << ans << endl;
}

