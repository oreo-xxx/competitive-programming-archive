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

int main(){
  ll n; cin >> n;
  ll N = n;
  int cnt = 0;
  while(n!=1){
    n = n/2;
    ++cnt;
  }
  ll tmp = 1;
  for(int i = 0; i < cnt; ++i){
    if(cnt%2==0){
      if(i%2==0){
        tmp = 2*tmp+1;
      }
      else{
        tmp = 2*tmp;
      }
    }
    else{
      if(i%2==0){
        tmp = 2*tmp;
      }
      else{
        tmp = 2*tmp+ 1;
      }
    }
  }
  //cout << tmp << endl;
  
  string ans;
  if(cnt % 2 == 0){
    if(tmp<=N)ans = "Aoki";
    else ans = "Takahashi";
  }
  else{
    if(tmp<=N)ans = "Takahashi";
    else ans = "Aoki";
  }
  
  cout << ans << endl;
}
