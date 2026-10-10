#include "alu.h"


ALU_RESULT alu_compute(uint8_t first, uint8_t second, ALU_OP operation)
{
    // Initialize a and b which mask inputs
    uint8_t a = first & 0x0F; 
    uint8_t b = second & 0x0F; 
    uint8_t addition = a + b;

    // Initialize result ouputs to 0 (bits + carry)
    ALU_RESULT output = {0}; 

    switch (operation)
    {
        case ADD: 
            output.result_bits = addition & 0x0F; 
            output.carry = (addition >> 4) & 1; 
            break;
        
        case BAND: // bitwise AND
            output.result_bits = (a & b) & 0x0F;
            output.carry = 0;
            break; 
        
        case BXOR: // bitwise XOR
            output.result_bits = (a ^ b) & 0x0F; 
            output.carry = 0;
            break;
        
        default:
            break;
    }
    return output;
}


