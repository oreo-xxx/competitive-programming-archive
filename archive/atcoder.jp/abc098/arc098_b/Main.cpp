#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;
const int MOD = 1000000007;

bool hasElement(const set<int>& st, int key){
    auto itr = st.find(key);
    if(itr != st.end()){
        return true;
    }
    return false;

}

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    // しゃくとり法
    ll ans = 0;
    int right = 0;
    int sum = 0;
    for (int left = 0; left < n; ++left) {
        while (right < n && ( (sum ^ a[right]) == (sum + a[right]) )) {
            sum += a[right];
            ++right;
        }
        ans += (right - left);
        if (left == right){
            ++right;
        }
        else{
            sum -= a[left];
        }
    }

    cout << ans << endl;
}

