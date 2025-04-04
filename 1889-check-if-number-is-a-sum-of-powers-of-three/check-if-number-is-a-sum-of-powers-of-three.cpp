class Solution {
public:
    bool checkPowersOfThree(int n) { return checkPowersOfThreeHelper(0, n); }

private:
    bool checkPowersOfThreeHelper(int power, int n) {

        if (n == 0) return true;
        if (pow(3, power) > n) return false;
        bool addPower = checkPowersOfThreeHelper(power + 1, n - pow(3, power));
        bool skipPower = checkPowersOfThreeHelper(power + 1, n);
        return addPower || skipPower;
    }
};