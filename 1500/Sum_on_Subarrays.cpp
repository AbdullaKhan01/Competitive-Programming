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
 // a b c d e f g
// 
// let's say the array is
// -1 -2 -3 -4
// so till now we 10 subarrays with negative sum

// now the next number which will be coming will be 
// contributing for the next 5 subarray sums 
// lets say we want to make the next 2 subarray negative 
// and remaining 3 positive then what can we do ? 

// the number will make the subarray like
// x , -4 x , -3 -4 x , -2 -3 -4 x , -1 -2 -3 -4 x
//

// 2 3 4 -8 _ 
//first of all the number should be positive
// now which 2 can we make negative 5

// VERDICT -> ACCEPTED

signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,k;
        cin >> n >> k;
        int no_of_sub = ((n)*(n+1))/2;
        int positive = k;
        int negative = no_of_sub - positive;
        vector<int> arr(n,0);
        int st = -2;
        int i=0;
        for(;i<n;i++)
        {
            int now_sub = i+1;
            if(now_sub <= negative)
            {
                negative -= now_sub;
                arr[i] = st;
                st--;
            }
            else break;
        }
        int sum = 0;
        int x = i+1 - negative;
        int j = i;
        while(x--)
        {
            sum += abs(arr[j--]);
        }
        if(negative != 0) arr[i++] = sum+1;
        while(i < n)
        {
            arr[i++] = 1000;
        }
        
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " \n"[i+1==n];
        }       
    }
    return 0;
}