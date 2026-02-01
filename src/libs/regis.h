#ifndef REGIS_H
#define REGIS_H

// static void inp_reg(int regis, char *buff); // IN//read

static inline void write_reg(int port, int reg, int data)
{
  __asm__ volatile(             // gas inline asm
      "mov %[data],%[reg] \n\t" // instructions
      "mov 0xAh %%al \n\t"
      "out %%dx, %%al \n\t"

      "inc %%dx \n\t"
      "mov 0x20,%%al \n\t"
      "out %%dx,%%al \n\t"
      :                    // outputs
      : [port] "dx"(port), // inputs
        [reg] "r"(reg),
        [data] "al"(data)
      : "dx", "al");
}

#endif