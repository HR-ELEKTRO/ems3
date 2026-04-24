module stopwatch;
import std;
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

chrono::milliseconds Stopwatch::duration() const {
    return chrono::duration_cast<chrono::milliseconds>(stop_time - start_time);
}
