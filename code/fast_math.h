#ifndef _FAST_MATH_LIB
    #define _FAST_MATH_LIB
    
    #include <config.h>
    #define ARM_MATH_CM7
    #include <arm_math.h>

    static inline float fast_math_sqrt(float num)
    {
        q31_t buffer;
        arm_float_to_q31(&num, &buffer, 1);
        arm_sqrt_q31(buffer, &buffer);
        arm_q31_to_float(&buffer, &num, 1);
        return num;
    }
#endif
