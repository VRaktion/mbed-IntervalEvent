#include "IntervalEvent.h"

IntervalEvent::IntervalEvent(
    EventQueue *eq, int interval,
    Callback<void(void)> cb) : eq(eq), interval(interval), cb(cb)
{
}

void IntervalEvent::start()
{
    this->stop();
    this->eq->call(this->cb);
    this->eventId = this->eq->call_every(this->interval, this->cb);
    this->running = true;
}

void IntervalEvent::stop()
{
    if (this->eventId != NULL)
    {
        this->eq->cancel(this->eventId);
    }
    this->running = false;
}

bool IntervalEvent::pause()
{
    if (this->running)
    {
        this->stop();
        this->running = true;
    }
    this->paused = true;
    return this->running;
}

bool IntervalEvent::resume()
{
    if (this->running)
    {
        this->start();
    }
    this->paused = false;
    return this->running;
}

bool IntervalEvent::isRunning() { return this->running; }
bool IntervalEvent::isPaused() { return this->paused; }

void IntervalEvent::setInterval(int interval)
{
    this->interval = interval;
    this->start();
}