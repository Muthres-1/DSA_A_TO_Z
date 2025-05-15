#include<iostream>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>


using namespace std;

// using queue
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


// using priority queue

vector<int> shortestDist(vector<vector<pair<int,int>>>adj,int N,int src){
    vector<int>ans(N,1e9);
    ans[src]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;// using min heap
    pq.push({0,src});// as {distance,node}
    while (!pq.empty())
    {
        int dist=pq.top().first;//or it will equal ans[node]
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int nearNode=it.first;
            int nearNodeWeight=it.second;
            if(dist+nearNodeWeight<ans[nearNode]){
                ans[nearNode]=dist+nearNodeWeight;
                pq.push({ans[nearNode],nearNode});
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

// using set


vector<int> shortestDist(vector<vector<pair<int,int>>>adj,int N,int src){
    vector<int>ans(N,1e9);
    ans[src]=0;
    set<pair<int,int>> st; 
    st.insert({0,src});// as {distance,node}
    while (!st.empty())
    {
        auto it = *(st.begin()); 
        int node = it.second; 
        int dis = it.first; 
        st.erase(it);
        for(auto it:adj[node]){
            int adjNode = it.first; 
                int edgW = it.second; 
                
                if(dis + edgW < ans[adjNode]) {
                    // erase if it was visited previously at 
                    // a greater cost.
                    if(ans[adjNode] != 1e9) 
                        st.erase({ans[adjNode], adjNode});                         
                    // If current distance is smaller,
                    // push it into the queue
                    ans[adjNode] = dis + edgW; 
                    st.insert({ans[adjNode], adjNode}); 
        }
    }
    for(int i=0;i<N;i++){
        if(ans[i]==1e9){
            ans[i]=-1;
        }
    }
    return ans;    
}

// time complexity using queue= O(V^2)
// time complexity using priority queue= O(V+ElogV) and space =O(V+E)
// time complexity using set=O()



