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
  string s;
  vector<string> a;
  while(cin >> s){
    a.push_back(s);
  }
  int n = a.size();
  for(int i = 0; i < n; ++i){
    if(a[i]=="Left"){
      cout << "<";
    }
    else if(a[i]=="Right"){
      cout << ">";
    }
    else{
      cout << "A";
    }
    if(i!=n-1){
      cout << ' ';
    }
    else{
      cout << endl;
    }
  }
}
