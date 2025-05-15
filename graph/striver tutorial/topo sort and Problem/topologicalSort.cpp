#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
    void dfs(int node,vector<bool>&visited,int V,vector<int>adj[],stack<int>&st){
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,visited,V,adj,st);
            }
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
        vector<bool>visited(V,false);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,V,adj,st);
            }
        }
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;        
	}
};

int main()
{

return 0;
}