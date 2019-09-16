# Algorithm

DFS

# Better Solution

```c++
// Optimize the array
const int MAXN=100010;
const int MAXM=100010;

class Solution {
    int Head[MAXN], Next[MAXM*2], To[MAXM*2];
    bool vis[MAXN];
    int dfn[MAXN],low[MAXN];
    int n,tot,tim,num_cutedge;
    struct Edge{
        int u,v;
    }cutedge[MAXM];


    void Tarjan(int u,int pre) {
        dfn[u] = low[u] = ++tim;
        vis[u] = true;
        
        for (int i = Head[u]; i; i = Next[i]) {
            int v=To[i];
            if(v == pre)continue;
            if (!vis[v]){
                Tarjan(v, u);
                low[u] = min(low[u], low[v]);
                
                if (low[v] > dfn[u]) {
                    cutedge[++num_cutedge] = {u, v};
                }
            }else{
                low[u] = min(low[u], dfn[v]);
            }  
        }
        
    }
    
    void solve(){
        memset(dfn,-1,sizeof(dfn));
        memset(low,-1,sizeof(low));
        memset(vis,false,sizeof(vis));
        num_cutedge = 0;
        tim = 0;
        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                 Tarjan(i,0);
            }
        }
    }
    void Outit(vector<vector<int>>& ans){
        for (int i = 1; i <= num_cutedge; i++){
            ans.push_back({cutedge[i].u - 1,cutedge[i].v - 1});
        }
    }
    
    void add_eage(int x, int y){
        tot++;
        Next[tot] = Head[x];
        Head[x] = tot;
        To[tot] = y;
    }
    void ReadInfo(int n, vector<vector<int>>& conn){
        memset(Head, 0, sizeof(Head));
        tot = 0;
        this->n = n;
        for(auto&v: conn){
            int x = v[0]+1;
            int y = v[1]+1;
            add_eage(x,y); 
            add_eage(y,x);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        ReadInfo(n, conn);
        solve();
        
        vector<vector<int>> ans;
        Outit(ans);
        return ans;
    }
};
```

(The best run time solution in the leetcode)

# Performance

Runtime: 1012 ms, faster than 18.29% of C++ online submissions for Critical Connections in a Network.

Memory Usage: 172.5 MB, less than 100.00% of C++ online submissions for Critical Connections in a Network.

# Time Spent

Not Done

# Times of Wrong Answer

~

# Solution

```c++
// Simple DFS
class Solution {
	public:
		map< int ,vector< int > > graph ;
		int time_stamp = 1 ;  
		struct Vetex {
			int index ;  // time_stamp 
			int lowlink ; // The earliest point that can be reached by a non-father node
		};
		vector< Vetex > check ;
		vector< vector<int> > ans ; 
		void dfs( int v , int parent ) {

			check[v].index = time_stamp ; 
			check[v].lowlink = time_stamp ;
			time_stamp ++ ;

			for( auto &w : graph[v] ){
				if ( w == parent ) continue ; 
				if ( check[w].index == 0 ){ // not visited
					dfs( w , v ) ; 
					// calc The earliest point that can be reached by a non-father node
					check[v].lowlink = min( check[v].lowlink , check[w].lowlink ) ; 
					if ( check[w].lowlink > check[v].index ) // this must be a bridge 
						ans.push_back( {v,w } ) ; 
				}  else {
					check[v].lowlink = min( check[v].lowlink , check[w].index ) ; 
				}
			}

		}
		vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
			check.resize( n+1 ) ; 
			// construct graph 
			for( auto &edge : connections ) {
				graph[edge[0]].push_back( edge[1] ) ; 
				graph[edge[1]].push_back( edge[0] ) ; 
			}
			for( int i=0 ; i< n ; i++ ) 
				if ( check[i].index == 0 ) // not visited 
					dfs( i , -1 ) ; 
			return ans ; 
		}
	};
```

The code of AC solution

# Time Complexity

O(kn), k is query time, n is edge number.

# Note & Tips

1. I tried to use BFS to solve this problems but meet TLE, because the graph may have much more edges than nodes. BFS has lower efficiency in finding a path.
2. This problem is not solved in contest, 7/11 tests passed.