#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

bool comp(P a, P b) { return a.second < b.second; }

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
     int n, m; cin >> n >> m;
     vector<P> a(m);
     for (int i = 0; i < m; ++i){
         cin >> a[i].first >> a[i].second;
     }
     sort(a.begin(), a.end(), comp);

     int ans = 0, end = 0;
     for (int i = 0; i < m; ++i) {
         if (a[i].first >= end) {
             end = a[i].second;
             ++ans;
         }
     }
     cout << ans << endl;
}

