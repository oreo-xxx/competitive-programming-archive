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
int a,b;cin >> a >> b;
a = abs(a); b = abs(b);
string ans= "Ant";
if(b<a)ans = "Bug";
if(a==b)ans= "Draw";
cout << ans << endl;
}
