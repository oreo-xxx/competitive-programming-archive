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
  int a,b;string s;
  cin >> a >> b >> s;
  int n = s.size();
  for(int i = 0; i < a; ++i){
    if(s[i]=='-'){
      cout << "No" << endl;
      return 0;
    }
  }
  if(s[a]!='-'){
    cout << "No" << endl;
    return 0;
  }
  for(int i = 0; i < b; ++i){
    int j = a+i+1;
    if(s[j]=='-'){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
