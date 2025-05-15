#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
// graph adjency list representation 
class graph{
   public:
   unordered_map<int,list<int>>adj;   
   void addedge(int u,int v,bool direction)
   {
    // direction =0 ->undirected 
    // direction =1 ->directed(u->v if directed)
    adj[u].push_back(v); // in this we gave an list as name u and in that list push v
    if(direction==0)
    {
        adj[v].push_back(u); // in this we gave an list as name v and in that list push u
    }
   }
   int countneighbour(int a)
   {
     int n=0;
     for(auto i:adj[a])
     {
        n++;
     }
     return n;
   }
   void printadjlist(void)
   {
    for(auto i:adj)
    {
        cout<<i.first<<"->";
        for(auto j:i.second)
        {
          cout<<j<<", ";
        }
        cout<<endl;
    }
   }
};
int main()
{
graph g;
 int n;
 cout<<"Enter the number of vertices -";
 cin>>n;
 int m;
 cout<<endl<<"Enter the number of edges ";
 cin>>m;
 for(int i=0;i<m;i++) // because we are passing edge that's why this will go on up to m times
 {
    int u,v;
    cin>>u>>v;
    g.addedge(u,v,0);
 }
 g.printadjlist();
 cout<<g.countneighbour(0)<<endl;
return 0;
}
