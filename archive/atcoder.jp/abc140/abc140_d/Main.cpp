#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	int  n, k; string s;
        cin >> n >> k >> s;
	vector<ll> lr;
        if(s[0]!='L'){lr.push_back(0);}
	for(int l = 0; l < n; ++l){
		int r = l;
		for(; r < n; ++r){
			if(s[l]!=s[r]){break;}
        }
        lr.push_back(r-l);
       l = r-1;
    }
    
    int N = lr.size();
    vector<ll> sum(N+1);
    for(int i = 0; i < N; ++i){
        sum[i+1]=sum[i] + lr[i];
    }
    ll tmp = 0;
    P idx {};
    for(int i = 0; i < N+1; ++i){
    	int r = min(2*k+1+i, N);
        if(tmp<sum[r]-sum[i]){
            tmp = sum[r]-sum[i];
            idx = {i, r};
        }
    }
    
    vector<ll> a;
    for(int i = 0; i < N; ++i){
    	if(i == idx.first){
    	    a.push_back(tmp);
            i = idx.second-1;
        }
        else{
        	a.push_back(lr[i]);
        }
    }

    ll ans = 0;
    for(int i = 0; i < a.size(); ++i){
        ans+= max(0LL, a[i]-1LL);
    }
    cout << ans << endl;
    return 0;
}