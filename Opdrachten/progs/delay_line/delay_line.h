
#ifndef _HR_BroJZ_delay_line_
#define _HR_BroJZ_delay_line_

#include <array>

class Delay_line {
public:
    Delay_line();
//  call put before get and alternate calls
    void put(int sample);
    int get();
private:
    std::array<int, 9> buffer;
    typename std::array<int, 9>::size_type index;
    bool get_called;
};

#endif