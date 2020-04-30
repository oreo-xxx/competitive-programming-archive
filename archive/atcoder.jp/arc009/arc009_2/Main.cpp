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
  map<char, char> mp;
  for(int i = 0; i < 10; ++i){
    char c;cin >> c;
    char k = (char)i+ '0';
    mp[c ]= k;
  }
  map<string, string> mp2;
  int n;cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    string s;cin >> s;
    string t;
    for(int j = 0; j < (int)s.size(); ++j){
      t+= mp[s[j]];
    }
    mp2[t]= s;
    a[i]= stoi(t);
  }
  sort(a.begin(), a.end());
  for(int i = 0; i < n; ++i){
    string tmp = to_string(a[i]);
    cout << mp2[tmp] << endl;
  }
}
