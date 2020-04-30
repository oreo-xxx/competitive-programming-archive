#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,  ll>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	int sx, sy, tx, ty;
    cin >> sx >>  sy >> tx >> ty;
    char fx, bx, fy, by;
    if(sx <tx){fx='R';bx='L';}
    else{fx='L';bx='R'; swap(sx, tx);}
    if(sy < ty){fy='U';by='D';}
    else{fy='D';by='U';swap(sy,ty);}

    for(int i = 0; i < ty-sy; ++i){
    	cout << fy;
    }
    for(int j = 0; j < tx-sx; ++j){
    	cout << fx;
    }
    for(int i = 0; i < ty-sy; ++i){
    	cout << by;
    }
    for(int j = 0; j < tx-sx; ++j){
    	cout << bx;
    }
    
    cout << bx;
    for(int i = 0; i < ty-sy+1; ++i){
    	cout << fy;
    }
    for(int j = 0; j < tx-sx+1; ++j){
    	cout << fx;
    }
    cout << by;
    cout << fx;
    for(int i = 0; i < ty-sy+1; ++i){
    	cout << by;
    }
    for(int j = 0; j < tx-sx+1; ++j){
    	cout << bx;
    }
    cout << fy << endl;
}