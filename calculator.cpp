#include <iostream>
using namespace std;

int main() {
    int x;
    double a, b, result;
    
    cout << "Press 1 to add" << endl;
    cout << "Press 2 to divide" << endl;
    cout << "Press 3 to multiply" << endl;
    cout << "Press 4 to subtract" << endl;

    cout << "Enter your choice: ";
    cin >> x;

    cout << "Enter 2 numbers: ";
    cin >> a >> b;

    switch (x) {
        case 1:
            result = a + b;
            cout << "Sum is: " << result << endl;
            break;
        case 2:
            if (b != 0) {
                result = a / b;
                cout << "Division is: " << result << endl;
            } else {
                cout << "Cannot divide by zero" << endl;
            }
            break;
        case 3:
            result = a * b;
            cout << "Product is: " << result << endl;
            break;
        case 4:
            result = a - b;
            cout << "Difference is: " << result << endl;
            break;
        default:
            cout << "Your choice is invalid" << endl;
    }

    return 0;
}
