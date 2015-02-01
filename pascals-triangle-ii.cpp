#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row0(rowIndex + 1), row1(rowIndex + 1);

        for (int i = 0; i <= rowIndex; ++i) {

            if (i % 2 == 0) {
                for (int j = 1; j < i; ++j) {
                    row0[j] = row1[j - 1] + row1[j];
                }
                row0[0] = 1;
                row0[i] = 1;
            } else {
                for (int j = 1; j < i; ++j) {
                    row1[j] = row0[j - 1] + row0[j];
                }
                row1[0] = 1;
                row1[i] = 1;
            }
        }

        if (rowIndex % 2 == 0) {
            return row0;
        } else {
            return row1;
        }
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
