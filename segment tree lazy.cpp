#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long
#define ll long long
#define mp make_pair
#define ss second
#define pb push_back
#define ff first
#define um unordered_map
#define us unordered_set
#define pll pair<ll,ll>
#define large 100005
const int mod = 1e9+7;
#define PI 3.1415926535
ll powmod(ll base,ll exp,ll MOD){ll res=1;while(exp>0){if(exp%2==1) res=(res*base)%MOD;base=(base*base)%MOD;exp/=2;}return (res%MOD);}
const int N = 2e5+5;
int n;
vector<int> p(N),t(N);
vector<int> arr[N];
int tame = 1;
vector<pii> v(N);
pii tree[4*N];
int lazy[4*N];
vector<int> tt(N,0);

void DFS(int node){
	
	int si = tame;
	
	for(auto child:arr[node]){
		if(child != p[node]){
		  DFS(child);	
		}
	}
	
	v[node] =  mp(si,tame);
	tt[tame] = t[node];
	tame++;
	
	
}

void build(int si,int ei,int node){
	
    if(si==ei){
	 tree[node].ff = (tt[si]?1:0);
	 tree[node].ss = (tt[si]?0:1);
	 return;
	}
	
 	int mid = (si+ei)/2;	
	build(si,mid,2*node);
	build(mid+1,ei,2*node+1);  
	tree[node].ff = tree[2*node].ff+tree[2*node+1].ff;
	tree[node].ss = tree[2*node].ss+tree[2*node+1].ss;
	
}

void update(int l,int r,int si,int ei,int node){
	
	if(lazy[node]!=0){
	  
	  lazy[node] = 0;
	  swap(tree[node].ff,tree[node].ss);
	  
	  if(si!=ei){
	   lazy[2*node]^=1;
	   lazy[2*node+1]^=1;
      }
      
	}
	
	if(si>r || ei<l)
	 return;
	else if(si>=l && ei<=r){
	 swap(tree[node].ff,tree[node].ss);
	  if(si!=ei){
	   lazy[2*node]^=1;
	   lazy[2*node+1]^=1;
      }
     return;
	}
    
    int mid = (si+ei)/2;
    update(l,r,si,mid,2*node);
	update(l,r,mid+1,ei,2*node+1);
	tree[node].ff = tree[2*node].ff+tree[2*node+1].ff;
	tree[node].ss = tree[2*node].ss+tree[2*node+1].ss;	   
	
}

int query(int l,int r,int si,int ei,int node){
	
	if(lazy[node]!=0){
	  lazy[node] = 0;
	  swap(tree[node].ff,tree[node].ss);
	  
	  if(si!=ei){
	   lazy[2*node]^=1;
	   lazy[2*node+1]^=1;
      }
	}
	
	if(si>r || ei<l)
	 return 0; 
	else if(si>=l && ei<=r)
	  return tree[node].ff; 
	 
	int mid = (si+ei)/2;
	
	int t1 = query(l,r,si,mid,2*node);
	int t2 = query(l,r,mid+1,ei,2*node+1);
	
	return t1+t2;
	
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   cin>>n;
   
   p[1] = -1;
   
   for(int i=2;i<=n;i++){
     cin>>p[i];
     arr[i].pb(p[i]);
     arr[p[i]].pb(i);
   }
   
   for(int i=1;i<=n;i++)
     cin>>t[i];
   
   DFS(1);
   
   int q;
   cin>>q;
   
   build(1,tame-1,1);
   
   while(q--){
   	 
	 string s;
   	 cin>>s;
   	 int val;
   	 cin>>val;
   	 
   	 if(s=="get")
   	   cout<<query(v[val].ff,v[val].ss,1,tame-1,1)<<'\n';
     else
       update(v[val].ff,v[val].ss,1,tame-1,1);
     
   }
   
   return 0;
}
