function isSafe(graph,node,color,x){
    for(let i =0;i<graph[node].length;i++){
        if(graph[node][i]== 1 && color[i]==x){
            return false;
        }
    }
    return true;
}

function isColoring(graph,node,n,color,M){
    if(node==n){
        return true;
    }
    for(let i=1;i<=M;i++){
        if(isSafe(graph,node,color,i)){
            color[node]=i;
            if(isColoring(graph,node+1,n,color,M)){
                return true;
            }
           color[node]=0;//backtracking  
        }
    }
    return false;
}

let color= new Array(n).fill(0);
let x=isColoring(graph,0,n,color,M);