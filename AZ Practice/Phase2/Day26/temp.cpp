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

int pw(int a,int p=mod-2){
	int result = 1;
	while(p>0){
		if(p&1)
			result = a*result %mod;
		a = a * a %mod;
		p >>= 1;
	}
	return result;
}

template<typename T>
class Mint
{
public:
	int val;
	Mint(int x){
		this->val = x;
	}
	// using Type = typename decay<decltype(T::val)>::type;

	Mint& operator+=(Mint other){this->val = (this->val%mod + other.val%mod)%mod; return *this;}
	Mint& operator-=(Mint other){this->val = (this->val%mod - other.val%mod)%mod; if(this->val < 0) this->val += mod;return *this;}
	Mint& operator*=(Mint other){this->val = (this->val%mod * other.val%mod)%mod;return *this;}
	Mint& operator/=(Mint other){this->val = (this->val%mod * pw(other.val))%mod;return *this;}


};

template<typename U,typename T>
U& operator<<(U&stream,const Mint<T> & num){
	return stream << num.val;
}
template <typename T> Mint<T> operator+(const Mint<T>& lhs, const Mint<T>& rhs) { return Mint<T>(lhs) += rhs; }
template <typename T, typename U> Mint<T> operator+(const Mint<T>& lhs, U rhs) { return Mint<T>(lhs) += rhs; }
template <typename T, typename U> Mint<T> operator+(U lhs, const Mint<T>& rhs) { return Mint<T>(lhs) += rhs; }
 
template <typename T> Mint<T> operator-(const Mint<T>& lhs, const Mint<T>& rhs) { return Mint<T>(lhs) -= rhs; }
template <typename T, typename U> Mint<T> operator-(const Mint<T>& lhs, U rhs) { return Mint<T>(lhs) -= rhs; }
template <typename T, typename U> Mint<T> operator-(U lhs, const Mint<T>& rhs) { return Mint<T>(lhs) -= rhs; }
 
template <typename T> Mint<T> operator*(const Mint<T>& lhs, const Mint<T>& rhs) { return Mint<T>(lhs) *= rhs; }
template <typename T, typename U> Mint<T> operator*(const Mint<T>& lhs, U rhs) { return Mint<T>(lhs) *= rhs; }
template <typename T, typename U> Mint<T> operator*(U lhs, const Mint<T>& rhs) { return Mint<T>(lhs) *= rhs; }
 
template <typename T> Mint<T> operator/(const Mint<T>& lhs, const Mint<T>& rhs) { return Mint<T>(lhs) /= rhs; }
template <typename T, typename U> Mint<T> operator/(const Mint<T>& lhs, U rhs) { return Mint<T>(lhs) /= rhs; }
template <typename T, typename U> Mint<T> operator/(U lhs, const Mint<T>& rhs) { return Mint<T>(lhs) /= rhs; }



void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	Mint<int> sum = 0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int pref = 0;
	Mint<int> k = 0;
	for(int i=0;i<n;i++)
	{
		Mint<int> later = 0;
		later += sum - pref - a[i];
		Mint<int> prev = pref;

		k += a[i] * (prev + later);
		pref += a[i];
	}
	// int l = ncr(n,2);
	Mint<int> l = (n*(n-1));
	l/=2;
	Mint<int> ans = k/(2*l);
	cout << ans << endl;
}

signed main(){	
	ll tt;
	cin >> tt;
	while(tt--)
	{
	    // solve();
	}
	Mint<int> a = 1e5;
	a*=1e5;
	// cout << a.val%mod << endl;
	cout << a << endl;
    return 0;
}