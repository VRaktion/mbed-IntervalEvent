#ifndef INTERVAL_EVENT_H
#define INTERVAL_EVENT_H

#include "mbed.h"

class IntervalEvent
{
public:
    IntervalEvent(EventQueue *eq, int interval, Callback<void()>cb);
    void start();
    void stop();
    bool pause();
    bool resume();
    bool isRunning();
    bool isPaused();
    void setInterval(int interval);

private:
    int interval;
    int eventId = NULL;
    bool running = false;
    bool paused = false;
    EventQueue *eq;
    Callback<void(void)> cb;
};

#endif //INTERVAL_EVENT_H