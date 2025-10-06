class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = 0, fullBottles = numBottles;
        while (fullBottles > 0) {
            result += fullBottles;
            // exchange
            fullBottles = numBottles / numExchange;
            numBottles = fullBottles + numBottles % numExchange;
        }

        return result;
    }
};