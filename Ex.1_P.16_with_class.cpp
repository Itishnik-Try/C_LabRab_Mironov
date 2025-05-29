#include <iostream>
#include <cmath>
#include <iomanip>

class Rez {
private:
    double part1(double x) {
        double sqrt_x = sqrt(x);
        double cbrt_x = cbrt(x);
        double cos_sqrt = cos(sqrt_x);
        double cos_cbrt = cos(cbrt_x);
        return sqrt(pow(cos_sqrt, 3) / (pow(cos_cbrt, 2) + 7));
    }

    double part2(double x) {
        double lg_x = log10(x);
        double inner = pow(2, x) + pow(fabs(x), 2 * lg_x);
        return pow(log10(inner), 5);
    }

public:
    double getY(double x) {
        return part1(x) + part2(x);
    }

    bool check(double x, double y) {
        return (fabs(x) + fabs(y)) <= 2 * sqrt(2);
    }
};

int main() {
    Rez rez;
    double x, y;

    std::cout << "Введите x: ";
    std::cin >> x;

    if (x <= 0) {
        std::cout << "False" << std::endl;
        return 0;
    }

    y = rez.getY(x);
    bool inRegion = rez.check(x, y);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "y(" << x << ") = " << y << std::endl;
    std::cout << (inRegion ? "True" : "False") << std::endl;

    return 0;
}