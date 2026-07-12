class Solution {
public:
    void nextPermutation(vector<int>& arr) {
    int n = arr.size();

    int index = -1;

    // Find breakpoint
    for(int i=n-2;i>=0;i--){

        if(arr[i] < arr[i+1]){

            index = i;
            break;
        }
    }

    // No breakpoint
    if(index == -1){

        reverse(arr.begin(),arr.end());
        return;
    }

    //  Find next greater element
    for(int i=n-1;i>index;i--){

        if(arr[i] > arr[index]){

            swap(arr[i],arr[index]);
            break;
        }
    }

    // Reverse suffix
    reverse(arr.begin()+index+1,arr.end());
    }
};