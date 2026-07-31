class Solution {
public:
    int lowerBound(vector<int>& arr, int n, int x){
    int low=0; int high=n-1;
    int idx=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            high= mid-1;
            idx=mid;
        }
        else{
            low=mid+1;
        }
    }
    return idx;
}

int upperBound(vector<int>& arr, int n, int x){
    int low=0; int high = n-1;
    int idx=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            high=mid-1;
            idx=mid;
        }
        else{
            low=mid+1;
        }
    }
    return idx;
}
    vector<int> searchRange(vector<int>& arr, int x) {
        int n=arr.size();
        if(n==0) return{-1,-1};

        int lb = lowerBound(arr,n,x);

        if (lb == n || arr[lb] != x) {
            return {-1, -1};
        }

        // The end position is always upperBound - 1
        return {lb, upperBound(arr, n, x) - 1};
        
    }
};