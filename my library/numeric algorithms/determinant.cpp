#include <bits/stdc++.h>
using namespace std;

int findDeterminant(vector<vector<int>> Matrix) {
    int det = 0;
    if (Matrix.size() == 1) {
        return Matrix[0][0];
    }

    else if (Matrix.size() == 2) {
        det = (Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0]);
        return det;
    }

    else {
        for (int p = 0; p < Matrix[0].size(); p++) {
            vector<vector<int>> tempMatrix;
            for (int i = 1; i < Matrix.size(); i++) {
                vector<int> row;
                for (int j = 0; j < Matrix[i].size(); j++) {
                    if (j != p) {
                        row.push_back(Matrix[i][j]);
                    }
                }

                if (row.size() > 0) {
                    tempMatrix.push_back(row);
                }
            }

            det = det + Matrix[0][p] * pow(-1, p) * findDeterminant(tempMatrix);
        }
        return det;
    }
}