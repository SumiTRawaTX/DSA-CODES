class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<string> rows(numRows);
        int direction = -1;
        int row = 0;

        for (char c : s) {
            rows[row] += c;
            if (row == 0 || row == numRows - 1) {
                direction *= -1;
            }
            row += direction;
        }

        string result;
        for (string row : rows) {
            result += row;
        }

        return result;
        
    }
};