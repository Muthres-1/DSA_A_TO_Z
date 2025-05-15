#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
using namespace std;

// Problem :- return subArray whose elements product is maximum 

// Brute force way 
// time complexity is O(n^3) and space complexity is O(1)
int mxmSubArrProduct(vector<int>arr,int length){
    int maxProduct = INT_MIN;
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            int product = 1;
            for (int k = i; k <= j; k++)
            {
                product*=arr[k];
            }
            maxProduct=max(maxProduct,product);
        }
        
    }
    return maxProduct;
}
// Better solution 
// time complexity is O(n^2) and space complexity is O(1)
int mxmSubArrProductBetter(vector<int>arr,int length){
    int maxProduct = INT_MIN;
    for (int i = 0; i < length; i++)
    {
        int product = 1;
        for (int j = i; j < length; j++)
        {            
            product*=arr[j];
            maxProduct=max(maxProduct,product);
        }
        
    }
    return maxProduct;
}
// Optimal solution 1
// time complexity is O(n) and space complexity is O(1)
int mxmSubArrProductOptimal1(vector<int>arr,int length){
    int pre = 1, suff=1;
    int ans = INT_MIN;
    for (int i = 0; i < length; i++)
    {
        if(pre==0)pre = 1;
        if(suff==0)suff =1;
        pre =pre*arr[i];
        suff = suff*arr[length-1-i];
        ans =max(ans,max(pre,suff));
    }
    return ans;
}

int main()
{
//vector<int>arr={};

return 0;
}