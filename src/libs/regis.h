#ifndef REGIS_H
#define REGIS_H

#include "stdint.h"

// return a 8 bits integer->ex:0000 0001
static inline uint8_t inb(uint16_t port) {
  uint8_t ret;

  __asm__ volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));

  return ret;
}

static inline void outb(uint16_t port, uint16_t data) // out/write
{
  __asm__ volatile("out %0, %1" //%0:"a"(data);%1:"nd"(port)
                   :
                   : "a"(data),
                     "nd"(port)); //'a':(AL reg);'nd':(immediate or DX)
}

#endif
