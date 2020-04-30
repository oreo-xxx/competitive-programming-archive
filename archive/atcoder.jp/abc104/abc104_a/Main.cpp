#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	int n; cin >>n;
	string ans;
	if(n<1200){ans="ABC";}
    else if(n<2800){ans="ARC";}
    else{ans="AGC";}
	cout << ans << endl;
    return 0;
}
