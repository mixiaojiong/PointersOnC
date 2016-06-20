#include <stdio.h>

int main(void) {
    typedef union {
        unsigned short addr;
        struct {
            unsigned short dst_reg:3;
            unsigned short dst_mode:3;
            unsigned short opcode:10;
        }a;
        struct {
            unsigned short dst_reg:3;
            unsigned short dst_mode:3;
            unsigned short src_reg:3;
            unsigned short src_mode:3;
            unsigned short opcode:4;
        }b;
        struct {
            unsigned short offset:8;
            unsigned short opcode:8;
        }c;
        struct {
            unsigned short dst_reg:3;
            unsigned short dst_mode:3;
            unsigned short src_reg:3;
            unsigned short opcode:7;
        }d;
        struct {
            unsigned short opcode:16;
        }e;
    }machine_inst;
}
