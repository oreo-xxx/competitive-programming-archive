#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

int main(){
  int n, k;
  cin >>n>> k;
  int ans = 0;
  if(n% k!=0){ans++;}
  cout << ans << endl;
}