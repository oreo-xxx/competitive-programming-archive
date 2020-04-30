#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int N; cin >> N;
    int K; cin >> K;

    vector<int> as(N);
    int index = 0;
    for(int i = 0; i < N; ++i){
        int a; cin >> a;
        as[i] = a;
        if(a == 1) index = i;
    }

    int l = index;
    int r = N - index - 1;

    int ans = (N - 1) / (K - 1);
    if((N - 1) % (K - 1) != 0) ++ans;

    cout << ans << endl;

    return 0;
}