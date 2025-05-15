function Sudoku(board,n){
    for(let row=0;row<n;row++){
        for(let col=0;col<n;col++){
            if(board[row][col]=='.'){
                for(let i='1';i<='9';i++){
                    if(isValid(board,row,col,i)){
                        board[row][col]=i.toString();
                        if(Sudoku(board,n)){
                            return true;
                        }
                        else{
                            board[row][col]='.';
                        }
                    }
                }
                return false;
            }
            
        }
    }
    return true;
}
function isValid(board,row,col,num){
    for(let i=0;i<=8;i++){
        if(board[i][col]==num){
            return false;
        }
        if(board[row][i]==num){
            return false;
        }
        if(board[3*Math.floor(row/3)+Math.floor(i/3)][3*Math.floor(col/3)+i%3]==num){
            return false;
        }
        
    }
    return true;
}
