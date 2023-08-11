//Implement the Standard atoil function using recurssion.
// Note this code has lot of edge cases 

    int Atoil(string &s, int index, int result, bool negative) {
        if (index >= s.length()) {
            return negative ? -result : result;
        }

        if (s[index] >= '0' && s[index] <= '9') {
            if (result > (INT_MAX - (s[index] - '0')) / 10) {
                return negative ? INT_MIN : INT_MAX;
            }
            result = result * 10 + s[index] - '0';
        } else {
            return negative ? -result : result;
        }

        return Atoil(s, index + 1, result, negative);
    }

    int createAtoi(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }

        int index = 0;
        while (index < n && s[index] == ' ') {
            index++;
        }

        bool negative = false;
        if (s[index] == '-') {
            negative = true;
            index++;
        } else if (s[index] == '+') {
            index++;
        }

        return Atoil(s, index, 0, negative);
    }
