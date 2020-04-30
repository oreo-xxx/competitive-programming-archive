#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main(){
	vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    int num=0, ans =0;
    for(int i = 0; i < 3; ++i){
if(a[i]%2==1){++num;}
}
if(num==1){++ans;
    for(int i = 0; i < 3; ++i){
if(a[i]%2==1){--a[i];}
}
}
if(num==2){++ans;
for(int i = 0; i < 3; ++i){
if(a[i]% 2==0){--a[i];}
}
}

    ans += (a[2]-a[0])/2;
    
    ans += (a[2]-a[1])/2;
    
	cout << ans << endl;
    return 0;
}