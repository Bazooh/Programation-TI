
#include <math.h>
#include <stdio.h>
#include <debug.h>

void main() {
    timer_Control = TIMER1_DISABLE;
    timer_1_ReloadValue = timer_1_Counter = 0;
    timer_Control = TIMER1_ENABLE | TIMER1_32K | TIMER1_0INT | TIMER1_UP;
    while (1) {
        if (timer_IntStatus & TIMER1_RELOADED) {
            timer_IntAcknowledge = TIMER1_RELOADED;
        }
        delay(100);
        dbg_sprintf(dbgout, "timer_IntStatus      : %d\n", timer_IntStatus);
        dbg_sprintf(dbgout, "timer_IntAcknowledge : %d\n", timer_IntAcknowledge);
        dbg_sprintf(dbgout, "timer_Control        : %d\n", timer_Control);
        dbg_sprintf(dbgout, "TIMER1_DISABLE       : %d\n", TIMER1_DISABLE);
        dbg_sprintf(dbgout, "TIMER1_ENABLE        : %d\n", TIMER1_ENABLE);
        dbg_sprintf(dbgout, "TIMER1_32K           : %d\n", TIMER1_32K);
        dbg_sprintf(dbgout, "TIMER1_0INT          : %d\n", TIMER1_0INT);
        dbg_sprintf(dbgout, "TIMER1_DOWN          : %d\n", TIMER1_DOWN);
        dbg_sprintf(dbgout, "timer_1_ReloadValue  : %d\n", timer_1_ReloadValue);
        dbg_sprintf(dbgout, "timer_1_Counter      : %d\n", timer_1_Counter);
        dbg_sprintf(dbgout, "TIMER1_RELOADED      : %d\n\n", TIMER1_RELOADED);
    }
}