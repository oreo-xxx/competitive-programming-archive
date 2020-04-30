#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> easter(n + 1);
    vector<int> wester(n + 1);
    for(int i = 1; i < n + 1; ++i){
        if(s[i - 1] == 'W') wester[i] = wester[i - 1] + 1;
        else wester[i] = wester[i - 1];
    }
    for(int i = n - 1; i >= 0; --i) {
        if (s[i] == 'E') easter[i] = easter[i + 1] + 1;
        else easter[i] = easter[i + 1];
    }
    int ans = 1 << 29;
    for(int i = 0; i < n; ++i){
        int wronger = wester[i] + easter[i + 1];
        ans = min(ans, wronger);
    }

    cout << ans  << endl;
    return 0;

}