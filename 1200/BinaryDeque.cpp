#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
int lenOfLongSubarr(vector<int> &A, int N, int K)
{
 
    int i = 0, j = 0, sum = 0;
    int maxLen = INT_MIN;
   
    while (j < N) {
        sum += A[j];  //calculation
        if (sum == K) { 
          maxLen = max(maxLen, j-i+1);     //taking results
            j++;
        }
        else if (sum < K) {    //adjusting window
            j++;
        }
        else if (sum > K) {     //adjusting window
            while (sum > K) {
                sum -= A[i];
                 i++;
            }
              if(sum == K){
              maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
    }
    return maxLen;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,s;
        cin >> n >> s;
        vi arr(n);
        input(arr);
        int p = lenOfLongSubarr(arr,n,s);
        if(p == INT_MIN){
        	cout << -1 << endl;
        }
        else cout << n-p << endl;
        // int prev = -1;
        // vi next(n,0);
        // int sum = 0;
        // bool first = true;
        // int ind;
        // for(int i=n-1;i>=0;i--){
        // 	next[i] = prev;
        // 	if(arr[i] == 1){
        // 		prev = i;
        // 		sum++;
        // 	}
        // 	if(sum == s){
        // 		if(first){
        // 			ind = i;
        // 			first = false;
        // 		}
        // 	}
        // }
        // output(next);
        // cout << endl;
        // if(first){
        // 	cout << -1 << endl;
        // }
        // else{
        // 	int maxi = ind+1;
        // 	int size = maxi;
        // 	int extra = 0;
        // 	for(int i=ind+1;i<n;i++){

        // 		if(arr[i] == 0){
        // 			size++;
        // 		}
        // 		else{

        // 		}

        // 	}
        // 	maxi = max(maxi,size);
        // 	cout << n - maxi << endl;
        // }
    }
    return 0;
}