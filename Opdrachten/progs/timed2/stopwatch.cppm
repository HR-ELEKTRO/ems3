export module stopwatch;
import std;
using namespace std;

// class to measure time in ms 
export class Stopwatch {
public:
    Stopwatch();
    void start();
    void stop();
    chrono::milliseconds duration() const;
private:
    bool running;
    chrono::time_point<std::chrono::high_resolution_clock> start_time;
    chrono::time_point<std::chrono::high_resolution_clock> stop_time;
};
