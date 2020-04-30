#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

bool check(ll n, ll m){
	if(2*n > m || m > 4* n){return false;}
	ll rem = m - 3 * n;
	if(rem < 0){
		cout <<-1*  rem  <<" " << n + rem << " " << 0 << endl;
    }
    else{
        cout << 0 <<" " << n - rem << " " << rem << endl;
    }
}

int main(){
	ll n,m; cin >>n >> m;
	if(!check(n,m)){
        cout << -1 << " " << -1 << " " <<-1 << endl;
    }
    return 0;
}
