class Solution {
public:
bool isPossible(vector<int> & arr, int k , int maxSum){
    int currSum = 0;
    k--;

    for(int i=0;i<arr.size();i++){
        if(currSum + arr[i] <= maxSum){
            currSum += arr[i];
        }

        else {
            currSum = arr[i];
            k--;
        }
    }
    if(k<0)
    return false;

    return true;
}
int splitArray(vector<int> & arr, int k){
    
    int maxElm = *max_element(arr.begin(),arr.end());
    int sum = accumulate(arr.begin(),arr.end(),0);

    if(k>arr.size())
    return -1;
    int low = maxElm, high = sum;
    while(low<=high){
        int mid = (low+high)/2;

        if(isPossible(arr,k,mid))
        high = mid-1;

        else
        low = mid+1;
    }
    return low;
    }
};