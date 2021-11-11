#include "thetime.hpp"
using namespace thetime;

Time_::Time_()
{
    s_time = time(NULL);
    m_time = localtime(&s_time);
}

Time_::~Time_()
{
    m_time = 0;
}

const int Time_::get_m()
{
    s_time = time(NULL);
    m_time = localtime(&s_time);
    int min = static_cast<int>(m_time->tm_min);
    return min;
}

const int Time_::get_h()
{
    s_time = time(NULL);
    m_time = localtime(&s_time);
    int hour = static_cast<int>(m_time->tm_hour);
    if(hour > 12)
        hour -=12;
    return hour;
}