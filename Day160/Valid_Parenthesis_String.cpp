/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
*/
class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, h = 0;

        for (auto& c : s) {
            l += ((c == '(') << 1) - 1;
            h += ((c != ')') << 1) - 1;

            if (h < 0) return 0;

            l = max(l, 0);
        }

        return l == 0;
    }
};