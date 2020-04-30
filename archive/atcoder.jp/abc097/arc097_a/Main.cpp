#include <bits/stdc++.h>

using namespace std;
int main() {
    string s; cin >> s;
    int K; cin >> K;
    set<string> st;
    for(int i = 0; i < s.size(); ++i){
        for(int j = 1; j <= 5; ++j){
            string str;
            for(int k = 0; k < j; ++k){
                if(i + k >= s.size()) continue;
                str += s[i + k];
            }
            st.insert(str);
        }
    }
    auto itr = st.begin();
    for(int i = 0; i < K - 1; ++i) {
        ++itr;
    }
    cout << *itr << "\n";
    return 0;

}