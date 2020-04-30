#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


void dfs(const vector<vector<ll> >& g, vector<ll>& dist, ll k, ll sum){
        if(dist[k]!=-1){return;}
	dist[k]=sum;
	for(auto i : g[k]){
		dfs(g, dist, i , sum+1);
    }
}


int main(){
	int n; cin >> n;
	vector<vector<ll> >g(n);
	for(int i = 0; i < n-1; ++i){
		ll a,b; cin >>a >>b;
--a, --b;
                g[a].push_back(b);
		g[b].push_back(a);
    }
    
    vector<ll> dist1(n, -1), distn(n, -1);
    dfs(g, dist1, 0, 0);
    dfs(g, distn, n-1, 0);
   ll sum=0;
    for(int i = 0; i <n; ++i){
    	if(dist1[i] > distn[i]){++sum;}
    }
    if(sum>=n-sum){
    	cout << "Snuke" << endl;
}
else{
	cout << "Fennec" << endl;
}
    return 0;
}
