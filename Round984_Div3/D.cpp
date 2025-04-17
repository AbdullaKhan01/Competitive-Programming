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
void solve()
{
	int n,m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		// output(a[i]);
	}	
	vector<string> temp;
        
    int row=a.size();
    int col=a[0].size();
    int count=0;
    int total=row*col;
    
    // index
    int startingRow=0;
    int startingCol=0;
    int endingRow=row-1;
    int endingCol=col-1;
    while(count<total){
    	string ans = "";
        //print starting row
        for(int index=startingCol; count<total && index<=endingCol;index++){
                ans.push_back(a[startingRow][index]);
                count++;
        }
        startingRow++;
        //print ending col
        for(int index=startingRow; count<total && index<=endingRow;index++){
           ans.push_back(a[index][endingCol]);
           count++; 
        }
        endingCol--;
        //print ending row
        for(int index=endingCol; count<total && index>=startingCol;index--){
           ans.push_back(a[endingRow][index]);
           count++; 
        }
        endingRow--;
        //print starting column
        for(int index=endingRow; count<total && index>=startingRow;index--){
           ans.push_back(a[index][startingCol]);
           count++; 
        }
        startingCol++;
        temp.push_back(ans);
    }
    int cnt = 0;
    for(auto it:temp)
    {
    	// cout << it << endl;
    	int n = it.size();
    	string t = it+it+it+it;
    	for(int i=0;i<n;i++)
    	{
    		string g = t.substr(i,4);
    		if(g == "1543") cnt++;
    	}
    }
    cout << cnt << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}