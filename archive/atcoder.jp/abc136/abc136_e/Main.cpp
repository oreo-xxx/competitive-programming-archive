#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

/// Lib
vector<long long> calc_divisor(long long n) {
    vector<long long> res;
    for (long long i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            long long j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
///
bool check(ll key, const vector<ll>& vec, ll maxtry){
    vector<ll> distance(vec.size());
    for(ll i = 0; i < vec.size(); ++i){
        distance[i] = vec[i] % key;
    }
    sort(distance.begin(), distance.end());

    ll cost = 0;
    ll last = vec.size()-1;
    for(ll i = 0; i < vec.size(); ++i){
        if(distance[i] == 0) continue;
        cost += distance[i];
        distance[last] += distance[i];

        bool flag = true;
        while(flag){
            if(distance[last] >= key){
                ll res = distance[last] - key;
                distance[last] = 0;
                --last;
                distance[last] += res;
            }
            else{
                flag = false;
            }
        }
    }

    if(cost <= maxtry){
        return true;
    }
    return false;
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }
    ll sum = 0;
    for(ll i = 0; i < n; ++i){
        sum += a[i];
    }
    vector<ll> div = calc_divisor(sum);
    ll ans = 0;
    for(auto it : div){
        if(check(it, a, k)){
            ans = max(ans, it);
        }
    }
    cout << ans << endl;
    return 0;
}
