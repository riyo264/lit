class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int d = numBottles;
        int empty = numBottles;
        if(numBottles < numExchange) {
            return numBottles;
        }
        while(empty >= numExchange)
        {
            empty -= numExchange;
            d++;
            empty++;
            numExchange++;
        }
        return d;
    }
};