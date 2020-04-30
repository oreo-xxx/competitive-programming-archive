#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, uint>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;
bool comp(pair<int, P> a, pair<int, P> b) {
    if(a.second.second != b.second.second){
        return a.second.second < b.second.second;
    }
    else{
        return a.first < b.first;
    }
}

void solve(){
    int N, M, Q; cin >> N >> M >> Q;
    vector< pair<int, P> > vec(M + Q);
    for(int i = 0; i < M; ++i){
        int L, R; cin >> L >> R;
        vec[i] = {0, {L, R}};
    }
    for(int i = 0; i < Q; ++i){
        int L, R; cin >> L >> R;
        vec[M + i] = {i + 1, {L, R}};
    }
    stable_sort(vec.begin(), vec.end(), comp);


    vector<int> arr(510, 0);
    vector<int> ans_arr(Q, 0);
    for(int i = 0; i < M + Q; ++i){
        int type = vec[i].first;
        if(type == 0){
            ++arr[vec[i].second.first];
        }
        else{
            int ans = 0;
            for(int j = vec[i].second.first; j <= vec[i].second.second; ++j){
                ans += arr[j];
            }
            ans_arr[type-1] = ans;
        }
    }
    for(int i = 0; i < Q; ++i){
        cout << ans_arr[i] << '\n';
    }

    return;
}





int main() {
    #ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
    #else

    solve();

    #endif
    return 0;
}

