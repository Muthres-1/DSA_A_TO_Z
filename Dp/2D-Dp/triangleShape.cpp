#include <iostream>
using namespace std;

int isEven(int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return 1;
    else return 0;
}

void trianglePattern(int row) {
    int col = 2 * (row - 1) + 1;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (j >= row - i - 1 && j <= row - 1 + i) {
                int mi = isEven(i);
                int mj = isEven(j);
                if ((mi && mj) || ((!mi) && (!mj))) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            } else {
                cout << " ";
            }
        }
        cout << endl;  // To move to the next line after each row
    }
}

int main() {
    trianglePattern(20);
    return 0;
}
