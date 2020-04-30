#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i)cin >>a[i];
  int ans = 0;
  for(int i = 0; i < n; ++i){
    for(int j = i+1; j < n; ++j){
      ans+= a[i]*a[j];
    }
  }
  cout << ans << endl;
  return 0;
}