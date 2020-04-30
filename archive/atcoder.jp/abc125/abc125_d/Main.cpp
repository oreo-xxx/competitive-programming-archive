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
    vector<long long> vec(n);
    long long ans = 0;
    long long minnum = 1LL << 60;
    int count = 0;
    for(int i = 0; i < n; ++i){
        long long a; cin >>a;
        if(a < 0){
            a = abs(a);
            ++count;
        }
        ans += a;
        minnum = min(minnum, a);
    }
    if(count % 2 != 0){
        ans -= 2 * minnum;
    }

    cout << ans << endl;
}