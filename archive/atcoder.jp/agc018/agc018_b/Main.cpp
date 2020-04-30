#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	int n,m; cin >>n >> m;
	vector<vector<int> >a(n, vector<int> (m));
	for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j]; --a[i][j];
        }
    }
    set<int> se;
    
    // 参加者の最大取りたい
    // 最大m回、スポーツを選んでく
    int ans = 1000;
    for(int i = 0; i < m; ++i){
        vector<int> s(m);
        int M=0, target=-1;
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < m; ++k){
            // 削除されてないスポーツなら選ぶ
                if(se.count(a[j][k])==0){
                    s[a[j][k]]++;
                    if(M<s[a[j][k]]){M=s[a[j][k]];target=a[j][k];}
                    break;
                }
            }
        }
        ans = min(ans, M);
        
        se.insert(target);
    }
    cout << ans << endl;
    return 0;
}
