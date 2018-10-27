#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ld long double
#define gch(ch) scanf("%c",&ch)
#define gcharr(arr,n) FOR(i,0,n) gch(arr[i])
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d %d",&x,&y)
#define gi3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define pi(x) printf("%d ",x)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld %lld",&x,&y)
#define gll3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define pll(x) printf("%lld ",x)
#define gld(x) scanf("%lf",&x)
#define pld(x) printf("%ld ",x)
#define pline printf("\n")
#define fori(i,a,b,c) for(ll i=a;i<b;i+=c)
#define ford(i,a,b,c) for(ll i=a;i>=b;i-=c)
#define mst(a,b) memset(a,b,sizeof a)
#define deb(x) cout<<#x<<" : "<<x<<endl;
#define debug(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<endl;
#define SYNC ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
ll gcd (ll a,ll b)
{
    if(b!=0)
        return gcd(b,a%b);
    else
        return a;
}
ll power(ll a,ll b)
{
    if(b==0)
    return 1;
    if(b==1)
    return a;
    if(b%2==0)
    {
        ll t=power(a,b/2);
        return t*t;
    }
    else
    {
        ll t=power(a,b/2);
        return a*t*t;
    }
}
ll powin(ll a,ll b)
{
    if(b==0)
        return 1;
    else if(b==1)
    return a;
    else if(b%2==0)
    {
        ll t=powin(a,b/2);
        return (t*t)%mod;
    }
    else
    {
        ll t=powin(a,b/2);
        return (((t*t)%mod)*a)%mod;
    }
}
#define N 20
ll g[N][N]={0};
ll dp[1<<19][N]={0};
int n,m;
ll cnt(ll a)
{
    int r=0;
    while(a!=0)
    {
        if(a%2!=0)
        {
            r++;
        }
        a/=2;
    }
    return r;
}
ll first(ll a)
{
    int i=0;
    while(a%2==0)
    {
        i++;
        a/=2;
    }
    return i;
}
ll bit(ll mask,ll i)
{
    if(mask&1<<i)
    return 1;
    else 0;
}
void solve()
{
    int i,j,mask,f;
    int ct;
    ll ans=0;
    for(mask=1;mask<=(1<<n)-1;mask++)
    {
        ct=cnt(mask);
        f=first(mask);
        if(ct==1)
        {
            dp[mask][f]=1;
        }
        else 
        {
            for(i=0;i<n;i++)
            {
                if(((mask>>i)&1) && i!=f)
                {
                    for(j=0;j<n;j++)
                    {
                        if(g[i][j]==1)
                        dp[mask][i]+=dp[mask^(1<<i)][j];
                    }
                }
            }
        }
        if(ct>=3)
        {
            for(i=0;i<n;i++)if(g[i][f]==1)ans+=dp[mask][i];
        }
    }
    cout<<ans/2;
}
int main()
{
    SYNC
    cin>>n>>m;
    int a,b;
    //cout<<cnt(4)<<endl;
    while(m--)
    {
        cin>>a>>b;
        a--;b--;
        g[b][a]=g[a][b]=1;
    }
    solve();
    return 0;
}
