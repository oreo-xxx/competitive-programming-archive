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
  string a,b;cin >> a>> b;
  int m = b.size();
  int ab = stoi(a)* pow(10, m)+ stoi(b);
  //cout << ab << endl;
  bool ans = false;
  for(int i = 0; i < ab; ++i){
    if(i*i == ab){ans = true;break;    }
  }
  string s="No";
  if(ans)s = "Yes";
  cout << s << endl;
}
