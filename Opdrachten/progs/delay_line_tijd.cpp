#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

/* vul hier jouw code in */

int main() {
	// test template with Tijdsduur and a delay of 10
    Delay_line<Tijdsduur, 10> d;
    // put samples 10:59:55 to 11:00:10 in delay line and see what comes out.
    for (int i {0}; i <= 15; ++i) {
        Tijdsduur t(10, 59, 55 + i);
        cout << "out: " << d.get();
        d.put(t);
        cout << ", in: " << t << '\n';
    }
}

/* Gewenste output:
out: 00:00:00, in: 10:59:55
out: 00:00:00, in: 10:59:56
out: 00:00:00, in: 10:59:57
out: 00:00:00, in: 10:59:58
out: 00:00:00, in: 10:59:59
out: 00:00:00, in: 11:00:00
out: 00:00:00, in: 11:00:01
out: 00:00:00, in: 11:00:02
out: 00:00:00, in: 11:00:03
out: 00:00:00, in: 11:00:04
out: 10:59:55, in: 11:00:05
out: 10:59:56, in: 11:00:06
out: 10:59:57, in: 11:00:07
out: 10:59:58, in: 11:00:08
out: 10:59:59, in: 11:00:09
out: 11:00:00, in: 11:00:10
*/