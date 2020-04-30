#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
  string s ;
  cin >> s;
  int n = s.size();
  int ans = INF32;
  for(int i = 0; i < n; ){
    int j = i;
    for(; j < n; ++j){
      if(s[j]!=s[i])break;
    }
    int tmp = max(j, n-j);
    ans = min(ans, tmp);
    i=j;
  }
  cout << ans << endl;
  return 0;
}