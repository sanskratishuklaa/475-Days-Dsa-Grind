class Solution {
public:
    bool isPalindrome(string s) {

        // Pointer starting from the beginning
        int i = 0;

        // Pointer starting from the end
        int j = s.length() - 1;

        // Continue until both pointers meet
        while (i < j) {

            // In C++, we access characters using s[index]
            char left = s[i];
            char right = s[j];

            // If left character is not a letter or digit,
            // skip it and move i forward
            if (!isalnum(left)) {
                i++;
                continue;
            }

            // If right character is not a letter or digit,
            // skip it and move j backward
            if (!isalnum(right)) {
                j--;
                continue;
            }

            // Convert both characters to lowercase and compare
            if (tolower(left) != tolower(right)) {
                return false;
            }

            // Characters are equal, so move both pointers
            i++;
            j--;
        }

        // If no mismatch was found, it is a palindrome
        return true;
    }
};