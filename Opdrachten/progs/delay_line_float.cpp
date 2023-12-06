#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

/* vul hier jouw code in */

int main() {
    // test template with float and a delay of 4
    // print floats in fixed format with one digit after point
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(1);
    Delay_line<float, 4> d;
    // put samples 1 to 20 in delay line and see what comes out.
    for (int i {1}; i <= 6; ++i) {
        cout << "out: " << d.get();
        float f {i / 10.0f};
        d.put(f);
        cout << ", in: " << f << '\n';
    }
    // calls to get without put return the same sample
    for (int i {0}; i < 3; ++i) {
        cout << "out: " << d.get() << '\n';
    }
    // calls to put without get override each other
    for (int i {6}; i <= 7; ++i) {
        float f {i / 10.0f};
        d.put(f);
        cout << "in: " << f << '\n';
    }
    // put samples 22 to 30 in delay line and see what comes out.
    for (int i {8}; i < 15; ++i) {
        cout << "out: " << d.get();
        float f {i / 10.0f};
        d.put(f);
        cout << ", in: " << f << '\n';
    }
}

/* Gewenste output:
out: 0.0, in: 0.1
out: 0.0, in: 0.2
out: 0.0, in: 0.3
out: 0.0, in: 0.4
out: 0.1, in: 0.5
out: 0.2, in: 0.6
out: 0.3
out: 0.3
out: 0.3
in: 0.6
in: 0.7
out: 0.4, in: 0.8
out: 0.5, in: 0.9
out: 0.6, in: 1.0
out: 0.7, in: 1.1
out: 0.8, in: 1.2
out: 0.9, in: 1.3
out: 1.0, in: 1.4
*/
