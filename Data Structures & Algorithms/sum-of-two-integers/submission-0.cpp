class Solution {
   public:
    int getSum(int a, int b) {
        // exit when b is 0,
        // means that we've finished the addition
        while (b != 0) {
            // 1. Finds positions where both bits are 1(carry)
            // 2. XOR gives the partial sum without carry(1+0=1, 0+1=1, 1+1=0, 0+0=0)
            // 3. Shifts the carry left one position to add in the next iteration
            int const carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }

        // return a after we finished the addition
        return a;
    }
};
