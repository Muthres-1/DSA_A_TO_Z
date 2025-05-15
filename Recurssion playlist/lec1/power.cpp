#include<iostream>
#include<limits>
using namespace std;

// Two things in Recurssion
// first --> backtracking and non-backtracking part 
// second thing recurssion function type --> parametrized (f(sum+i,i-1)) or (f(sum+i,i+i)) and functional recursion(f(i-1)+i) or (f(i+1)+i)  here example is given assuming example summation of first n number


// class Solution {
// public:
// double power(double x,int n){
//     if(n==0)return 1;
//     else if(n==1)return x;
//     else{
//         return power(x,n-1)*x;
//     }
// }
// double myPow(double x, int n) {
//   double ans=power(x,abs(n));
//   if(n<0)return (1/ans);
//   else return ans;  
//  }
// };
// this(above) will give the stack overflow so we need to improve our answer

// class Solution {
// public:
// double power(double x,int n){
//     if(n==0)return 1;
//     else if(n==1)return x;
//     else if(n%2==0){
//         // even number
//         double a=power(x,n/2);
//         return a*a;
//     }
//     else{
//         return power(x,n-1)*x;
//     }
// }
// double myPow(double x, int n) {
//       if(x==0)return 0;
//       else if(n==0)return 1;
//       else if(n==1)return x;
//       else if(n<0){
//             return 1/power(x,-n);
//         }
//     else return power(x,n);   
//     return 0.00;
// }
// };

// the above won't be able to solve the lowest number in negative more than 32 bit
// class Solution {
// public:
// double power(double x,int n){
//     if(n==0)return 1;
//     else if(n==1)return x;
//     else if(n%2==0){
//         // even number
//         double a=power(x,n/2);
//         return a*a;
//     }
//     else{
//         return power(x,n-1)*x;
//     }
// }
// double myPow(double x, int n) {
//       if(x==0)return 0;
//       else if(n==0)return 1;
//       else if(n==1)return x;
//       else if(n==numeric_limits<int>::min()){
//             return 1/power(x,numeric_limits<int>::max());
//         }
//       else if(n<0){
//             return 1/power(x,-n);
//         }
//     else return power(x,n);   
//     return 0.00;
// }
// };

// this will give the wrong answer when x=-1 and n=-2147483648 ,output =-1

class Solution {
public:
double power(double x,int n){
    if(n==0)return 1;
    else if(n==1)return x;
    else if(n%2==0){
        // even number
        double a=power(x,n/2); // here we are calling this function every time when it is even
        return a*a;
    }
    else{
        return power(x,n-1)*x;
    }
}
double myPow(double x, int n) {
      if(x==0)return 0;
      else if(n==0)return 1;
      else if(n==1)return x;
      else if(n==numeric_limits<int>::min()){
            double ans=power(x,numeric_limits<int>::max());
            return 1/(ans*x);
        }
      else if(n<0){
            return 1/power(x,-n);
        }
    else return power(x,n);   
    return 0.00;
}
};

// the following answer is optimization 

// def power(x, n):
//     ans = 1
//     l = abs(n)  # work with positive exponent first
//     while l > 0:
//         if l & 1:          # if the last bit is 1 (odd number)
//             ans = ans * x  # multiply ans by current x
//             l = l - 1
//         else:
//             x = x * x      # square the base
//             l = l // 2     # divide exponent by 2
//     if n < 0:
//         return 1 / ans     # handle negative exponent
//     return ans
// class Solution(object):
//     def myPow(self, x, n):
//         return power(x,n)


// The function you've written is a classic example of Exponentiation by Squaring, which is an efficient method to compute 
// 𝑥^𝑛 (i.e., x raised to the power n). Let's break it down step-by-step, both intuitively and mathematically.

// ✅ Goal: Compute 
// 𝑥^𝑛  efficiently
// Instead of multiplying x by itself n times (which takes O(n) time), we reduce the problem size using bitwise operations and squaring, so it works in O(log n) time.

// 🧠 Core Idea:
// Use these properties of exponents:

// Use these properties of exponents:

// x^n =(x^2)^(n/2)  if n is even
// x^n =x⋅x^(n−1)  if n is odd

// Example:

// x^5 =x⋅x^4 =x⋅(x^2)^2
 
// x^10 =(x^2)^5 =x^2⋅(x^2)^4


// 🔍 Your Code:

// def power(x, n):
//     ans = 1
//     l = abs(n)  # work with positive exponent first
//     while l > 0:
//         if l & 1:          # if the last bit is 1 (odd number)
//             ans = ans * x  # multiply ans by current x
//             l = l - 1
//         else:
//             x = x * x      # square the base
//             l = l // 2     # divide exponent by 2
//     if n < 0:
//         return 1 / ans     # handle negative exponent
//     return ans
// 🧮 Step-by-Step Example: power(2, 10)
// Iteration	l (exp)	l&1 (odd?)	x	ans	Action
// Start	10	No	2	1	x = x² = 4, l = 5
// 1	5	Yes	4	1×4 = 4	ans = ans×x, l = 4
// 2	4	No	4² =16	4	x = x² = 16, l = 2
// 3	2	No	16²=256	4	x = x² = 256, l = 1
// 4	1	Yes	256	4×256=1024	ans = ans×x, l = 0 (done)

// ➡ Final ans = 1024
// ✔ Correct! 
// 2^10 =1024

// ⚙️ Why it works:
// The algorithm mimics the binary representation of the exponent.

// For each bit in n:

// If it's 1 → multiply by current power of x

// Always square x and reduce n

// This breaks down the exponentiation into log(n) operations.

// Example:
// 10 in binary is 1010 → corresponds to:

// 𝑥^8⋅𝑥^2 

// 💡 Handling Negative Powers:


// 📌 Summary:
// Feature	Purpose
// l & 1	Check if exponent is odd (last bit 1)
// x = x * x	Square the base
// l = l // 2	Halve the exponent
// ans *= x (when odd)	Multiply by base if bit is 1
// 1 / ans (if n < 0)	Handles negative exponents
// Time Complexity	

// O(logn) — very fast


int main(){
    Solution a;
    cout<<a.myPow(-1.00000,-2147483648)<<endl;
    return 0;
}