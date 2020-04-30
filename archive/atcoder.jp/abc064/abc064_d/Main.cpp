#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main(){
	int n;string s; 
       cin>>n >>s;
	int m=0, M=0;
	int tmp=0;
    for(int i = 0; i < n; ++i){
    	if(s[i]=='('){++tmp;}
        else if(tmp>0){--tmp;}
        else{++m;}
    }
    string ans;
    for(int i = 0; i < m; ++i){
    	ans+='(';
    }
    ans+=s;
    for(int i = 0; i < tmp; ++i){
    	ans+=')';
    }
    cout << ans << endl;
    return 0;
}