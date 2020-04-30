#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

long long calc_divisor(long long n) {
    long long res =0;
    for (long long i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res+=i;
            long long j = n / i;
            if (j != i) res+=j;
        }
    }
    res-=n;
    return res;
}

int main() {
	ll  n;cin >>n;
	ll sum =calc_divisor(n);
	string ans="Perfect";
	if(n>sum)ans="Deficient";
	if(n<sum)ans="Abundant";
    cout << ans << endl;
}
