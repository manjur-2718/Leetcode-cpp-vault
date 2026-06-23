class Solution {
public:
    int check(vector<vector<int>> &matrix,int target,int m,int n){
        int row=m-1;
        int col=0;
        int count=0;
        while(row>=0 && col<n){
            if(matrix[row][col]>target){
                row--;
            }
            else{
                count+=row+1;
                col++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(k==1) return matrix[0][0];
        int m=matrix.size();
        int n=matrix[0].size();
        int low=matrix[0][0];
        int high=matrix[m-1][n-1];
        int res=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            int count=check(matrix,mid,m,n);

            if(count<k){
                low=mid+1;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
        return res;

    }
};