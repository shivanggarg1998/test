#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define mp make_pair
#define ss second
#define pb push_back
#define ff first
#define um unordered_map
#define us unordered_set
#define pll pair<ll,ll>
#define mod 1000000007
#define large 100005
ll powmod(ll base,ll exp,ll MOD){ll res=1;while(exp>0){if(exp%2==1) res=(res*base)%MOD;base=(base*base)%MOD;exp/=2;}return (res%MOD);}
int n,m;
bool cmp(pair<pii,int> &a,pair<pii,int> &b){
    return a.ss<b.ss;
}

int find(vector<int> &arr,int i){
    
    if(arr[i]!=i)
     return arr[i] = find(arr,arr[i]);
    else
     return arr[i];
     
}

void uni(vector<int> &parent,vector<int> &rank,int x,int y){
    
    int xroot = find(parent,x);
    int yroot = find(parent,y);
    
    if(rank[xroot]<rank[yroot])
      parent[xroot] = yroot;
    else if(rank[yroot]<rank[xroot])
      parent[yroot] = xroot;
    else{
      parent[yroot] = xroot;
      rank[xroot]++;
    }
    
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   cin>>n>>m;
   
   vector<pii> *arr = new vector<pii>[n+1];
   vector<pair<pii,int> > v;
   
   for(int i=0;i<m;i++){
      
      int x,y,z;
      cin>>x>>y>>z;
      
      arr[x].pb(mp(y,z));
      arr[y].pb(mp(x,z));
      v.pb( mp( mp(x,y), z ) );
       
   }
   
   vector<int> rank(n+1,0),parent(n+1);
   
   for(int i=1;i<=n;i++)
     parent[i] = i;
     
   sort(v.begin(),v.end(),cmp);
   
   ll cnt = 0;     
   int temp = -1; 
        
   for(int i=0;i<v.size();i++){
      
     int temp1 = v[i].ff.ff;
     int temp2 = v[i].ff.ss;
     
     if(v[i].ss == -2)
      continue;
     
     if(v[i].ss!=temp){
       
       int k = i;
       temp = v[k].ss;
	   	
       while(v[k].ss==temp){
       	 
       	  int temp1 = v[k].ff.ff;
          int temp2 = v[k].ff.ss;
       	
         if(find(parent,temp1)==find(parent,temp2))
		    v[k].ss = -2;
		 
		 k++;   
			 	
	   }	
	   
	 }
     
	 if(v[i].ss==temp && (find(parent,temp1)==find(parent,temp2)))
	    cnt++;   	
	 else  
     if(find(parent,temp1)!=find(parent,temp2))
         uni(parent,rank,temp1,temp2);
     
     temp = v[i].ss; 
       
   }
   

   cout<<cnt;
   
  
   delete []arr;
   
	return 0;
}

