#include <bits/stdc++.h>

using namespace std;
int main() {
    int n; cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }
    vector<int> sorted = x;
    sort(sorted.begin(), sorted.end());
    int l = sorted[n / 2 - 1];
    int r = sorted[n / 2];

    for(int i = 0; i < n; ++i){
        if(x[i] <= l){
            cout << r << endl;
        }
        else{
            cout << l << endl;
        }
    }
    return 0;
}