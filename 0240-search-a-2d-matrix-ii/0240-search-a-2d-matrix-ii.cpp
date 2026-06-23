class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int col=0;
        int row=m-1;
        while(row>=0 && col<n){
            if(matrix[row][col]==target) return true;

            if(matrix[row][col]>target) row--;

            else col++;
        }
        return false;
    }
};