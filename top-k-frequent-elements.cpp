class Solution {
public:
    int Partition(vector<vector<int>>& a, int low, int high){
        auto temp = a[low];
        while (low < high){
            while (low < high && a[high][0] <= temp[0]) --high;
            a[low] = a[high];
            while (low < high && a[low][0] >= temp[0]) ++low;
            a[high] = a[low];
        }
        a[low] = temp;
        return low;
    }

    void myQSort(vector<vector<int>>& a, int low, int high, int k){
        int pivotloc = Partition(a, low, high);
        int num = pivotloc - low + 1;
        if (low < high){
            if (k < num) myQSort(a, low, pivotloc - 1, k);
            else if (k > num) myQSort(a, pivotloc + 1, high, k - num);
            else return;
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> fre;
        size_t len = nums.size();
        for (int num : nums) ++fre[num];
        vector<vector<int>> toSort;
        for (auto& [k ,v] : fre){
            vector<int> temp = {v, k};
            toSort.emplace_back(temp);
        }
        myQSort(toSort, 0, toSort.size() - 1, k);
        vector<int> res;
        for (int i = 0; i < k; ++i) res.emplace_back(toSort[i][1]);
        return res;
    }
};