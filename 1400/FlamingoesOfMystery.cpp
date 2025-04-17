#include<bits/stdc++.h>
using namespace std; 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout << setprecision(10);

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> pref(n+1);
    int t = n-1;
    int idx = 2;
    int sum = 0;
    int total;

    cout << "? 2 " << n << endl;
    cin >> total;

    while(t--){

    	cout << "? 1 " << idx << endl;
    	int x;
    	cin >> x;
    	sum = x;
    	pref[idx++] = x;
    }
    pref[1] = sum - total; 
    for(int i=0;i<n;i++){
    	arr[i] = pref[i+1] - pref[i];
    }
    cout << "! ";
    for(auto it:arr){
    	cout << it << " ";
    } 

    return 0;
}