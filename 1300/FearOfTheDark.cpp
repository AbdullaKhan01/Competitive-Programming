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
bool possible(int ax,int ay,int px,int py,int bx,int by,double r){
	double AtoP = sqrt(pow(ax-px,2) + pow(ay-py,2));
    double BtoP = sqrt(pow(bx-px,2) + pow(by-py,2));
    double AtoB = sqrt(pow(ax-bx,2) + pow(ay-by,2));
    double AtoO = sqrt(pow(ax,2) + pow(ay,2));
    double BtoO = sqrt(pow(bx,2) + pow(by,2));

    // cout << r << "->" << endl;
    // cout << AtoP << " " << BtoP << " " << AtoB << " " << AtoO<<" "<<BtoO<<endl;
    if(AtoP <= r){
    	if(AtoO <= r || (AtoB <= 2*r && BtoO<=r)){
    		// cout << "true2"<<endl;
    		return true;	
    	} 
    }
    else if(BtoP <= r){
    	// cout << "here2" << endl;
    	if(BtoO <= r || (AtoB <= 2*r && AtoO <= r)){
    		// cout << "true" << endl;
    		return true;	
    	} 
    }
    // cout << "false" << endl;
    return false;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        double px,py;
        cin >> px >> py;
        double ax,ay;
        cin >> ax >> ay;
        double bx,by;
        cin >> bx >> by;
        double dis1 = sqrt(pow(ax-px,2) + pow(ay-py,2));
        double dis2 = sqrt(pow(bx-px,2) + pow(by-py,2));
        double AtoO = sqrt(pow(ax,2) + pow(ay,2));
    	double BtoO = sqrt(pow(bx,2) + pow(by,2));
        // cout << dis1 << " " << dis2 << endl;
        double s = 0.00000000 , e = max({dis1,dis2,AtoO,BtoO});
        double ans = e;
        cout << fixed << setprecision(10);
        while(s<=e){
        	double mid = ((s + e)/2);
        	if(possible(ax,ay,px,py,bx,by,mid)){
        		ans = mid;
        		e = mid-0.0000000001;
        	}
        	else{
        		s = mid+0.0000000001;
        	}
        }
        cout << ans << '\n';
    }
    return 0;
}