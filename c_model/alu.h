#ifndef ALU_H
#define ALU_H

#include <stdint.h>

/* Define enum for operations */
typedef enum 
{ 
    ADD, 
    BAND, // Bitwise AND
    BXOR // Bitwise XOR
} ALU_OP;

typedef struct 
{
    uint8_t result_bits; 
    uint8_t carry; 
} ALU_RESULT; 

/* Function declarations*/
ALU_RESULT alu_compute(uint8_t first_input, uint8_t second_input, ALU_OP operation);

#endif