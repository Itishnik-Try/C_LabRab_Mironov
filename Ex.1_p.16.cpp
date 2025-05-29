#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x, y;
    cout << "Введите x: ";
    cin >> x;

    if (x <= 0) {
        cout << "False" << endl;
        return 0;
    }

    double sqrt_x = sqrt(x);
    double cbrt_x = cbrt(x);
    double cos_sqrt = cos(sqrt_x);
    double cos_cbrt = cos(cbrt_x);
    
    double part1 = pow(cos_sqrt, 3) / (pow(cos_cbrt, 2) + 7);
    part1 = sqrt(part1);
    
    double lg_x = log10(x);
    double part2 = pow(2, x) + pow(fabs(x), 2 * lg_x);
    part2 = pow(log10(part2), 5);
    
    y = part1 + part2;

    bool inD = (fabs(x) + fabs(y)) <= 2 * sqrt(2);

    cout << fixed << setprecision(6);
    cout << "y(" << x << ") = " << y << endl;
    cout << (inD ? "True" : "False") << endl;

    return 0;
}