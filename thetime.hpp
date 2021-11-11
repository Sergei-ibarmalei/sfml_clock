#ifndef THETIME_HPP
#define THETIME_HPP

#include <time.h>

namespace thetime
{
    class Time_
    {
        long int s_time;
        struct tm* m_time;
        //int current_minute;
        //int current_hour;

        public:
        Time_();
        ~Time_();

        const int get_h();
        const int get_m();

    };
}


#endif