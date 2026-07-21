class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        // Step 1: Count original active sections
        int active = 0;

        for (char ch : s) {
            if (ch == '1') {
                active++;
            }
        }


        // Step 2: Add temporary 1 on both sides
        string t = "1" + s + "1";


        // Stores lengths of zero blocks
        vector<int> zeroBlocks;

        int count = 0;


        // Step 3: Find every consecutive block of zeros
        for (char ch : t) {

            if (ch == '0') {
                count++;
            }

            else {
                // A zero block has ended
                if (count > 0) {
                    zeroBlocks.push_back(count);
                    count = 0;
                }
            }
        }


        // Step 4: Find maximum sum of
        // two neighboring zero blocks

        int maxGain = 0;

        for (int i = 0; i + 1 < zeroBlocks.size(); i++) {

            int gain = zeroBlocks[i] + zeroBlocks[i + 1];

            maxGain = max(maxGain, gain);
        }


        // Step 5: Original active + newly activated sections
        return active + maxGain;
    }
};