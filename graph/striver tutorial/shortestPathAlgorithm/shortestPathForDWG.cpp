// shortest path for directed weighted graph
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

vector<int> shortestDist(vector<vector<pair<int,int>>>adj,int N,int src){
    vector<int>ans(N,1e9);
    ans[src]=0;
    queue<int>q;
    q.push(src);
    while (!q.empty())
    {
        int a=q.front();
        q.pop();
        for(auto it:adj[a]){
            if(ans[a]+it.second<ans[it.first]){
                ans[it.first]=ans[a]+it.second;
                q.push(it.first);
            }
        }
    }
    for(int i=0;i<N;i++){
        if(ans[i]==1e9){
            ans[i]=-1;
        }
    }
    return ans;    
}
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>>adj(N);
        for(int i=0;i<M;i++){
                int a=edges[i][0];
                int b=edges[i][1];
                int w=edges[i][2];
                adj[a].push_back({b,w});
        }
        return shortestDist(adj,N,0);
        
    }
};


// the following code also work 

 

class Solution {
  private:
    void topoSort(int node, vector < pair < int, int >> adj[],
      int vis[], stack < int > & st) {
      //This is the function to implement Topological sort. 
      vis[node] = 1;
      for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }
      st.push(node);
    }
  public:
    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {

      //We create a graph first in the form of an adjacency list.
      vector < pair < int, int >> adj[N];
      for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt}); 
      }
      // A visited array is created with initially 
      // all the nodes marked as unvisited (0).
      int vis[N] = {
        0
      };
      //Now, we perform topo sort using DFS technique 
      //and store the result in the stack st.
      stack < int > st;
      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st);
        }
      }
      //Further, we declare a vector ‘dist’ in which we update the value of the nodes’
      //distance from the source vertex after relaxation of a particular node.

      vector < int > dist(N);
      for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
      }

      dist[0] = 0;
      while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it: adj[node]) {
          int v = it.first;
          int wt = it.second;

          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }

      for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;
    }
};

int main() {

  int N = 6, M = 7;
  
  vector<vector<int>> edges= {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
  Solution obj;
  vector < int > ans = obj.shortestPath(N, M, edges);

  for (int i = 0; i < ans.size(); i++) {

    cout << ans[i] << " ";
  }

  return 0;

}