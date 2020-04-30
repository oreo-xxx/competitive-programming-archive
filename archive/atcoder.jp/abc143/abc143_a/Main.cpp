#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	int n, k;
	cin >> n >> k;
	cout << max(n-2* k, 0) << endl;
    return 0;
}
