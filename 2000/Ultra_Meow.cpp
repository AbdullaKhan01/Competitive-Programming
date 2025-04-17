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
// when will 1 contribute to the answer
// -> when the size of set is 0 so size + 1 = 1
// when will 2 contribute to the answer 
// -> when the size of subset is 1 and element in subset != 1

// let b be the size of the subset
// when b == 1 -> |b| + 1  == 2; -> this says the 2nd positive 
// number not present in the set -> will contribute to answer
// then what can be the possible answers 
// -> {1} -> 3 {2} -> 3 {3} -> 2 


// when b == 2 -> |b| + 1 == 3 -> this says the 3rd positive 
// number not present in the set -> will contribute to answer

// then what can be the possible answers
// -> {1,2} -> 5 , {2,3} -> 5 , {1,3} -> 5 , {4,5} -> 3 , {3,5} -> 4 



// 4 size ke subset me max answer aur min answer kya ho
// sakta hai ? |b| + 1 = 5;

// min answer == pehle 5 me se koi bhi present na ho
// then answer = 5

// max answer == pehle 5 me se saare present ho
// then answer = 10

// so K size ke subset me 
// min answer == K + 1 jab pehle K+1 elements me se koi bhi
// present na ho

// max answer == 2*(K+1) jab saare K+1 elements present ho

// so just check for every element from K+1 to 2*(K+1)

// what is the overall TIME COMPLEXITY -> 

// there is almost n size subset 
// for every subset we do we go from K+1 to 2*(K+1)
// OVERALL TC -> N*(N+1) -> N^2

/*

	for n = 1 [1]
	// subset -> ({},1) -> 1
	          -> ({1},2) -> 3

	for n = 2 [1,2]
	// subsets -> ({},1) , ({1},2) , ({2},2) , ({1,2},3)
*/  // S({},k) ->    1   ,    3    ,    3    ,     5
/* 
for fast input output use printf and scanf;
*/
const int N = 1e6+1; 
#define PRIME mod
int fact[N],invfact[N];
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

void init(){
	int p = PRIME;
	fact[0] = 1;
	int i;
	for(i=1;i<N;i++){
		fact[i] = i * fact[i-1]%p;
	}
	i--;
	invfact[i] = pw(fact[i],p-2);
	for(i--;i>=0;i--){
		invfact[i] = invfact[i+1]*(i+1)%p;
	}

}
int ncr(int n,int r){
	if(r > n || n < 0 || r < 0) return 0;
	return fact[n] * invfact[r] % PRIME * invfact[n-r] % PRIME;
}
ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    return p;
}
ll modSub(ll a,ll b){
    ll p = (a%mod - b%mod)%mod;
    if(p<0) p+=mod;
    return p;
}
ll modMul(ll a,ll b){
    ll p = (a%mod * b%mod)%mod;
    return p;
}
signed main(){
	fast_io();
	init();
    ll tt;
    cin >> tt;
    // cout << ncr(4,0) << endl;
    while(tt--)
    {
        int n;
        cin >> n;
        int ans = 1; // for subset of size 0

        for(int k=1;k<=n;k++)
        {
        	int type = k+1;
        	cout << "For Type -> " << type << endl;
        	for(int nom=k+1;nom<=2*(k+1);nom++)
        	{
        		int numbers_before = max(1LL,nom-1);
        		int numbers_after = max(1LL,n - nom);

        		int choose1 = max(1LL,numbers_before - (type-1));

        		cout << nom << " " << numbers_before << " " << choose1 << endl;
        		cout << nom << " " << numbers_after << " " <<  k-choose1 << endl;
        		if(choose1 == 0) {cout << endl;continue;}
        		int a = ncr(numbers_before,choose1);
        		int b = ncr(numbers_after,max(1LL,k-choose1));
        		cout << a << " " << b << endl << endl;
        		ans = modAdd(ans,modMul(a,b));
        		// we will nom be considered as answer
        		// this is the type-th element 

        		// subset size is 4
        		// 5th element is 7 this means
        		// 4 elements before 7 
        		// should be not present in the set
        	}
        }
        cout << ans << '\n';
    }
    return 0;
}