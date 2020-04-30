#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string sorted = s;

    // 辞書順最小
    sort(sorted.begin(), sorted.end());

    string ans;
    string nokori = sorted;

    int total_count = 0;
    for(int i = 0; i < n; ++i){

        for(int j = 0; j < nokori.size(); ++j){
            string tmp = nokori;
            char c = tmp[j];
            tmp.erase(tmp.begin() + j);

            int count = 0;
            if(s[i] != c){
                ++total_count;
            }

            map<char, int>mp;
            for(int k = 0; k < tmp.size(); ++k){
                ++mp[s[i + 1 + k]];
            }

            for(int k = 0; k < tmp.size(); ++k){
                if(mp.count(tmp[k]) != 0){
                    --mp[tmp[k]];
                }
            }
            for(auto itr : mp){
                count += max(itr.second, 0);
            }

            if(total_count + count <= k){
                ans.push_back(c);
                nokori.erase(nokori.begin() + j);
                break;
            }
            else{
                --total_count;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

