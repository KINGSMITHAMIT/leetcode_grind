class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = m - 2; j >= 0; --j) {
                if (box[i][j] == '#') {
                    int k = j;
                    while (k + 1 < m && box[i][k + 1] == '.') {
                        box[i][k + 1] = '#';
                        box[i][k] = '.';
                        ++k;
                    }
                }
            }
        }

        // Create the rotated matrix
        vector<vector<char>> rotatedMatrix(m, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                rotatedMatrix[j][n - 1 - i] = box[i][j];
            }
        }

        return rotatedMatrix;
    }
};
