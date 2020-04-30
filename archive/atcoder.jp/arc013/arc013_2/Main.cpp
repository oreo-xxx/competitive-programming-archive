#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
  int n; cin >>n;
  ll a=0, b =0, c=0;
  vector<ll> t(3);
  for(int i = 0; i < n; ++i){
    cin >>t[0]>> t[1]>> t[2];
    sort(t.begin(),t.end());
    a=max(a,t[0]);
    b=max(b,t[1]);
    c=max(c,t[2]);
  }
  
  ll ans=a* b* c;
  
  cout << ans << endl;
}
