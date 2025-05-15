// function isSafe(row,coloum,board,n){
//     let duprow=row;
//     let dupcol=coloum;
//     // check upper diagonal
//     while(dupcol>=0 && duprow>=0){
//         if(board[duprow][dupcol]==="Q")return false;
//         dupcol--;
//         duprow--;
//     }
//     dupcol=coloum;
//     // check side row
//     while(dupcol>=0){
//         if(board[row][dupcol]==="Q")return false;
//         dupcol--;
//     }
//     dupcol=coloum;
//     duprow=row;
//     // check lower diagonal
//     while(duprow<n && dupcol>=0){
//         if(board[duprow][dupcol]==="Q")return false;
//         dupcol--;
//         duprow++;
//     }
//     return true;
// }

// function NQueen(board,coloum,n,result){
//     if(coloum>=n){
//         result.push(board.map(row => row.join(''))); // convert each row to a string
//         return ;
//     }
//     else{
//         for(let i=0;i<n;i++){
//             if(isSafe(i,coloum,board,n)){
//                 board[i][coloum]="Q";
//                 NQueen(board,coloum+1,n,result);
//                 board[i][coloum]="."; //backtracking 
//             }
//         }
//     }
// }
// let n = 4;
// let board = new Array(n).fill(0).map(() => new Array(n).fill("."));
// let result = [];
// NQueen(board, 0, n, result);
// console.log(result);

// Optimal Solution
function NQueen(board,coloum,n,result,leftRow,upperDiagonal,lowerDiagonal){
    if(coloum>=n){
        result.push(board.map(row=> row.join(''))); // convert each row to a string
        return ;
    }
    else{
        for(let i=0;i<n;i++){
            if (leftRow[i] == 0 && lowerDiagonal[i + coloum] == 0 && upperDiagonal[board.length - 1 + coloum - i] == 0) {
                board[i][coloum] = 'Q';
                leftRow[i] = 1;
                lowerDiagonal[i + coloum] = 1;
                upperDiagonal[board.length - 1 + coloum - i] = 1;
                NQueen(board,coloum+1,n,result,leftRow,upperDiagonal,lowerDiagonal);
                // Backtracking 
                board[i][coloum] = '.';
                leftRow[i] = 0;
                lowerDiagonal[i + coloum] = 0;
                upperDiagonal[board.length - 1 + coloum - i] = 0;
            }
        }
    }
}
let n = 4;
let board = new Array(n).fill(0).map(() => new Array(n).fill("."));
console.log(board)
let result = [];
leftRow=new Array(n).fill(0);
lowerDiagonal=new Array(2*n-1).fill(0);
upperDiagonal=new Array(2*n-1).fill(0);
NQueen(board, 0, n, result,leftRow,upperDiagonal,lowerDiagonal);
console.log(result);




