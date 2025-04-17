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
bool solve(string a,string b)
{
	int n = a.size();
	int z = 0 , o = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i] == '0') z++;
		else o++;
	}
	int totalFlip = 0;
	for(int i=n-1;i>=0;i--)
	{


		// cout << "Ones : " << o << " Zeroes : " << z << endl;
		// standing on the ith position of string a
		int bit = a[i] - '0';
		// if totalFlip is odd then flip the ith bit

		// else don't flip it 
		if(totalFlip % 2 == 1)
		{
			if(bit == 0)
			{
				// we will flip the bit 0 to 1
				// so cnt of zero will decrease by 1
				// and cnt of one will increase by 1
				z -= 1;
				o += 1;
			}
			else
			{
				// we will flip the bit 1 to 0
				// so cnt of zero will increase by 1
				// and cnt of one will decrease by 1
				z += 1;
				o -= 1;
			}
			bit ^= 1;
			// 1 ^ 1 = 0
			// 1 ^ 0 = 1


			// 1000101000
			// 0100101100
		}
		if(bit == (b[i]-'0'))
		{
			if(bit == 0) z--;
			else o--;
			continue;	
		} 
		else
		{

			// 000101
			// 101011
			// bit != b[i]
			// so we have to flip the prefix[0,i];

			// we have to do something here
			if(z != o)
			{
				cout << i << endl;
				return false;
			}
			if(bit == 0) z--;
			else o--;
			// to flip the prefix just make 
			// no of zeroes = no of ones
			// and make no of ones = no of zeroes
			swap(z,o);
			// and increase the totalFlip by 1
			totalFlip++;

			// now if we flipped the bit 0 

			// then decrease zero cnt by 1

			// else decrease one cnt by 1
			
		}
	}
	return true;
	// 
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        cout << (solve(a,b)?yes:no) << endl;
    }
    // 12
    // totalflip = some number = odd,even
    // 1 -> 2 , 4 , 6
    //  
	// 010101010101
	// 2 flip 
	// 101010101010
    // 010101010101

	// 6
	// 111000
	// 110100
    return 0;
}