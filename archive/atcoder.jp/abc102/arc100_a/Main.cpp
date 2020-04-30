#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include <cmath>
#include <climits>
#include <queue>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i){
        int a; cin >>vec[i];
        vec[i] -= (i + 1);
    }
    sort(vec.begin(), vec.end());

    int median = vec[n/2];
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        ans += abs(vec[i] - median);
    }

    cout << ans << endl;
}