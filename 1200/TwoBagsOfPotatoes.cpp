#include <iostream>
using namespace std;
 int main(){
	int p,k,n;
	cin >>p>>k>>n;
	int a = p+ (k-p%k);

	if(a>n){
	 cout << -1 << endl;
	 }
 	else{
	while (a<=n){
 		cout << a-p << " ";
		a += k;
	}
}
 return 0;
}