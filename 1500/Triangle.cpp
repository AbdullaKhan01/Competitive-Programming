#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define ll long long
#define int long long
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define rep(i,a,n) for(int i=(a);i<n;i++)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define si set<int>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define yes "YES"
#define no "NO"
#define endl '\n'
using namespace std; 
bool isRight(int x1,int y1,int x2,int y2,int x3,int y3){

	if((x1==x2 && y1!=y2 && y1==y3) || (x1==x3 && y1!=y3 && y1==y2) ||
     (x2==x3 && y2!=y3 && y2==y1)){
    	return true;
    }
    else return false;

}
signed main(){
	
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(isRight(x1,y1,x2,y2,x3,y3)){
    	cout << "RIGHT" << endl;
    }
    // else{
    // 	if(isRight())
    // }

    return 0;
}