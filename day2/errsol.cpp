#include <iostream>
using namespace std;

int main() {
    int side, area;
    cout << "Enter the side length of the square: ";
    cin >> side;
    area = side * side;

    // Output result
    cout << "Area of the square: " << area << endl;

    return 0;
}