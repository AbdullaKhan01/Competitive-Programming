#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int sum;
    node()
    {
        sum = 0;
    }
};
node merge(node a,node b)
{
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

node t[4*200200];

void build(int idx,int l,int r)
{
    if(l == r)
    {
        //leaf node
        t[idx].sum = 0;
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
        t[idx].sum += val;
        return ;
    }
    int mid = (l+r)/2;
    update(2*idx,l,mid,pos,val);
    update(2*idx+1,mid+1,r,pos,val);
    t[idx] = merge(t[2*idx],t[2*idx+1]);
}

node query(int idx,int l,int r,int lq,int rq)
{
    if(lq > r || l > rq)
    {
        return node();
    }
    if(lq <= l && r <= rq)
    {
        return t[idx];
    }
    int mid = (l+r)/2;
    return merge(query(2*idx,l,mid,lq,rq),query(2*idx+1,mid+1,r,lq,rq));
}
signed main()
{
    int n,q;
    cin >> n >> q;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    build(1,0,n-1);
    while(q--)
    {
        int ch;cin >> ch;
        if(ch == 1)
        {
            int a,b,u;
            cin >> a >> b >> u;
            a--,b--;
            update(1,0,n-1,a,u);
            update(1,0,n-1,b+1,-u);
        }
        else
        {
            int k;
            cin >> k;
            k--;
            node ans = query(1,0,n-1,0,k);
            cout << ans.sum + a[k] << endl;
        }
    }
    return 0;
}