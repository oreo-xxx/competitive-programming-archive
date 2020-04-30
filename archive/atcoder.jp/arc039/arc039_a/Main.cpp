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
  string a,b;cin >> a >> b;
  int n = 3;
  string a_ = a;
  string b_ = b;
  for(int i = 0; i < n; ++i){
    if(a_[i]!='9'){
      a_[i] = '9';
      break;
    }
  }
  for(int i = 0; i < n; ++i){
    char c = '0';
    if(i==0) c = '1';
    if(b_[i]!=c){
      b_[i] = c;
      break;
    }
  }
  int ans = stoi(a_)-stoi(b);
  ans = max(ans, stoi(a)-stoi(b_));
  cout << ans << endl;
}
