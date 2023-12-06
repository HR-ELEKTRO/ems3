#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

class Delay_line {
public:
	Delay_line();
//	call get before put and alternate calls
	int get();
	void put(int sample);
private:
	array<int, 8> buffer;
	typename array<int, 8>::size_type index;
	bool put_called;
};

Delay_line::Delay_line(): buffer{}, index{0}, put_called{true} {
}

int Delay_line::get() {
	if (put_called) {
		if (++index >= 8) {
			index = 0;
		}
		put_called = false;
	}
	return buffer[index];
}

void Delay_line::put(int sample) {
	buffer[index] = sample;
	put_called = true;
}

int main() {
	Delay_line d;
	// put samples 1 to 20 in delay line and see what comes out.
	for (int i {1}; i <= 20; ++i) {
		cout << "out: " << setw(2) << d.get();
		d.put(i);
		cout << ", in: " << setw(2) << i << '\n';
	}
	// calls to get without put return the same sample
	for (int i {0}; i < 10; ++i) {
		cout << "out: " << setw(2) << d.get() << '\n';
	}
	// calls to put without get override each other
	for (int i {11}; i <= 21; ++i) {
		d.put(i);
		cout << "in: " << setw(2) << i << '\n';
	}
	// put samples 22 to 30 in delay line and see what comes out.
	for (int i {22}; i <= 30; ++i) {
		cout << "out: " << setw(2) << d.get();
		d.put(i);
		cout << ", in: " << setw(2) << i << '\n';
	}
}
