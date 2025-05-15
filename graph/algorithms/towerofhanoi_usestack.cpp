#include <iostream>
#include <stack>
using namespace std;

void moveDisk(stack<int>& source, stack<int>& destination, char s, char d, int* i)
{
    int top = source.top();
    source.pop();
    destination.push(top);
    cout << ++(*i) << ". Move disk " << top << " from " << s << " to " << d << endl;
} 

void towerOfHanoi(int n, stack<int>& source, stack<int>& auxiliary, stack<int>& destination, int* i) {
    if (n == 1) {
        moveDisk(source, destination, 'A', 'C', i);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary, i);
    moveDisk(source, destination, 'A', 'C', i);
    towerOfHanoi(n - 1, auxiliary, source, destination, i);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    int i = 0;

    stack<int> source, auxiliary, destination;
    for (int j = n; j >= 1; --j) {
        source.push(j);
    }

    towerOfHanoi(n, source, auxiliary, destination, &i);
    cout << "Total required moves: " << i << endl;
    return 0;
}
