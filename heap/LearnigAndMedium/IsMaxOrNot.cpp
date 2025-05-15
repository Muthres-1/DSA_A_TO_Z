class Solution{
    public:
    // when any tree is in the form of array it will be always complete tree
    bool isMaxHeap(int arr[], int n)
    {
        if(n<=0){
            return true;
        }
        n-=1;
        while(n>0){
            int parent =(n-1)/2;
            if(arr[parent]<arr[n]){
                return false;
            }
            n-=1;
        }
        return true;
    }
};