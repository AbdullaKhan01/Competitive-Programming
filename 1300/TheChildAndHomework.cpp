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
signed main(){
	
    string a1,b1,c1,d1;
    cin >> a1 >> b1 >> c1 >> d1;
    int a = a1.size()-2;
    int b = b1.size()-2;
    int c = c1.size()-2;
    int d = d1.size()-2;
    // cout << a << b << c << d << endl;
    int at=0,bt=0,ct=0,dt=0;
    if(a>=2*b && a>=2*c && a>=2*d){
    	at=1;
    }
    else if(b>=2*a && b>=2*c && b>=2*d){
    	bt=1;
    }
    else if(c>=2*a && c>=2*b && c>=2*d){
    	ct=1;
    }
    else if(d>=2*a && d>=2*b && d>=2*c){
    	dt=1;
    }
    if(a<=b/2 && a<=c/2 && a<=d/2){
    	at=1;
    }
    else if(b<=a/2 && b<=c/2 && b<=d/2){
    	bt=1;
    }
    else if(c<=a/2 && c<=b/2 && c<=d/2){
    	ct = 1;
    }
    else if(d<=a/2 && d<=b/2 && d<=c/2){
    	dt=1;
    }
    // cout << at << bt << ct << dt << endl;
    if(at ==1 && bt+ct+dt==0){
    	cout << "A" << endl;
    }
    else if(bt == 1 && at+ct+dt == 0){
    	cout << "B" << endl;
    }
    else if(dt == 1 && at+bt+ct == 0){
    	cout << "D" << endl;
    }
    else{
    	cout << "C" << endl;
    }

    return 0;
}