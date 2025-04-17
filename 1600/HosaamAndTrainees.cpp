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

/* APPROACH -> if there are more than 2 even numbers then answer
is yes


// if even number == 1 && that num % any odd number == 0
// then answer == YES

// now we have no even number or only 1 even number
// then does not needs to be checked

// so now basically we have bunch of odd numbers and we
// have to check if any two of them have hcf >= 2

// in sqrtN we can tell the smallest number which 
// divides a particular number -> but is it of any use ? NO

//  21 49
// 21 = 3 * 5 * 7 
// 49 = 5 * 7 * 9
// 

does prime factorization of a number give some hint
prime factorization of a number is obtained in (NO USE)


let's try reverse psycology

// lets say there are 4 odd numbers
// a b c d 

and there exists some number x which is divides 
2 numbers from the set of 4 odd numbers

// then what observation can we infer ?? 

-> a%x == b%x == 0
x is smaller than min(a,b)

since a and b are odd numbers a/x and b/x both are odd

if -> a%x == b%x == 0 is true
then lcm(a,b) < a*b 

6 9 divided by 3
6/3 = 2  || 9/3 = 3

LCM = 6*(9/3) == 9*(6/3)


now we have <= 1 even number and some odd numbers

*/

int N = 1e9 + 7;
int K = 2e5 + 100;
vector<bool> is_prime(K+1, true);
vector<int> primes;
void init(){
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= N; i++) {
	    if (is_prime[i]) {
	    	primes.push_back(i);
	        for (int j = i * i; j <= K; j += i)
	            is_prime[j] = false;
	    }
	}
}

signed main(){
	fast_io();
	init();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
        	cin >> a[i];
        }
        // we have 3401 prime numbers

        // we can find all prime numbers <= sqrt(A)
        // then check if any prime number divides
        // both 2 numbers then ans is yes else no
        set<int> st;
        bool flag = false;
        for(int i=0;i<n;i++)
        {
        	int t = a[i];
        	for(int j=0;j<(int)primes.size();j++)
        	{
        		if(primes[j] > t) break;
        		int pp = primes[j];
        		if(t % pp == 0)
        		{
        			if(st.find(pp) != st.end())
        			{
        				flag = true;
        				break;
        			}
        			while(t % pp == 0) t/=pp;
        			st.insert(pp);
        		}
        	}
        	if(t != 1)
        	{
        		if(st.find(t) != st.end())
        		{
        			flag = true;
        		}
        		else st.insert(t);
        	}
        	if(flag == true) break;
        }
    	cout << (flag?yes:no) << endl;
    }
    return 0;
}





// #include <bits/stdc++.h>

// using namespace std;

// const int N = 1e5 + 5, M = 2 * N + 5;

// bool vis[N], ans;

// void Sieve(){
//     memset(vis, true, sizeof(vis));
    
//     vis[0] = vis[1] = false;
//     for(int i = 4 ; i < N ; i += 2)
//         vis[i] = false;
//     for(int i = 3 ; i < N / i ; i += 2){
//         if(!vis[i])continue;
//         for(int j = i * i ; j < N ; j += i + i)
//             vis[j] = false;
//     }
// }

// int in[N], vid;
// vector<int> primes;

// void Gen(){
//     for(int i = 2 ; i < N ; ++i)
//         if(vis[i])
//             primes.emplace_back(i);
// }

// set<int> st;

// void check(int x){
//     if(in[x] == vid){
//         ans = true;
//         return;
//     }

//     in[x] = vid;
// }

// void fact(int x){

//     if(x < N && vis[x] == true){
//         check(x);
//         return;
//     }

//     int idx = 0, sz = primes.size();

//     while(x > 1 && idx < sz && x / primes[idx] >= primes[idx]){

//         if(x % primes[idx] == 0){
//             check(primes[idx]);
//             while(x % primes[idx] == 0)x /= primes[idx];
//         }

//         ++idx;
//     }

//     if(x > 1){
//         if(x < N)
//             return check(x), void();

//         if(st.find(x) != st.end()){
//             ans = true;
//             return;
//         }

//         st.emplace(x);
//     }
// }

// void pre(){
//     ++vid;
//     st.clear();
// }

// int main(){
//     Sieve();
//     Gen();

//     int t;
//     scanf("%d", &t);
//     while(t--){
//         pre();
        
//         int n;
//         scanf("%d", &n);
        
//         ans = false;
        
//         while(n--){
//             int x;
//             scanf("%d", &x);
//             fact(x);
//         }
        
//         puts(ans ? "YES" : "NO");
//     }
    
// }