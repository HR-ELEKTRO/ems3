#include <iostream>
#include <chrono>

// class to measure time in ms 
class Stopwatch {
public:
    Stopwatch();
    void start();
    void stop();
private:
    bool running;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> stop_time;
friend std::ostream& operator<<(std::ostream& o, const Stopwatch& sw);
};
