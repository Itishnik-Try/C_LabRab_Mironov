#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y;

    cout << "Введите x: ";
    cin >> x;

    if (x <= -0.5) {
        y = -pow(x, 5) + log10(pow(3, x)) - pow(fabs(x), -x);
    } 
    else if (x > -0.5 && x < 0.5) {
        if (x == 0 || (1 - x*x) <= 0) {
            cout << "Ошибка" << endl;
            return 1;
        }
        y = log10(x / (1 - x*x));
    } 
    else {
        if (fabs(1 / (4*x)) > 1) {
            cout << "Ошибка" << endl;
            return 1;
        }
        y = acos(1 / (4*x));
    }

    cout << "y(" << x << ") = " << y << endl;

    return 0;
}