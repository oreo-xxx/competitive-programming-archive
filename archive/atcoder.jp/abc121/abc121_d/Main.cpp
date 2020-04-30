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
using ll = long long;
int main() {
    ll a, b; cin >> a >> b;
    ll index = a + (4 - a % 4);
    ll index2 = b - b % 4;

    ll ans = 0;
    for(ll i = a; i < index; ++i){
        ans ^= i;
    }

    for(ll i = index2; i <= b; ++i){
        ans ^= i;
    }

    cout << ans << endl;
}