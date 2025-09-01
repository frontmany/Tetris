#pragma once

#include <chrono>

class Timer {
public:
    Timer();
    
    bool isExpired() const;
    void start(std::chrono::milliseconds ms);
    void stop();
    bool isStopped();
    
private:
    std::chrono::steady_clock::time_point m_startTime;
    std::chrono::milliseconds m_interval;
    bool m_stopped = false;
};
