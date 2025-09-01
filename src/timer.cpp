#include "timer.h"

Timer::Timer()  
{
}

bool Timer::isExpired() const {
    if (!m_stopped) {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(now - m_startTime) >= m_interval;
    }
    else {
        throw std::runtime_error("cannot check isExpired() on stopped timer");
    }
    
}

void Timer::start(std::chrono::milliseconds ms) {
    m_interval = ms;
    m_startTime = std::chrono::steady_clock::now();
    m_stopped = false;
}

void Timer::stop() {
    m_stopped = true;
}

bool Timer::isStopped() {
    return m_stopped;
}