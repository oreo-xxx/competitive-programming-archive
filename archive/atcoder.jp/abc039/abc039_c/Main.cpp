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
  string s;cin >> s;
  s=s.substr(0,12);
  s = s + s;
  string t = "WBWBWWBWBWBW";
  for(int i = 0; i < 24; ++i){
    bool flag = true;
    for(int j = 0; j < 12; ++j){
      if(s[i+j]!= t[j]){
        flag = false;
        break;
      }
    }
    if(flag){
      string ans;
      if(i == 0)ans = "Do";
      if(i == 1)ans = "Si";
      if(i == 3)ans = "La";
      if(i == 5)ans = "So";
      if(i == 7)ans = "Fa";
      if(i == 8)ans = "Mi";
      if(i == 10)ans = "Re";
      cout << ans << endl;
      return 0;
    }
  }
}
