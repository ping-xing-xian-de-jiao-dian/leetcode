// class Solution {
// public:
//     vector<int> smallestK(vector<int>& arr, int k) {
//         nth_element(arr.begin(), arr.begin() + k, arr.end());
//         vector<int> res;
//         for (int i = 0; i < k; ++i) res.emplace_back(arr[i]);
//         return res;
//     }
// };
class Solution {
public:
    int Patition(vector<int>& arr, int low, int high, int k){
        int temp = arr[low];
        while (low < high){
            while (low < high && arr[high] >= temp) --high;
            arr[low] = arr[high];
            while (low < high && arr[low] <= temp) ++low;
            arr[high] = arr[low];
        }
        arr[low] = temp;
        return low;
    }

    void Qsort(vector<int>& arr, int low, int high, int k){
        int pivotloc = Patition(arr, low, high, k);
        int num = pivotloc - low + 1;
        if (low < high){
            if (k > num) Qsort(arr, pivotloc + 1, high, k - num);
            else if (k < num) Qsort(arr, low, pivotloc - 1, k);
            else return;
        }
    }

    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> res;
        if (k == 0) return res;
        const size_t len = arr.size();
        int low = 0, high = len - 1;
        Qsort(arr, low, high, k);
        for (int i = 0; i < k; ++i) res.emplace_back(arr[i]);
        return res;
    }
};