#include <stdio.h> 
#include "alu.h"

int test(uint8_t a, uint8_t b, ALU_OP operation)
{
    uint8_t exp_carry;
    uint8_t exp_result;

    switch (operation)
    {
        case ADD:
            exp_result = (a + b) & 0x0F;
            exp_carry = ((a + b) >> 4) & 1;
            break; 
        
        case BAND:
            exp_result = (a & b) & 0x0F;
            exp_carry = 0;
            break;
        
        case BXOR:
            exp_result = (a ^ b) & 0x0F;
            exp_carry = 0;
            break;
        
        default:
            break;
        }
    ALU_RESULT result = alu_compute(a, b, operation);
    if ((result.carry == exp_carry) && (result.result_bits == exp_result))
    {
        return 0;
    }
    return 1;
}

int main(void) 
{ 
    int failure = 0;
    ALU_OP operations[] = { ADD, BAND, BXOR};

    for (uint8_t a = 0; a < 16; a++)
    {
        for (uint8_t b = 0; b < 16; b++)
        {
            for (int index = 0; index < 3; index++)
            {
                ALU_OP operation = operations[index];
                int result = test(a, b, operation);
                if (result == 1)
                {
                    failure++;
                }
            }
        }
    }
    printf("There were %d number of failures\n", failure);
    if (failure == 0)
    {
        return 0;
    }
    else
    {
        return failure;
    }
}