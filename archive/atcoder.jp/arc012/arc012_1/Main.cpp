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
  map<string , int> mp;
  mp["Sunday"]=0;
  mp["Saturday"]=0;
  mp["Monday"]=5;
  mp["Tuesday"]=4;
  mp["Wednesday"]=3;
  mp["Thursday"]=2;
  mp["Friday"]=1;
  string s;cin >> s;
  cout << mp[s] << endl;
}
