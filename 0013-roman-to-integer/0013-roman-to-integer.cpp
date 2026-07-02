class Solution {
public:

    // Function to convert a Roman character into its integer value
    int num(char c){

        if(c == 'I')
            return 1;

        else if(c == 'V')
            return 5;

        else if(c == 'X')
            return 10;

        else if(c == 'L')
            return 50;

        else if(c == 'C')
            return 100;

        else if(c == 'D')
            return 500;

        else
            return 1000;   // If none of the above, it must be 'M'
    }

    int romanToInt(string s) {

        // Variable to store the final answer
        int sum = 0;

        // Start checking from the first character
        int index = 0;

        // Loop until the second last character
        while(index < s.size() - 1){

            // If current Roman value is smaller than next Roman value,
            // subtract it because it forms a special Roman number.
            // Example:
            // IV = 5 - 1 = 4
            // IX = 10 - 1 = 9
            if(num(s[index]) < num(s[index+1]))
                sum = sum - num(s[index]);

            // Otherwise simply add its value.
            // Example:
            // VI = 5 + 1 = 6
            else
                sum = sum + num(s[index]);

            // Move to next character
            index++;
        }

        // Add the last character because it has no next character
        sum = sum + num(s[index]);

        // Return the final integer
        return sum;
    }
};