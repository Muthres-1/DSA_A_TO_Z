// function recurrence(keyboard,digit,subarr,concatedString,index){
//     if(index==digit.length){
//         subarr.push(concatedString);
//         return ;
//     }
//     for(const x of keyboard[digit[index]]){
//         recurrence(keyboard,digit,subarr,concatedString+x,index+1);
//     }     
// }

// See how to convert for loop into recurrsion when two loops are interconnected like here outer loop go from 0 to digit.length and inner loop
// goes from 0 to letters.length 

function helper(keyboard, digit, subarr, concatedString,letterIndex,letters,index) {
    if (letterIndex === letters.length) {
        return;
    }
    recurrence(keyboard, digit, subarr, concatedString + letters[letterIndex], index + 1);
    helper(keyboard, digit, subarr, concatedString,letterIndex+1,letters,index);
}
function recurrence(keyboard, digit, subarr, concatedString, index) {
    if (index === digit.length) {
        subarr.push(concatedString);
        return;
    }    
    const letters = keyboard[digit[index]];    
    helper(keyboard, digit, subarr, concatedString,0,letters,index);
}


function letterCollection(digit){
    const keyboard={
        "2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"
    }
    if(digit.length===0){
       return [];
    }
    else if(digit.length===1){
        return [...keyboard[digit]] // converting string to array
    }
    else{
        subarr=[];
        recurrence(keyboard,digit,subarr,"",0);
        
        return subarr;
    }
}


let digit="67";
console.log(letterCollection(digit));


// const keyboard = {
//     "2": "abc",
//     "3": "def",
//     "4": "ghi",
//     "5": "jkl",
//     "6": "mno",
//     "7": "pqrs",
//     "8": "tuv",
//     "9": "wxyz"
// };

// function letterCombinations(digits) {
//     if (!digits.length) return [];

//     let result = [''];

//     // Iterate through each digit in the input
//     for (const digit of digits) {
//         const temp = [];

//         // Iterate through the current combinations in result
//         for (const combination of result) {
//             // Append each possible character for the current digit to each combination
//             for (const char of keyboard[digit]) {
//                 temp.push(combination + char);
//             }
//         }

//         // Update result with the new combinations
//         result = temp;
//     }

//     return result;
// }

// const digits = "23";
// const combinations = letterCombinations(digits);
// console.log(combinations);



function recurrence2(keyboard, digit, subarr, concatedString, index, letterIndex) {    
    if (index === digit.length) {
        subarr.push(concatedString);
        return;
    }
    const letters = keyboard[digit[index]];
    if (letterIndex === letters.length) {
        return;
    }
    recurrence2(keyboard, digit, subarr, concatedString + letters[letterIndex], index + 1, 0);
    recurrence2(keyboard, digit, subarr, concatedString, index, letterIndex + 1);
}

function letterCollection2(digit){
    const keyboard={
        "2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"
    }
    if(digit.length===0){
       return [];
    }
    else if(digit.length===1){
        return [...keyboard[digit]] // converting string to array
    }
    else{
        subarr=[];
        recurrence2(keyboard,digit,subarr,"",0,0);        
        return subarr;
    }
}



console.log(letterCollection2(digit));

