class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (string token : tokens){
            if (token == "+" || token == "-" || token == "*" || token == "/"){
                double num1 = nums.top(); nums.pop();
                double num2 = nums.top(); nums.pop();
                if (token == "+") nums.push(num1 + num2);
                if (token == "-") nums.push(num2 - num1);
                if (token == "*") nums.push(num1 * num2);
                if (token == "/") nums.push(num2 / num1);
            } else {
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};