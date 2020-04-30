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
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int tmp; cin >> tmp;
        ans += tmp;
    }
    ans -= n;
    cout << ans << endl;
}