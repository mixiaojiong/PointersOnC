#include <stdio.h>

void cpu_type() {
#if defined(VAX)
    return CPU_VAX;
#elif defined(M68000)
    return CPU_68000;
#else
    return CPU_UNKNOWN;
#endif
}
