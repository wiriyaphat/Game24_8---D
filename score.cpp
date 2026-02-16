#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

atomic<int> timeLeft(60);
atomic<bool> running(true);

void timer() {

    while (running) {

        if (timeLeft > 0) {
            cout << "\rTime Left: " << timeLeft-- << " sec" << flush;
            this_thread::sleep_for(chrono::seconds(1));
        }
        else {
            cout << "\nTime's up!\n";
            running = false;
        }
    }
}

int main() {

    thread t(timer);

    //
        //code by arm


    //

    t.join();
    return 0;
}