#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;
int sum=0;
int used[9]{};
vector<int> b(6),c(6);
int calc(){
  int tak = 0;
  for(int i = 0; i < 6; ++i){
    if(used[i]==used[i+3]){
      tak += b[i];
    }
    int j = i + i/2;
    if(used[j]==used[j+1]){
      tak += c[i];
    }
    
  }
  return sum - tak;
}

int rec(int n){
  if(n==9){
    return calc();
  }
  int ret = INF32;
  if(n%2!=0) ret = -INF32;
  for(int i = 0; i < 9; ++i){
    if(used[i]!=0)continue;
    used[i]=1;
    if(n%2!=0) ++used[i];
    
    if(n%2!=0) ret = max(ret, rec(n+1));
    else ret = min(ret, rec(n+1));
    used[i]=0;
  }
  return ret;
}

int main(){
  for(int i = 0; i < 6; ++i){
    cin >> b[i];
    sum += b[i];
  }
  for(int i = 0; i < 6; ++i){
    cin >> c[i];
    sum += c[i];
  }
  int ans= rec(0);
  cout << sum-ans << endl;
  cout << ans << endl;
}
