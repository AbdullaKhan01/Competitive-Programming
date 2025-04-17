#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll l,r;
ll segtree[400001];
ll a[100001];
ll b[100001];
void build(ll node,ll b1,ll e)

{if(b1==e)
{
    segtree[node]=b[b1];
// cout<<b[b1]<<"\n";
}
else
{
    ll mid=(b1+e)/2;
    
  build(2*node,b1,mid);
  build(2*node+1,mid+1,e);
  
  
  l=segtree[2*node];
  r=segtree[2*node+1];
  
  if(a[l]<a[r])
  {
      segtree[node]=l;
      
  }
  else if(a[l]>a[r])
  {
      
      segtree[node]=r;
      
  }
  else if(a[l]==a[r])
  {
      
      segtree[node]=l;
  }
  else
  {
      
  }
  
}



}
ll sum1(ll node,ll b1,ll e,ll L,ll R)
{

  if(b1>R || e<L)
  {
        return -1;
  }
  
  if (b1>=L && e<=R)
  {
        return segtree[node];  
    
  }
  
    
	ll mid=(b1+e)/2;
	ll left=sum1(2*node,b1,mid,L,R);
	ll right=sum1(2*node+1,mid+1,e,L,R);

	if(left==-1)
	{
	    return right;
	}
	else if(right==-1)
	{
	    return left;
	}	
	else
	{
	    
	    if(a[left]>a[right])
	    {
	            return right;
	    }
	    else
	    {
	        return left;
	    }
	    
	    
	} 
}

int main()
{
    ll n;
    cin>>n;
    ll i=1;
    while(i<=n)
    {
        cin>>a[i];
        b[i]=i;
        i++;
    }
    
    build(1,1,n);
    int q;
    cin >> q;
    while(q--){
    	int a1,a2;
    	cin >> a1 >> a2;
    	cout<<sum1(1,1,n,a1,a2) << endl;	
    }
    return 0;
}


























