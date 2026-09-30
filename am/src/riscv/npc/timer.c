#include <am.h>

#ifndef NPC_FREQ
#define NPC_FREQ 25000000
#endif

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t lo, hi;
  asm volatile ("csrr %0, mcycle"  : "=r"(lo));
  asm volatile ("csrr %0, mcycleh" : "=r"(hi));
  uint64_t cycles = (uint64_t)hi << 32 | lo;
  uptime->us = cycles * 1000000 / NPC_FREQ;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
