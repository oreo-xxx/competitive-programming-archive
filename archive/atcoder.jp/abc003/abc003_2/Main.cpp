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

int main() {
  string s, t;cin >> s>> t;
  int n = s.size();
  bool f = true;
  set<char>se;
  se.insert('a');
  se.insert('t');
  se.insert('c');
  se.insert('o');
  se.insert('d');
  se.insert('e');
  se.insert('r');
  se.insert('@');
  for(int i = 0; i < n; ++i){
    if(s[i]=='@' && se.count(t[i])!=0){
      continue;
    }
    if(t[i]=='@' && se.count(s[i])!=0){
      continue;
    }
    if(s[i]!=t[i]){
      f=false;break;
    }
  }
  string ans = "You will lose";
  if(f){
    ans = "You can win";
  }
  cout << ans << endl;
}
