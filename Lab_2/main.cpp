#include <iostream>
#include "calculator.h"
using namespace std;

int main() {
    Calculator calc;
    double a = -5.3, b = 2.0;

    cout << "Addition: " << calc.Add(a, b) << endl;
    cout << "Subtraction: " << calc.Sub(a, b) << endl;
    cout << "Multiplication: " << calc.Mul(a, b) << endl;
    cout << "Division: " << calc.Div(a, b) << endl;
    cout << "Modulus: " << calc.Mod(a) << endl;

    return 0;
}