#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int collatz(int n){
	if(n%2==0){return n/2;}
	return 3*n+1;
}

int main(){
	int s; cin >> s;
	vector<bool> a(1000000, false);
	a[s]= true;
	for(int i = 0; i < 1000000; ++i){
		s = collatz(s);
		if(a[s]){
			cout << i+2 << endl;
			return 0;
        }
        else{a[s]= true;}
    }
    
    return 0;
}