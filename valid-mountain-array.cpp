class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        size_t len = arr.size();
        if (len < 3) return 0;
        if (arr[1] <= arr[0]) return 0;
        int i;
        for (i = 1; i < len - 1; ++i){
            if (arr[i] == arr[i - 1]) return 0;
            if (arr[i] < arr[i - 1]) break;
        }
        for (int j = i; j < len; ++j){
            if (arr[j] == arr[j - 1]) return 0;
            if (arr[j] > arr[j - 1]) return 0;
        }
        return 1;
    }
};