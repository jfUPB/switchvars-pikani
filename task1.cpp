#include <Arduino.h>
#include "task1.h"

static void switchVariables(uint32_t *var, uint32_t *padata, uint32_t *pbdata)
{
    *var = *padata;
    *padata = *pbdata;
    *pbdata = *var;
}

static void printVar(const char *varName, uint32_t value)
{
    printf("%s = %d\n", varName, value);
}

void task1()
{
    enum class Task1States
    {
        INIT,
        WAIT_DATA
    };
    static Task1States task1State = Task1States::INIT;

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        task1State = Task1States::WAIT_DATA;
        break;
    }

    case Task1States::WAIT_DATA:
    {
        // evento 1:
        if (Serial.available() > 0)
        {
            Serial.read();
            uint32_t a = 10;
            uint32_t b = 20;
            uint32_t c = 0;
            uint32_t *pc = &c;
            uint32_t *pa = &a;
            uint32_t *pb = &b;
            printVar("a", a);
            printVar("b", b);            
            switchVariables(pc, pa, pb);
            printVar("a", a);
            printVar("b", b);
        }
        break;
    }

    default:
    {
        break;
    }
    }
}