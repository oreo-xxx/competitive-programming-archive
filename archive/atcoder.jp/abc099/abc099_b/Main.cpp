#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;


int main(){
    int a,b;
  cin >>a>>b;
  vector<int> h(1000);
  for(int i = 1; i < 1000; ++i){
    h[i]=i+h[i-1];
  }
  int d = b-a;
  int ans = h[d] - b;
      
    cout << ans << endl;
    return 0;
}