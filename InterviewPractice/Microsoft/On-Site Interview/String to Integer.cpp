// https://leetcode.com/problems/string-to-integer-atoi/

#define sz(x) int(x.size())

const int int_max = pow(2, 31) - 1;
const int int_min = -pow(2, 31);

class Solution {
public:
    int myAtoi(string str) {
        int start = -1, sign = 1;
        bool op = false;
        for (int i = 0; i < sz(str); i++) {
            if (str[i] != ' ') {
                if (!isdigit(str[i])) {
                    if (str[i] == '+' || str[i] == '-') { // sign character
                        if (op) return 0;
                        op = true;
                        sign *= ((str[i] == '-') ? -1 : 1);
                        continue; // skip assigning start = this position
                    }
                    else return 0; // the first non-white space is not numerical;
                }
                start = i;
                break;
            }
            else if (op) return 0;
        }
        if (start == -1) return 0; // str is empty or contains only white spaces
        string num = "";
        for (int i = start; i < sz(str); i++) {
            if (isdigit(str[i])) {
                num += str[i];
            }
            else break;
        }
        while (sz(num) != 0 && num[0] == '0') num.erase(num.begin());
        if (num == "") return 0;
        if (sz(num) >= 11) return (sign == -1) ? int_min : int_max;
        long long tmp = stoll(num);
        if (tmp < int_min || tmp > int_max) return (sign == -1) ? int_min : int_max;
        return sign * tmp;
    }
};
