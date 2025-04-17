#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int max_val;
    node()
    {
        max_val = 0;
    }
};
node merge(node a,node b)
{
    node ans;
    ans.max_val = max(a.max_val,b.max_val);
    return ans;
}

node t[4*200200];
int a[200200];
void build(int idx,int l,int r)
{
    if(l == r)
    {
        //leaf node
        t[idx].max_val = a[l];
        return ;
    }
    int mid = (l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    t[idx] = merge(t[2*idx],t[2*idx+1]);
}

void update(int idx,int l,int r,int pos,int val)
{
    if(pos < l || pos > r) return ;
    if(l == r)
    {
        t[idx].max_val -= val;
        return ;
    }
    int mid = (l+r)/2;
    update(2*idx,l,mid,pos,val);
    update(2*idx+1,mid+1,r,pos,val);
    t[idx] = merge(t[2*idx],t[2*idx+1]);
}

int query(int idx,int l,int r,int req)
{
    if(t[idx].max_val < req) return 0;
    if(l == r)
    {
        return l;
    }
    int mid = (l+r)/2;
    if(t[2*idx].max_val >= req)
    {
        return query(2*idx,l,mid,req);
    }
    else
    {
        return query(2*idx+1,mid+1,r,req);
    }
}
signed main()
{
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    build(1,1,n);
    while(q--)
    {
        int req;cin >> req;
        int idx = query(1,1,n,req);
        cout << idx << " ";
        if(idx != 0)
        {
            update(1,1,n,idx,req);
        }
    }
    return 0;
}