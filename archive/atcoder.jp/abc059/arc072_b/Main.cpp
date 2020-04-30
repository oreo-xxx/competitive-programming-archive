#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main(){
	ll x,y; cin >> x >> y;

    if(abs(x-y)>1){
        cout << "Alice" << endl;
    }
    else{
    	cout << "Brown" << endl;
    }
    return 0;
}