#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<unordered_map>
#include<climits>
using namespace std;

const int INF = 1000000000;
int N;
int A;
int B;
int C;
vector<int> ls {};

int dfs(int cur, int a, int b, int c){
    if(cur == N){
        if(a > 0 && b > 0 && c > 0){
            return abs(a - A) + abs(b - B) + abs(c - C) - 30;
        }
        else{
            return INF;
        }
    }
    int ret0 = dfs(cur + 1, a, b, c);
    int ret1 = dfs(cur + 1, a + ls[cur], b, c) + 10;
    int ret2 = dfs(cur + 1, a, b + ls[cur], c) + 10;
    int ret3 = dfs(cur + 1, a, b, c + ls[cur]) + 10;
    int min1 = min(ret0, ret1);
    int min2 = min(ret2, ret3);
    return min(min1, min2);
}

int main()
{
    cin >> N;
    cin >> A;
    cin >> B;
    cin >> C;
    for(int i = 0; i < N; ++i){
        int tmp; cin >> tmp;
        ls.push_back(tmp);
    }

    cout << dfs(0,0,0,0) << endl;
    return 0;
}

