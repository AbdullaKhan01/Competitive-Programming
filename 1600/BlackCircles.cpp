#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
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
/* 
for fast input output use printf and scanf;
*/
int distance(int x,int y,int x1,int y1)
{
	// distance formula d = sqrt(x-x1)^2 + (y-y1)^2)
	

	int d = (x-x1)*(x-x1) + (y-y1)*(y-y1);

	// double ans = sqrt(d);

	// a1 > a2
	// sqrt(a1) > sqrt(a2)
	// return ans;

	return d;
	// int m = sqrt(d);
	// if(m * m == d) return m;
	// return m+1;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vector<pair<int,int>>cir(n);
        for(int i=0;i<n;i++)
        {
        	cin >> cir[i].first >> cir[i].second;
        }
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;    
        // speed = 1
        int time = distance(x1,y1,x2,y2);
        bool flag = true;

        for(int i=0;i<n;i++)
        {
        	int x1 = cir[i].first;
        	int y1 = cir[i].second;

        	int t_new = distance(x1,y1,x2,y2);
        	if(t_new <= time)
        	{
        		flag = false;
        	}
        }
        cout << (flag?yes:no) << endl;
    }
    return 0;
}