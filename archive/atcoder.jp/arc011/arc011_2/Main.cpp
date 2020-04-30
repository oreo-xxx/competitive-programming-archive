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

char tolowr(char c) {
  if ((c >= 'A') && (c <= 'Z')) {
    return (c + 0x20);
  } else {
    return (c);
  }
}

int main() {
  map<char,char> mp{
    {'b','1'},{'c','1'},
    {'d','2'},{'w','2'},
    {'t','3'},{'j','3'},
    {'f','4'},{'q','4'},
    {'l','5'},{'v','5'},
    {'s','6'},{'x','6'},
    {'p','7'},{'m','7'},
    {'h','8'},{'k','8'},
    {'n','9'},{'g','9'},
    {'z','0'},{'r','0'},
    {'a','a'},{'i','a'},{'u','a'},
    {'e','a'},{'o','a'},{'y','a'}
  };
  int n;cin >>n;
  vector<string > a(n);
  for(int i = 0; i < n; ++i)cin >>a[i];
  
  vector<string> ans;
  for(int i = 0; i < n; ++i){
    string tmp;
    string s = a[i];
    for(int j = 0; j < s.size(); ++j){
      if(s[j]=='.'|| s[j]==','){continue;}
      char c = mp[ tolowr(s[j]) ];
      if(c=='a'){continue;}
      tmp+=c;
    }
    if(tmp==""){continue;}
    ans.push_back(tmp);
  }
  for(int i = 0; i<(int)ans.size(); ++i){
    cout << ans[i];
    if(i != (int)ans.size() - 1){
         cout << " ";
     }
  }
  cout << endl;
}
