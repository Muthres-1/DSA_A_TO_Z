#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination,int *i) 
{
    if (n == 1) {
        cout <<++(*i) <<". Move disk 1 from " << source << " to " << destination << endl;
        return;
    }     
    towerOfHanoi(n - 1, source, destination, auxiliary,i);
    // The line no 12 is actually base condition means- this is for n=1,
    // if I comment out line no 15 and use line no 14 instead of 15 then line no will not
    // execute only for one times it will be execute more than single times
    //cout <</*++(*i)<<*/ ". Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(1,source,auxiliary,destination,i); 
    towerOfHanoi(n - 1, auxiliary, source, destination,i);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    int i=0;
    towerOfHanoi(n, 'A', 'B', 'C',&i); // A, B, and C are the names of the pegs
    cout<<"total required moves="<<i<<endl;
    return 0;
}
