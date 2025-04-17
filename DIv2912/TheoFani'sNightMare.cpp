#include<bits/stdc++.h>
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 
int solve(vll &nums,int index,int arrno){
    if(index>=nums.size()){
        return 0;
    }
    int op1 = arrno * nums[index] + solve(nums,index+1,arrno);
    int op2 = (arrno+1) * nums[index] + solve(nums,index+1,arrno+1);
    return max(op1,op2);
}
int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll n;
        cin >> n;
        vll arr(n);
        input(arr);
        cout << arr[0] + solve(arr,1,1);

    }
    return 0;
}