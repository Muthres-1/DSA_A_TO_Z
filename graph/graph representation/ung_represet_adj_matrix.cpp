#include<iostream>
using namespace std;

// if we make pointer inside of class then we need to make a deconstruct class too
class graph{
    public:
    int edges;
    int vertices;
    int **adjcencymatrix;
    graph(int ed,int ver)
    {
       edges=ed;
       vertices=ver; 
       adjcencymatrix=new int*[ver]; // Because adjcencymatrix is double pointer so it will point to a pointer
       for(int i=0;i<ed;i++)
       {
          adjcencymatrix[i]=new int[ver];
          for(int j=0;j<ed;j++)
          {
            adjcencymatrix[i][j]=0;
          }
       }
       // now we need to initialize with zero so for that instead of new two loop creation 
       // we make one more loop inside this loop and do initialize with zero 
    }
    void addedge(int u,int v,int weight)
    {
        adjcencymatrix[u][v]=weight;
        adjcencymatrix[v][u]=weight;
    }
    void print()
    {
        for(int i=0;i<=vertices;i++)
        {
            if(i==0)
            {
                cout<<"  ";
                continue;
            }
            cout<<i-1<<" ";
        }
        cout<<endl;
        for(int i=0;i<vertices;i++)
        {
            cout<<i<<" ";
            for(int j=0;j<vertices;j++)
            {
                cout<<adjcencymatrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    ~graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjcencymatrix[i]; // delete each row
        }
        delete[] adjcencymatrix; // delete the array of pointers
    }

};
int main()
{

int ed,ver,weight;
cin>>ed>>ver;
graph g(ed,ver);
for(int i=0;i<ed;i++)
{
    int v1,v2;
    cin>>v1>>v2>>weight;
    g.addedge(v1,v2,weight);
}
g.print();
return 0;
}