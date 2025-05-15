#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void helper(vector<int>candidates,int index,int target,vector<vector<int>>&ans,vector<int>subseq){
        if(index==candidates.size() && target==0){
                ans.push_back(subseq);
                return ;
        }
        if(index>=candidates.size() || target < 0){
            return ;
        }
        subseq.push_back(candidates[index]);
        helper(candidates,index,target-candidates[index],ans,subseq);
        subseq.pop_back();
        helper(candidates,index+1,target,ans,subseq);
    }
    // note if we don't pass by reference to ans vector then it won't be correct because it won't get changed in parent 
    // it only get change child function locally
    // the helper function showing error while helper2 is not showing 
    void helper2(vector<int>&candidates,int index,int target,vector<vector<int>>&ans,vector<int>&subseq){
        if(target==0){
                ans.push_back(subseq);
                return ;
        }
        if(index>=candidates.size() || target < 0){
            return ;
        }
        subseq.push_back(candidates[index]);
        helper2(candidates,index,target-candidates[index],ans,subseq);
        subseq.pop_back();
        helper2(candidates,index+1,target,ans,subseq);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>subseq;
        helper(candidates,0,target,ans,subseq);
        return ans;
    }
};
int main(){
   
    return 0;
}
