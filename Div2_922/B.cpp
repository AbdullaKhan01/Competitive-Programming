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
int computeLongestSubarray(vector<int> &arr, int k)
{
  // Stores the maximum length subarray so far
  int maxLength = 0;
 
  deque<int> maxHeap;
  deque<int> minHeap;
 
  // Marks to the beginning and end
  // pointer for current subarray
  int beg = 0;
  int end = 0;
 
  while (end < arr.size()) {
    // Stores the current element being
    // added to the subarray
    int currEl = arr[end];
 
    // Remove indices of all elements smaller
    // than or equal to current from maxHeap
    while (!maxHeap.empty()
           && arr[maxHeap.back()] < currEl)
      maxHeap.pop_back();
 
    // Add current element's index to maxHeap
    maxHeap.push_back(end);
 
    // Remove indices of all elements larger
    // than or equal to current from minHeap
    while (!minHeap.empty()
           && arr[minHeap.back()] > currEl)
      minHeap.pop_back();
 
    // Add current element's index to minHeap
    minHeap.push_back(end);
 
    // Index of maximum of current subarray
    int maxOfSub = arr[maxHeap.front()];
 
    // Index of minimum of current subarray
    int minOfSub = arr[minHeap.front()];
 
    // check if the largest possible difference
    // between a pair of elements <= k
    if (maxOfSub - minOfSub < k) {
      // Length of current subarray
      int currLength = end - beg + 1;
 
      // Update maxLength
      if (maxLength < currLength)
        maxLength = currLength;
    }
    else {
      // If current subarray doesn't satisfy
      // the condition then remove the starting
      // element from subarray that satisfy
      // increment the beginning pointer
      beg += 1;
 
      // Remove elements from heaps that
      // are not in the subarray anymore
      while (!minHeap.empty()
             && minHeap.front() < beg)
        minHeap.pop_front();
 
      while (!maxHeap.empty()
             && maxHeap.front() < beg)
        maxHeap.pop_front();
    }
    end += 1;
  }
 
  // Return the final answer
  return maxLength;
}
signed main(){
    
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        set<int> p;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            p.insert(x);
        }
        vi arr;
        for(auto it:p){
            arr.pb(it);
        }
        // input(arr);
        // arr.resize(distance(arr.begin(),it));
        // output(arr);
        // cout << endl;
        int ans = computeLongestSubarray(arr,n);
        // set<int> arr;
        // for(int i=0;i<n;i++){
        //     int x;
        //     cin >> x;
        //     arr.insert(x);
        // }
        // vector<int> p;
        // for(auto it:arr){
        //     p.push_back(it);
        // }
        // sort(all(p));
        // int cnt = 1;
        // int s = p[0];
        // int ans = 0;
        // for(int i=1;i<n;i++){
        //     if(abs(p[i]-s)<=n){
        //         cnt++;
        //     }
        //     else{
        //         ans = max(ans,cnt);
        //         s = 
        //     }
        // }
        // ans = max(ans,cnt);
        cout << ans << endl;
    }
    return 0;
}