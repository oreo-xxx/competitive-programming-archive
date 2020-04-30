#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

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
	vector<int> primes = Era(55556);
	vector<int> primes_1;
	for(int i = 0; i < primes.size(); ++i){
		  if(primes[i]%5==1) primes_1.push_back(primes[i]);
    }
    int n; cin >>n;
    for(int i = 0; i < n; ++i){
    	  cout << primes_1[i] << endl;
    }
    return 0;
}