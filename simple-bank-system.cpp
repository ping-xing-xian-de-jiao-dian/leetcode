#define ll long long
class Bank {
private:
    vector<ll> bal;
    int len;
    
public:
    Bank(vector<long long>& balance) {
        bal = balance;
        len = bal.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > len || account2 < 1 || account2 > len) return 0;
        if (bal[account1 - 1] < money) return 0;
        bal[account2 - 1] += money;
        bal[account1 - 1] -= money;
        return 1;
    }
    
    bool deposit(int account, long long money) {
        if (account < 1 || account > len) return 0;
        bal[account - 1] += money;
        return 1;
    }
    
    bool withdraw(int account, long long money) {
        if (account < 1 || account > len) return 0;
        if (bal[account - 1] < money) return 0;
        bal[account - 1] -= money;
        return 1;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */