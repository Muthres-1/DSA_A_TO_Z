function allWay(totalArr,board,row,col,vis,n,move){
    if(row==n-1 && col==n-1){
        totalArr.push(move);
        return ;
    }
    // up move
    if(row>0 && vis[row-1][col]===0 && board[row-1][col]!==0){
        vis[row][col]=1;
        allWay(totalArr,board,row-1,col,vis,n,move+"U");
        //Backtracking 
        vis[row][col]=0;
    }
     // left move
    if(col>0 && vis[row][col-1]===0 && board[row][col-1]!==0){
        vis[row][col]=1;
        allWay(totalArr,board,row,col-1,vis,n,move+"L");
        //Backtracking 
        vis[row][col]=0;
    }

    // right move
    if(col<n-1 && vis[row][col+1]===0 && board[row][col+1]!==0){
        vis[row][col]=1;
        allWay(totalArr,board,row,col+1,vis,n,move+"R");
        //Backtracking 
        vis[row][col]=0;
    }
    
    // down move
    if(row<n-1 && vis[row+1][col]===0 && board[row+1][col]!==0){
        vis[row][col]=1;
        allWay(totalArr,board,row+1,col,vis,n,move+"D");
        vis[row][col]=0;
    }
}
let n = 4
const board = [[1, 0, 0, 0],
               [1, 1, 0, 1], 
               [1, 1, 0, 0],
               [0, 1, 1, 1]]
let vis = Array.from({ length: n }, () => Array(n).fill(0));
let move="";
totalArr=[];
if(board[0][0]!=0){
    vis[0][0]=1;
    allWay(totalArr,board,0,0,vis,n,move);
}
console.log(totalArr);
