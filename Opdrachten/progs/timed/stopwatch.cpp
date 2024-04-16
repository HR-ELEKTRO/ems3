#include <iostream>
#include <chrono>

#include "stopwatch.h"

using namespace std;

Stopwatch::Stopwatch(): running{false} {
}

void Stopwatch::start() {
    if (!running) {
        running = true;
        start_time = chrono::high_resolution_clock::now();
    }
}

void Stopwatch::stop() {
    if (running) {
        running = false;
        stop_time = chrono::high_resolution_clock::now();
    }
}

ostream& operator<<(ostream& o, const Stopwatch& sw) {
    auto total_time {chrono::duration_cast<chrono::milliseconds>(sw.stop_time - sw.start_time).count()};
    return o << total_time << " ms";
}
