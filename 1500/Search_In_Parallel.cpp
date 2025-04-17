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
bool comp(pair<int,int>&a,pair<int,int>&b)
{
	if(a.first == b.first) return a.second > b.second;
	return (a.first > b.first);

}

/*

INTUITION -> 

	JUST GREEDY PUT THE BALLS IN THAT LIST WHICH WILL
	TAKE THE MIN TIME IN PROCESSING THE BALLS PREVIOUS
	TO THIS BALL AND THEN PROCESS THIS BALL ALSO IN THE
	MIN POSSIBLE TIME
*/
// VERDICT => ACCEPTED
signed main(){
	fast_io();
    int tt;
    cin >> tt;
    while(tt--)
    {
    	int n,s1,s2;
    	cin >> n >> s1 >> s2;
    	vector<pair<int,int>>a(n+1,{0,0});
    	for(int i=1;i<=n;i++)
    	{
    		cin >> a[i].first;
    		a[i].second = i;
    	}
    	sort(all(a),comp);
    	vector<int> x,y;
    	int sumx=0,sumy=0;
    	for(int i=0;i<n;i++)
    	{
    		int count = a[i].first;
    		int timefirst = (sumx + s1)*count;
    		int timesecond = (sumy + s2)*count;
    		if(timefirst == timesecond)
    		{
    			if(x.size() < y.size())
    			{
    				sumx += s1;
    				x.push_back(a[i].second);
    			}
    			else
	    		{
	    			sumy+=s2;
	    			y.push_back(a[i].second);
	    		}
    		}
    		else if(timefirst < timesecond)
    		{
    			sumx += s1;
    			x.push_back(a[i].second);
    		}
    		else
    		{
    			sumy+=s2;
    			y.push_back(a[i].second);
    		}
    	}
    	cout << x.size() << " \n"[x.size()==0];
    	for(int i=0;i<(int)x.size();i++)
    	{
    		cout << x[i] << " \n"[i+1==(int)x.size()];
    	}
    	cout << y.size() << " \n"[y.size()==0];
    	for(int i=0;i<(int)y.size();i++)
    	{
    		cout << y[i] << " \n"[i+1==(int)y.size()];
    	}

    }
    return 0;
}