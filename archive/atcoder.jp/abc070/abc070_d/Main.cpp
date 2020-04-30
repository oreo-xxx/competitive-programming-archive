#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


void dfs(const vector<vector<P> >& g, vector<ll>& dist, ll k, ll sum){
        if(dist[k]!=-1){return;}
	dist[k]=sum;
	for(auto i : g[k]){
		dfs(g, dist, i.first , sum+i.second);
    }
}


int main(){
	int n; cin >> n;
	vector<vector<P> >g(n);
	for(int i = 0; i < n-1; ++i){
		ll a,b,c; cin >>a >>b>>c;
--a, --b;
                g[a].push_back({b,c});
		g[b].push_back({a,c});
    }
    
    ll q,k; cin >>q>>k; --k;
    vector<ll> dist(n, -1);
    dfs(g, dist, k, 0);
   
    for(int i = 0; i < q; ++i){
    	ll x,y;cin >>x>> y;
--x, --y;
        cout << dist[x]+dist[y] << endl;
    }
    return 0;
}
