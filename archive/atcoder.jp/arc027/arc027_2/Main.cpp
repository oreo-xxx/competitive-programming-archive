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

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
  int n;cin >> n;
  string s1,s2;
  cin >> s1 >> s2;
  UnionFind uf(26);
  for(int i = 0; i < n; ++i){
    int c1 = s1[i]-'A';
    int c2 = s2[i]-'A';
    bool f1 = false, f2 = false;
    if(0<= c1 && c1 <= 25){
      f1 = true;
    }
    if(0<= c2 && c2 <= 25){
      f2 = true;
    }
    if(f1&&f2){
      uf.merge(c1,c2);
    }
  }
  
  for(int i = 0; i < n; ++i){
    int c1 = s1[i]-'A';
    int c2 = s2[i]-'A';
    if(0<= c1 && c1 <= 25){
      s1[i] = uf.root(c1) + 'A';
    }
    if(0<= c2 && c2 <= 25){
      s2[i] = uf.root(c2) + 'A';
    }
  }
  //cout << s1 << endl;
  //cout << s2 << endl;
  map<char, int> mp;
  for(int i = 0; i < n; ++i){
    int c1 = s1[i]-'A';
    int c2 = s2[i]-'A';
    bool f1 = false, f2 = false;
    if(0<= c1 && c1 <= 25){
      f1 = true;
    }
    if(0<= c2 && c2 <= 25){
      f2= true;
    }
    if(f1 && f2){
      if(mp.count(s1[i])==0){
        mp[s1[i]]= 10;
        if(i==0){mp[s1[i]]=11;}
      }
    }
    else if(f1){
      mp[s1[i]] = s2[i] - '0'; 
    }
    else if(f2){
      mp[s2[i]] = s1[i] - '0';
    }
  }
  string s;
  set<char> se;
  for(int i = 0; i < n; ++i){
    if(se.count(s1[i])==0){
      s += s1[i];
      se.insert(s1[i]);
    }
  }
  ll ans = 1;
  for(int i = 0; i < s.size(); ++i){
    int num = mp[s[i]];
    if(num==11){num=9;}
    else if(0<= num && num <= 9){num = 1;}
    // cout << num << endl;
    ans *= num;
  }
  cout << ans << endl;
}
