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
int n; cin >> n;
set<int> se;
for(int i = 0; i < n; ++i){
    int t; cin >> t;t *= -1;
    se.insert(t);
}
int i = 0;
for(auto it : se)
{
    if(i == 1){cout << -1*it << endl;}
    ++i;
}
}
