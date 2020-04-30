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

vector<bool> isprime;
vector<int> Era(int n) {
    isprime.resize(n, true);
    vector<int> res;
    isprime[0] = false; isprime[1] = false;
    for (int i = 2; i < n; ++i) isprime[i] = true;
    for (int i = 2; i < n; ++i) {
        if (isprime[i]) {
            res.push_back(i);
            for (int j = i*2; j < n; j += i) isprime[j] = false;
        }
    }
    return res;
}

int main(){
  int n; cin >> n;
  auto p = Era(200000);
  cout << *lower_bound(p.begin(), p.end(), n) << endl;
}
