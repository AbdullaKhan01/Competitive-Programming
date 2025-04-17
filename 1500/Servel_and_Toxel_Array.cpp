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

/*
	APPROACH -> let's say the array is [1,2,3]

	and there are 2 operations 
	change idx 1 to 4 -> array becomes [4,2,3]
	change idx 2 to 5 -> array becomes [4,5,3]

	so we can just store the intervals in which every
	element appears 

	// let's say the elements appears in intervals
	[a,b],[c,d],[e,f]
	// then we can calculate the total occurence 
	of any element as a whole

	// each element would have made a pair with each
	of the remaining arrays excluding itself
	the total will be == occurence of ele * (total_arrays-1)
	
	but some of the pairs of these would be counted 
	twice and we have to remove them due to them being 
	duplicate
	these duplicates will be (freq*(freq-1)) / 2

	so for each element contribution will be
	occurence of ele * (total_arrays-1) - (freq*(freq-1)) / 2


	VERDICT -> ACCEPTED
*/
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> arr(n);
        vector<vector<int>>brr(n+m+1);
        for(int i=0;i<n;i++)
        {
        	cin >> arr[i];
        	brr[arr[i]].push_back(0);
        }
        int op = 1;
        int z = m;
        while(m--)
        {
        	int idx,val;
        	cin >> idx >> val;
        	idx--;
        	if(arr[idx] == val)
        	{
        		op++;
        		continue;
        	}
        	brr[arr[idx]].push_back(op);
        	arr[idx] = val;
        	brr[arr[idx]].push_back(op);
        	op++;
        }
        int total = 0;
        for(int i=0;i<(int)brr.size();i++)
        {
        	if(brr[i].empty()) continue;

    		if(!brr[i].empty() && brr[i].size()%2 != 0)
    		{
    			brr[i].push_back(op);
    		}
    		int freq = 0;
    		for(int j=0;j<(int)brr[i].size();j+=2)
    		{
    			int st = brr[i][j];
    			int en = brr[i][j+1];
    			freq += en - st;
    		}
    		total += freq*(z) - (freq * (freq-1))/2;
    		
        }
        cout << total << '\n';
    }
    return 0;
}