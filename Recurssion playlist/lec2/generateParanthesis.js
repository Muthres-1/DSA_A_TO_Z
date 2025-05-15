// https://www.youtube.com/watch?v=s9fokUqJ76A
function generatParanthesis(n,open,close,result,str){
    if(open==n && close==n){
        result.push(str);
        return ;
    }
    if(open>n||close>n){
     return ;
    }
    // add open Paranthesis
    generatParanthesis(n,open+1,close,result,str+"(");
    if(open>close){
        generatParanthesis(n,open,close+1,result,str+")");
    } 
}
n=1;
result=[];
generatParanthesis(n,0,0,result,"");
console.log(result);