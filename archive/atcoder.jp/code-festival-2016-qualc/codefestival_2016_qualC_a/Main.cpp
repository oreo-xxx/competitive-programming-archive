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
  string s; cin >> s;
  bool  c= false, f = false;
  for(int i = 0; i < s.size(); ++i){
    if(!c && s[i]=='C')c = true;
    else if(c && !f  && s[i]== 'F')f = true;
  }
  string ans = "No";
  if(c && f )ans = "Yes";
  cout << ans << endl;
}
