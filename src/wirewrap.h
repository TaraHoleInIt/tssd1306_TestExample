#ifndef _WIREWRAP_H_
#define _WIREWRAP_H_

#if defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__) || defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
    #include <USIWire.h>
#else
    #include <Wire.h>
#endif

#endif
