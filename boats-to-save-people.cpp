class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        int len = people.size();
        sort(people.begin(), people.end());
        int left = 0, right = len - 1;
        while (left <= right){
            if (left == right) return ++count;
            if (people[left] + people[right] > limit){
                ++count; --right;
            } else {
                ++count; ++left; --right;
            }
        } return count;
    }
};