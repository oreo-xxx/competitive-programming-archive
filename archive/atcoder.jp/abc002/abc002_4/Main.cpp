#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int MOD = 1000000007;

bool hasElement(const vector<int>& target, int key){
    auto itr = find(target.begin(), target.end(), key);
    if(itr != target.end()){
        return true;
    }
    return false;
}

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n, m; cin >> n >> m;
    vector<int> x(m);
    vector<int> y(m);
    map<int, vector<int> > mp;
    for(int i = 0; i < m; ++i){
        cin >> x[i] >> y[i];
        --x[i];
        --y[i];
        mp[x[i]].push_back(y[i]);
        mp[y[i]].push_back(x[i]);
    }

    int ans = 1;
    for(ll bit = 0; bit < (1 << n); ++bit){
        vector<int> vec;
        for (int i = 0; i < n; ++i) {
            if ( bit & (1<<i) ) {
                vec.push_back(i);
            }
        }
        bool flag = true;
        for (int i = 0; i < vec.size(); ++i) {
            for (int j = i + 1; j < vec.size(); ++j) {
                if (!hasElement(mp[vec[i]], vec[j])) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            ans = max(ans, (int)vec.size());
        }
    }
    cout << ans << endl;
    return 0;
}

