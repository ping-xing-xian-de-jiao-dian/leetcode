bool cmp(vector<int> a, vector<int> b){
    if (a[0] > b[0]) return 1;
    if (a[0] < b[0]) return 0;
    if (a[1] < b[1]) return 1;
    if (a[1] > b[1]) return 0;
    return 0;
}

class Solution {
public:
    void forward(vector<vector<int>>& people, int i){
        vector<int> temp = people[i];
        int target = temp[1];
        while (i > target){
            people[i] = people[i - 1];
            --i;
        }
        people[i] = temp;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        size_t len = people.size();
        for (int i = 0; i < len; ++i){
            if (people[i][1] < i){
                forward(people, i);
            }
        }
        return people;
    }
};