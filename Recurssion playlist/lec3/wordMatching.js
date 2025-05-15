function wordmatching(board, row, col, word, index, visited) {
    if (index === word.length) {
        return true; // All characters matched
    } 
    if (row < 0 || col < 0 || row >= board.length || col >= board[0].length || board[row][col] !== word[index] || visited[row][col]) {
        return false; // Out of bounds or character mismatch or cell already visited
    }     
    visited[row][col] = true; // Mark the cell as visited
    
    // Explore all four directions
    const directions = [
        [0, 1], // right
        [0, -1], // left
        [1, 0], // down
        [-1, 0] // up
    ];    
    for (let [dr, dc] of directions) {
        if (wordmatching(board, row + dr, col + dc, word, index + 1, visited)) {
            return true;
        }
    }    
    visited[row][col] = false; // Unmark the cell for backtracking
    return false;
}

var exist = function(board, word) {
    let m = board.length;
    let n = board[0].length;
    
    let visited = Array.from({ length: m }, () => Array(n).fill(false));
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (wordmatching(board, i, j, word, 0, visited)) {
                return true;
            }
        }
    }
    
    return false;
};

// Example usage:
let board =[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]];
let word = "SEE";
console.log(exist(board, word)); // true
