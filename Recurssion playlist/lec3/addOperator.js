function additionOfOperators(num,str,result,target,index){
    if(index>=num.length-1){
        if( eval(str)==target)
        result.push(str);
        return ;
    }
    if(index===0){
        str+=num[0];
    }
    additionOfOperators(num,str+"+"+num[index+1],result,target,index+1);// either do add +
    additionOfOperators(num,str+"-"+num[index+1],result,target,index+1); // either do add -
    additionOfOperators(num,str+"*"+num[index+1],result,target,index+1); // either do add *
    if(num[index+1]!=0)// avoiding devide by zero case
    additionOfOperators(num,str+"/"+num[index+1],result,target,index+1); // either do add /  
    additionOfOperators(num,str+num[index+1],result,target,index+1); // don't add anything (to add like 12*2) 
    
}
num="12600";
target=72;
result=[];
additionOfOperators(num,"",result,target,0);
console.log(result);


//Optimal Solution

function additionOfOperators(num, index, currentExpr, currentValue, lastOperand, target, result) {
    if (index === num.length) {
        if (currentValue === target) {
            result.push(currentExpr);
        }
        return;
    }

    for (let i = index; i < num.length; i++) {
        // Avoid numbers with leading zero
        // if (i > index && num[index] === '0') {
        //     break;
        // } //if we don't do this then the case like x+00 will not appear

        const part = num.substring(index, i + 1);
        const currentNum = parseInt(part, 10);// We want to convert this as int because we are using it to calculate currentVal
   
        if (index === 0) {
            // First number in the expression
            additionOfOperators(num, i + 1, part, currentNum, currentNum, target, result);
        } else {
            // Recursively explore the different operators
            additionOfOperators(num, i + 1, currentExpr + "+" + part, currentValue + currentNum, currentNum, target, result);
            additionOfOperators(num, i + 1, currentExpr + "-" + part, currentValue - currentNum, -currentNum, target, result);
            additionOfOperators(num, i + 1, currentExpr + "*" + part, currentValue - lastOperand + lastOperand * currentNum, lastOperand * currentNum, target, result);
            
            // Avoid division by zero
            if (currentNum !== 0) {
                additionOfOperators(num, i + 1, currentExpr + "/" + part, currentValue - lastOperand + lastOperand / currentNum, lastOperand / currentNum, target, result);
            }
        }
    }
}

num="12600";
target=72;
result=[];
additionOfOperators(num, 0, "", 0, 0, target, result);
console.log(result);
