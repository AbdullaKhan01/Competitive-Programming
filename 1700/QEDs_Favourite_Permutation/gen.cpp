#include<bits/stdc++.h>
#define endl '\n'
using namespace std; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(){

	int n = rng() % 10 + 1; 
	int q = rng() % 10 + 1;
	cout << n << " " << q << endl;
	set<int> st;
	int idx = n;
	while(idx){
		int x = rng() % n + 1;
		if(st.count(x)) continue;
		cout << x << " ";
		st.insert(x);
		idx--; 
	}
	cout << endl;
	for(int i=0;i<n;i++){
		int f = rand() % 2;
		if(f) cout << 'R';
		else cout << 'L';
	}
	cout << endl;
	while(q--){
		int a = rng() % n + 1;
		cout << a << endl;
	}
    return 0;
}