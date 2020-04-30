#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main(){
	int n; cin >> n;
	
	vector<ll> a(n);
	ll mini = INF64; ll maxi = -INF64;
	ll i1,i2;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(maxi < a[i]){maxi =a[i];i1 = i;}
		if(mini >a[i]){mini =a[i];i2=i;}
    }
    
    if(abs(maxi)>=abs(mini)){
cout << 2* n-2 << endl;
    	for(int i = 0; i < n; ++i){
    	    if(i1==i){continue;}
    	    cout << i1+1 << " " << i+1<< endl;
        }
        for(int i = 0; i < n-1; ++i){
        	cout << i+1<< " "  << i+2 << endl;
        }
     }
     else if(abs(maxi)<abs(mini)){
cout << 2* n-2 << endl;
     	for(int i = 0; i < n; ++i){
    	    if(i2==i){continue;}
    	    cout << i2+1 << " " << i+1<< endl;
        }
        for(int i = n-1; i >= 1; --i){
        	cout << i+1 << " " << i << endl;
        }
     }
     else{
     	cout << 0 << endl;
     }
    
    return 0;
}