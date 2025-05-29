#include <iostream>
#include <cmath>

using namespace std;

double proizvodnaya(double x) {
    if (x <= 0) return NAN;
    return pow(x, x) * (1 + log(x));
}

int main() {
    double tochka;
    cout << "Введите число (больше 0): ";
    cin >> tochka;

    if (tochka <= 0) {
        cout << "Число должно быть больше 0" << endl;
        return 1;
    }

    double otvet = proizvodnaya(tochka);
    cout << "Производная в точке " << tochka << " = " << otvet << endl;

    return 0;
}