
export module delay_line;
import std;
using namespace std;

export class Delay_line {
public:
    Delay_line();
//  call put before get and alternate calls
    void put(int sample);
    int get();
private:
    array<int, 9> buffer;
    typename decltype(buffer)::size_type index;
    bool get_called;
};
