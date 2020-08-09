#include "ECReview.h"
#include <iostream>
using namespace std;

ECTime::ECTime (int h, int m, int s) : hour(h), min(m), sec(s) {};
ECTime::~ECTime() {};

void ECTime::GetTime(int &h, int &m, int &s) const {
    h = hour;
    m = min;
    s = sec;
}

ECTime ECTime::operator+(const ECTime &tmToAdd) {
    int total_sec = sec + tmToAdd.sec;
    int total_min = min + tmToAdd.min;
    int total_hour = hour + tmToAdd.hour;

    total_min += total_sec / 60;
    total_sec = total_sec % 60;

    total_hour += total_min / 60;
    total_min = total_min % 60;

    return ECTime(total_hour, total_min, total_sec);    
}

