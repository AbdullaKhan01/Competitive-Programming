// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// const int N = 100100;
// int freq[N];
// int dp[N][2];
// signed main(){
// 	fast_io();
//     int n;
//     cin >> n;
//     for(int i=0;i<n;i++)
//     {
//     	int x;
//     	cin >> x;
//     	freq[x]++;
//     }
//     int ans = 0;
//     for(int i=N-2;i>=1;i--)
//     {
//     	dp[i][1] = i*freq[i] + dp[i+1][0];
//     	dp[i][0] = max(dp[i+1][0],dp[i+1][1]);
//     	ans = max({ans,dp[i][0],dp[i][1]});
//     }
//     cout << ans << endl;
//     return 0;
// }

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
write the num - sumofDigit sequence
// it will become a sequence of table
of 9 appearing exactly 9 times for 
each digit which means it is increasing
and then go on from there.
*/
int sumofDigits(int n)
{
    int sum = 0;
    while(n!=0)
    {
        sum += n%10;
        n/=10;
    }
    return sum;
}
int correct(int n,int s){
	
    int l=1,h=n;
    int ans = n+1;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(mid-sumofDigits(mid)>=s)
        {
            ans = mid;
            h = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return n-ans+1;
}
int solve(int n,int s) {

	auto sumofDigits = [&](int n)
	{
	    int sum = 0;
	    while(n!=0)
	    {
	        sum += n%10;
	        n/=10;
	    }
	    return sum;
	};
    auto ok = [&](int mid) {
        return mid-sumofDigits(mid)>=s;
    };

    int lo = 0,hi = 1e18 ,ans = 0;

    while(lo<=hi) {
        int mid = (lo+hi)/2;

        if(ok(mid)) {
            ans = mid;
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }

    // cout<<n<<" "<<ans<<endl;
    cout << ans << endl;
    int lb = ans*10;
    if(lb==0) {
        lb = 1;
    } 

    if(n>=lb) {
        return n-lb+1;
    }
    else {
        return 0;
    }
}
void test(){
	srand(time(NULL));
	int cnt = 1;
	int MAX = 1e3;
	while(cnt <= MAX){
		int n = rand() % 1000 + 1;
		int s = rand() % 500 + 1;
		// int arr[n];
		// for(int i=0;i<n;i++){
		// 	arr[i] = rand() % 1000 + 1;
		// }
		int correctAns = correct(n,s);
		int myAns = solve(n,s);
		if(correctAns != myAns){
			cout << correctAns << " " << myAns << endl;
			cout << n << " " << s << endl;
			break;
		}
		cnt++;
	}
}
signed main(){
    // test();
    int n = 628 , s = 427 ;
    // int l = 628 - 188;
    // cout << l << endl;
    // cout << l - sumofDigits(l) << endl;
    // int n = 56 , s = 35;
    cout << solve(n,s) << endl;
    // cout << correct(n,s);
    return 0;
}