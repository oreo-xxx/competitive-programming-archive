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
int m; cin >> m;
int n = 5;
vector<string> v;
for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
        string t; t+= s[i];
        t += s[j];
        v.push_back(t);
    }
}
sort(v.begin(), v.end());
cout << v[m-1] << endl;
}
