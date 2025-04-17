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
Approach -> lets say the total no of ones = x
// since the condition is given that
// every array has same no of ones
// let's say every array has y ones

so total no of ones = x = n * y
// y = x/n

if y is not an integer then answer is not 
possible otherwise 

I guess answer is always possible

3 4
1 1 1 0
0 0 1 0
1 0 0 1

total no of ones = 6
6/3 = 2

so answer is possible

1 1 0
0 0 1 
1 1 1 1



// VERDICT -> ACCEPTED
*/
void solve()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>>arr(n,vector<int>(m));
	int cnt = 0;
	vector<int> oneCnt(n,0);
	for(int i=0;i<n;i++)
	{
		rep(j,0,m)
		{
			cin >> arr[i][j];
			// be careful for string input
			if(arr[i][j])
				oneCnt[i]++;
		}
		cnt += oneCnt[i];
	}
	if(cnt % n)
	{
		// answer no possible
		cout << -1 << endl;
		return ;
	}
	else
	{
		// answer is possible
		// no of 1's in all arrays = cnt/n;
		// just greedily swap the ones

		// condition for swap
		// stand on the 0 of the array which
		// requires a 1 suppose the index is X

		// find some array which has 1 in the
		// Xth index and just swap them
		// and increase and decrese the 1 cnt

		// now the question is how to find
		// this array quickly ???

		// got it -> go for every column


		int y = cnt / n;

		// y = 5
		// cout << y << endl;
		vector<vector<int>>ans;
		for(int i=0;i<m;i++)
		{
			vector<int> temp;
			for(int j=0;j<n;j++)
			{
				if(oneCnt[j] > y && arr[j][i] == 1)
				{
					temp.push_back(j);
				}
			}
			for(int j=0;j<n;j++)
			{
				if(oneCnt[j] < y)
				{
					// this row needs an ans
					if(arr[j][i] == 1) continue;

					// arr[j][i] = 0;

					// this cell needs a 1
					if(!temp.empty())
					{
						// then swap can be possible

						int arr2 = temp.back();
						temp.pop_back();
						int arr1 = j;

						// swap the ith position of arr2 and arr1

						swap(arr[arr2][i],arr[arr1][i]);
						ans.push_back({arr1+1,arr2+1,i+1});
						oneCnt[arr2]--;
						oneCnt[arr1]++;
					}
				}
			}
		}
		// we would have found the answer
		cout << ans.size() << "\n";
		for(vector<int> brr:ans)
		{
			for(auto it:brr)
			{
				cout << it << " ";
			}
			cout << "\n";
		}
	}
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}
/*


*/