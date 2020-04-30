#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

vector<int> buf;

int seeds[] = {3, 5, 7};
int N;
int size_;
int ans;
bool endflag = true;

int convert(){
    bool exist3 = false;
    bool exist5 = false;
    bool exist7 = false;
    int ret = 0;
    for(int i = 0; i < size_; ++i){
        if(buf[i] == 3) exist3 = true;
        else if(buf[i] == 5) exist5 = true;
        else if(buf[i] == 7) exist7 = true;
        else return -1;
        ret += buf[i] * pow(10, size_ - i - 1); 
    }
    if(exist3 && exist5 && exist7) return ret;
    else return -1;
}

void dfs(int i)
{
    if (i == size_) {
        int tmp = convert();
        if(tmp == -1){
            return;
        }
        else if(0 < tmp && tmp <= N){
            ++ans;
        }
        else{
            endflag = false;
            return;
        }
    }
    else{
        for(int j = 0; j < 3; ++j){
            buf[i] = seeds[j];
            dfs(i + 1);
        }
    }
}

int main(void)
{
    cin >> N; 
    buf.resize(20);
    for(int s = 3; endflag == true; ++s){
        size_ = s;
        dfs(0);
    }
    cout << ans << endl;
    return 0;
}