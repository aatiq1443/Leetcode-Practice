class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                string modified1 = s;
                modified1[right] = s[left];

                std::string modified2 = s;
                modified2[left] = s[right];

                if (modified1 < modified2) {
                    s = modified1;
                } else {
                    s = modified2;
                }
            }

            left++;
            right--;
        }

        return s;
    }
};