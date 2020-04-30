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
    int N; cin >> N;
    if(N == 0){
        cout << 0 << endl;
        return 0;
    }

    string str = "";
    while (N != 0) {
        int r = N % 2;
        if (r < 0) r += 2;

        N = (N - r) / (-2);
        str += to_string(r);
    }
    reverse(str.begin(), str.end());
    cout << str << endl;
}