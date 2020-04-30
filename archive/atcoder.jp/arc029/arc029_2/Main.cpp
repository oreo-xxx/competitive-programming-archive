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

ld a,b,h,w;

int check(ld ang){ 
  ld rad = M_PI * ang / 180.0;
  ld h_ = a* cos(rad)+ b* sin(rad);
  ld w_ = a* sin(rad)+ b* cos(rad);
  if(h_<=h && w_ <= w){
    return 0;
  }
  else if(h_ > h){
    return 1;
  }
  else{
    return -1;
  }
}

int main() {
  cin >> a >> b;
  if(a<b){
    swap(a,b);
  }
  
  int n;cin >> n;
  for(int i = 0; i < n; ++i){
    ld c,d;cin >> c >> d;
    h = max(c,d);
    w = min(c,d);
    if(a<= h && b <= w){
      cout << "YES" << endl;
      continue;
    }
    if(a> h && b >w){
      cout << "NO" << endl;
      continue;
    }
    
    ld lb = 0.0, ub = 90.0;
    bool flag = false;
    for(int j = 0; j < 50; ++j){
      ld mb = (lb+ub)/2.0;
      int ret = check(mb);
      if(ret==0){
        flag= true;
        break;
      }
      else if(ret==1){
        lb = mb;
      }
      else{
        ub = mb;
      }
    }
    if(flag){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}
