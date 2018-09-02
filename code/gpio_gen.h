
/*This code was generated! Do not edit directly!*/

#ifndef PA_0_MODE
    #define PA_0_MODE      GPIO_MODE_ANALOG
    #define PA_0_PUPD      GPIO_PUPD_NONE
    #define PA_0_OSPEED    GPIO_OSPEED_LOW
    #define PA_0_OTYPE     GPIO_OTYPE_PP
    #define PA_0_AF        GPIO_AF0
    #define PA_0_DEFAULT_STATE 0
#else
    #if (PA_0_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_0_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_0_AF not defined'
        #endif
    #else
        #ifdef PA_0_AF
            #error 'PA_0_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_0_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_0_DEFAULT_STATE
            #warning 'PA_0_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_0_DEFAULT_STATE
        #define PA_0_DEFAULT_STATE 0
    #endif
    #ifndef PA_0_AF
        #define PA_0_AF GPIO_AF0
    #endif
    #ifndef PA_0_OTYPE
        #define PA_0_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_0_PUPD
        #define PA_0_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_0_OSPEED
        #define PA_0_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_1_MODE
    #define PA_1_MODE      GPIO_MODE_ANALOG
    #define PA_1_PUPD      GPIO_PUPD_NONE
    #define PA_1_OSPEED    GPIO_OSPEED_LOW
    #define PA_1_OTYPE     GPIO_OTYPE_PP
    #define PA_1_AF        GPIO_AF0
    #define PA_1_DEFAULT_STATE 0
#else
    #if (PA_1_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_1_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_1_AF not defined'
        #endif
    #else
        #ifdef PA_1_AF
            #error 'PA_1_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_1_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_1_DEFAULT_STATE
            #warning 'PA_1_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_1_DEFAULT_STATE
        #define PA_1_DEFAULT_STATE 0
    #endif
    #ifndef PA_1_AF
        #define PA_1_AF GPIO_AF0
    #endif
    #ifndef PA_1_OTYPE
        #define PA_1_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_1_PUPD
        #define PA_1_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_1_OSPEED
        #define PA_1_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_2_MODE
    #define PA_2_MODE      GPIO_MODE_ANALOG
    #define PA_2_PUPD      GPIO_PUPD_NONE
    #define PA_2_OSPEED    GPIO_OSPEED_LOW
    #define PA_2_OTYPE     GPIO_OTYPE_PP
    #define PA_2_AF        GPIO_AF0
    #define PA_2_DEFAULT_STATE 0
#else
    #if (PA_2_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_2_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_2_AF not defined'
        #endif
    #else
        #ifdef PA_2_AF
            #error 'PA_2_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_2_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_2_DEFAULT_STATE
            #warning 'PA_2_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_2_DEFAULT_STATE
        #define PA_2_DEFAULT_STATE 0
    #endif
    #ifndef PA_2_AF
        #define PA_2_AF GPIO_AF0
    #endif
    #ifndef PA_2_OTYPE
        #define PA_2_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_2_PUPD
        #define PA_2_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_2_OSPEED
        #define PA_2_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_3_MODE
    #define PA_3_MODE      GPIO_MODE_ANALOG
    #define PA_3_PUPD      GPIO_PUPD_NONE
    #define PA_3_OSPEED    GPIO_OSPEED_LOW
    #define PA_3_OTYPE     GPIO_OTYPE_PP
    #define PA_3_AF        GPIO_AF0
    #define PA_3_DEFAULT_STATE 0
#else
    #if (PA_3_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_3_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_3_AF not defined'
        #endif
    #else
        #ifdef PA_3_AF
            #error 'PA_3_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_3_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_3_DEFAULT_STATE
            #warning 'PA_3_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_3_DEFAULT_STATE
        #define PA_3_DEFAULT_STATE 0
    #endif
    #ifndef PA_3_AF
        #define PA_3_AF GPIO_AF0
    #endif
    #ifndef PA_3_OTYPE
        #define PA_3_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_3_PUPD
        #define PA_3_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_3_OSPEED
        #define PA_3_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_4_MODE
    #define PA_4_MODE      GPIO_MODE_ANALOG
    #define PA_4_PUPD      GPIO_PUPD_NONE
    #define PA_4_OSPEED    GPIO_OSPEED_LOW
    #define PA_4_OTYPE     GPIO_OTYPE_PP
    #define PA_4_AF        GPIO_AF0
    #define PA_4_DEFAULT_STATE 0
#else
    #if (PA_4_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_4_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_4_AF not defined'
        #endif
    #else
        #ifdef PA_4_AF
            #error 'PA_4_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_4_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_4_DEFAULT_STATE
            #warning 'PA_4_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_4_DEFAULT_STATE
        #define PA_4_DEFAULT_STATE 0
    #endif
    #ifndef PA_4_AF
        #define PA_4_AF GPIO_AF0
    #endif
    #ifndef PA_4_OTYPE
        #define PA_4_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_4_PUPD
        #define PA_4_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_4_OSPEED
        #define PA_4_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_5_MODE
    #define PA_5_MODE      GPIO_MODE_ANALOG
    #define PA_5_PUPD      GPIO_PUPD_NONE
    #define PA_5_OSPEED    GPIO_OSPEED_LOW
    #define PA_5_OTYPE     GPIO_OTYPE_PP
    #define PA_5_AF        GPIO_AF0
    #define PA_5_DEFAULT_STATE 0
#else
    #if (PA_5_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_5_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_5_AF not defined'
        #endif
    #else
        #ifdef PA_5_AF
            #error 'PA_5_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_5_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_5_DEFAULT_STATE
            #warning 'PA_5_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_5_DEFAULT_STATE
        #define PA_5_DEFAULT_STATE 0
    #endif
    #ifndef PA_5_AF
        #define PA_5_AF GPIO_AF0
    #endif
    #ifndef PA_5_OTYPE
        #define PA_5_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_5_PUPD
        #define PA_5_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_5_OSPEED
        #define PA_5_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_6_MODE
    #define PA_6_MODE      GPIO_MODE_ANALOG
    #define PA_6_PUPD      GPIO_PUPD_NONE
    #define PA_6_OSPEED    GPIO_OSPEED_LOW
    #define PA_6_OTYPE     GPIO_OTYPE_PP
    #define PA_6_AF        GPIO_AF0
    #define PA_6_DEFAULT_STATE 0
#else
    #if (PA_6_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_6_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_6_AF not defined'
        #endif
    #else
        #ifdef PA_6_AF
            #error 'PA_6_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_6_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_6_DEFAULT_STATE
            #warning 'PA_6_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_6_DEFAULT_STATE
        #define PA_6_DEFAULT_STATE 0
    #endif
    #ifndef PA_6_AF
        #define PA_6_AF GPIO_AF0
    #endif
    #ifndef PA_6_OTYPE
        #define PA_6_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_6_PUPD
        #define PA_6_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_6_OSPEED
        #define PA_6_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_7_MODE
    #define PA_7_MODE      GPIO_MODE_ANALOG
    #define PA_7_PUPD      GPIO_PUPD_NONE
    #define PA_7_OSPEED    GPIO_OSPEED_LOW
    #define PA_7_OTYPE     GPIO_OTYPE_PP
    #define PA_7_AF        GPIO_AF0
    #define PA_7_DEFAULT_STATE 0
#else
    #if (PA_7_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_7_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_7_AF not defined'
        #endif
    #else
        #ifdef PA_7_AF
            #error 'PA_7_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_7_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_7_DEFAULT_STATE
            #warning 'PA_7_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_7_DEFAULT_STATE
        #define PA_7_DEFAULT_STATE 0
    #endif
    #ifndef PA_7_AF
        #define PA_7_AF GPIO_AF0
    #endif
    #ifndef PA_7_OTYPE
        #define PA_7_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_7_PUPD
        #define PA_7_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_7_OSPEED
        #define PA_7_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_8_MODE
    #define PA_8_MODE      GPIO_MODE_ANALOG
    #define PA_8_PUPD      GPIO_PUPD_NONE
    #define PA_8_OSPEED    GPIO_OSPEED_LOW
    #define PA_8_OTYPE     GPIO_OTYPE_PP
    #define PA_8_AF        GPIO_AF0
    #define PA_8_DEFAULT_STATE 0
#else
    #if (PA_8_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_8_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_8_AF not defined'
        #endif
    #else
        #ifdef PA_8_AF
            #error 'PA_8_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_8_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_8_DEFAULT_STATE
            #warning 'PA_8_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_8_DEFAULT_STATE
        #define PA_8_DEFAULT_STATE 0
    #endif
    #ifndef PA_8_AF
        #define PA_8_AF GPIO_AF0
    #endif
    #ifndef PA_8_OTYPE
        #define PA_8_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_8_PUPD
        #define PA_8_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_8_OSPEED
        #define PA_8_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_9_MODE
    #define PA_9_MODE      GPIO_MODE_ANALOG
    #define PA_9_PUPD      GPIO_PUPD_NONE
    #define PA_9_OSPEED    GPIO_OSPEED_LOW
    #define PA_9_OTYPE     GPIO_OTYPE_PP
    #define PA_9_AF        GPIO_AF0
    #define PA_9_DEFAULT_STATE 0
#else
    #if (PA_9_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_9_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_9_AF not defined'
        #endif
    #else
        #ifdef PA_9_AF
            #error 'PA_9_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_9_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_9_DEFAULT_STATE
            #warning 'PA_9_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_9_DEFAULT_STATE
        #define PA_9_DEFAULT_STATE 0
    #endif
    #ifndef PA_9_AF
        #define PA_9_AF GPIO_AF0
    #endif
    #ifndef PA_9_OTYPE
        #define PA_9_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_9_PUPD
        #define PA_9_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_9_OSPEED
        #define PA_9_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_10_MODE
    #define PA_10_MODE      GPIO_MODE_ANALOG
    #define PA_10_PUPD      GPIO_PUPD_NONE
    #define PA_10_OSPEED    GPIO_OSPEED_LOW
    #define PA_10_OTYPE     GPIO_OTYPE_PP
    #define PA_10_AF        GPIO_AF0
    #define PA_10_DEFAULT_STATE 0
#else
    #if (PA_10_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_10_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_10_AF not defined'
        #endif
    #else
        #ifdef PA_10_AF
            #error 'PA_10_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_10_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_10_DEFAULT_STATE
            #warning 'PA_10_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_10_DEFAULT_STATE
        #define PA_10_DEFAULT_STATE 0
    #endif
    #ifndef PA_10_AF
        #define PA_10_AF GPIO_AF0
    #endif
    #ifndef PA_10_OTYPE
        #define PA_10_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_10_PUPD
        #define PA_10_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_10_OSPEED
        #define PA_10_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_11_MODE
    #define PA_11_MODE      GPIO_MODE_ANALOG
    #define PA_11_PUPD      GPIO_PUPD_NONE
    #define PA_11_OSPEED    GPIO_OSPEED_LOW
    #define PA_11_OTYPE     GPIO_OTYPE_PP
    #define PA_11_AF        GPIO_AF0
    #define PA_11_DEFAULT_STATE 0
#else
    #if (PA_11_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_11_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_11_AF not defined'
        #endif
    #else
        #ifdef PA_11_AF
            #error 'PA_11_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_11_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_11_DEFAULT_STATE
            #warning 'PA_11_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_11_DEFAULT_STATE
        #define PA_11_DEFAULT_STATE 0
    #endif
    #ifndef PA_11_AF
        #define PA_11_AF GPIO_AF0
    #endif
    #ifndef PA_11_OTYPE
        #define PA_11_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_11_PUPD
        #define PA_11_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_11_OSPEED
        #define PA_11_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_12_MODE
    #define PA_12_MODE      GPIO_MODE_ANALOG
    #define PA_12_PUPD      GPIO_PUPD_NONE
    #define PA_12_OSPEED    GPIO_OSPEED_LOW
    #define PA_12_OTYPE     GPIO_OTYPE_PP
    #define PA_12_AF        GPIO_AF0
    #define PA_12_DEFAULT_STATE 0
#else
    #if (PA_12_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_12_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_12_AF not defined'
        #endif
    #else
        #ifdef PA_12_AF
            #error 'PA_12_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_12_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_12_DEFAULT_STATE
            #warning 'PA_12_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_12_DEFAULT_STATE
        #define PA_12_DEFAULT_STATE 0
    #endif
    #ifndef PA_12_AF
        #define PA_12_AF GPIO_AF0
    #endif
    #ifndef PA_12_OTYPE
        #define PA_12_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_12_PUPD
        #define PA_12_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_12_OSPEED
        #define PA_12_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_13_MODE
    #define PA_13_MODE      GPIO_MODE_ANALOG
    #define PA_13_PUPD      GPIO_PUPD_NONE
    #define PA_13_OSPEED    GPIO_OSPEED_LOW
    #define PA_13_OTYPE     GPIO_OTYPE_PP
    #define PA_13_AF        GPIO_AF0
    #define PA_13_DEFAULT_STATE 0
#else
    #if (PA_13_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_13_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_13_AF not defined'
        #endif
    #else
        #ifdef PA_13_AF
            #error 'PA_13_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_13_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_13_DEFAULT_STATE
            #warning 'PA_13_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_13_DEFAULT_STATE
        #define PA_13_DEFAULT_STATE 0
    #endif
    #ifndef PA_13_AF
        #define PA_13_AF GPIO_AF0
    #endif
    #ifndef PA_13_OTYPE
        #define PA_13_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_13_PUPD
        #define PA_13_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_13_OSPEED
        #define PA_13_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_14_MODE
    #define PA_14_MODE      GPIO_MODE_ANALOG
    #define PA_14_PUPD      GPIO_PUPD_NONE
    #define PA_14_OSPEED    GPIO_OSPEED_LOW
    #define PA_14_OTYPE     GPIO_OTYPE_PP
    #define PA_14_AF        GPIO_AF0
    #define PA_14_DEFAULT_STATE 0
#else
    #if (PA_14_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_14_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_14_AF not defined'
        #endif
    #else
        #ifdef PA_14_AF
            #error 'PA_14_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_14_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_14_DEFAULT_STATE
            #warning 'PA_14_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_14_DEFAULT_STATE
        #define PA_14_DEFAULT_STATE 0
    #endif
    #ifndef PA_14_AF
        #define PA_14_AF GPIO_AF0
    #endif
    #ifndef PA_14_OTYPE
        #define PA_14_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_14_PUPD
        #define PA_14_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_14_OSPEED
        #define PA_14_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PA_15_MODE
    #define PA_15_MODE      GPIO_MODE_ANALOG
    #define PA_15_PUPD      GPIO_PUPD_NONE
    #define PA_15_OSPEED    GPIO_OSPEED_LOW
    #define PA_15_OTYPE     GPIO_OTYPE_PP
    #define PA_15_AF        GPIO_AF0
    #define PA_15_DEFAULT_STATE 0
#else
    #if (PA_15_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PA_15_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PA_15_AF not defined'
        #endif
    #else
        #ifdef PA_15_AF
            #error 'PA_15_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PA_15_MODE == GPIO_MODE_OUTPUT)
        #ifndef PA_15_DEFAULT_STATE
            #warning 'PA_15_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PA_15_DEFAULT_STATE
        #define PA_15_DEFAULT_STATE 0
    #endif
    #ifndef PA_15_AF
        #define PA_15_AF GPIO_AF0
    #endif
    #ifndef PA_15_OTYPE
        #define PA_15_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PA_15_PUPD
        #define PA_15_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PA_15_OSPEED
        #define PA_15_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_0_MODE
    #define PB_0_MODE      GPIO_MODE_ANALOG
    #define PB_0_PUPD      GPIO_PUPD_NONE
    #define PB_0_OSPEED    GPIO_OSPEED_LOW
    #define PB_0_OTYPE     GPIO_OTYPE_PP
    #define PB_0_AF        GPIO_AF0
    #define PB_0_DEFAULT_STATE 0
#else
    #if (PB_0_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_0_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_0_AF not defined'
        #endif
    #else
        #ifdef PB_0_AF
            #error 'PB_0_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_0_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_0_DEFAULT_STATE
            #warning 'PB_0_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_0_DEFAULT_STATE
        #define PB_0_DEFAULT_STATE 0
    #endif
    #ifndef PB_0_AF
        #define PB_0_AF GPIO_AF0
    #endif
    #ifndef PB_0_OTYPE
        #define PB_0_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_0_PUPD
        #define PB_0_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_0_OSPEED
        #define PB_0_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_1_MODE
    #define PB_1_MODE      GPIO_MODE_ANALOG
    #define PB_1_PUPD      GPIO_PUPD_NONE
    #define PB_1_OSPEED    GPIO_OSPEED_LOW
    #define PB_1_OTYPE     GPIO_OTYPE_PP
    #define PB_1_AF        GPIO_AF0
    #define PB_1_DEFAULT_STATE 0
#else
    #if (PB_1_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_1_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_1_AF not defined'
        #endif
    #else
        #ifdef PB_1_AF
            #error 'PB_1_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_1_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_1_DEFAULT_STATE
            #warning 'PB_1_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_1_DEFAULT_STATE
        #define PB_1_DEFAULT_STATE 0
    #endif
    #ifndef PB_1_AF
        #define PB_1_AF GPIO_AF0
    #endif
    #ifndef PB_1_OTYPE
        #define PB_1_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_1_PUPD
        #define PB_1_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_1_OSPEED
        #define PB_1_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_2_MODE
    #define PB_2_MODE      GPIO_MODE_ANALOG
    #define PB_2_PUPD      GPIO_PUPD_NONE
    #define PB_2_OSPEED    GPIO_OSPEED_LOW
    #define PB_2_OTYPE     GPIO_OTYPE_PP
    #define PB_2_AF        GPIO_AF0
    #define PB_2_DEFAULT_STATE 0
#else
    #if (PB_2_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_2_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_2_AF not defined'
        #endif
    #else
        #ifdef PB_2_AF
            #error 'PB_2_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_2_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_2_DEFAULT_STATE
            #warning 'PB_2_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_2_DEFAULT_STATE
        #define PB_2_DEFAULT_STATE 0
    #endif
    #ifndef PB_2_AF
        #define PB_2_AF GPIO_AF0
    #endif
    #ifndef PB_2_OTYPE
        #define PB_2_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_2_PUPD
        #define PB_2_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_2_OSPEED
        #define PB_2_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_3_MODE
    #define PB_3_MODE      GPIO_MODE_ANALOG
    #define PB_3_PUPD      GPIO_PUPD_NONE
    #define PB_3_OSPEED    GPIO_OSPEED_LOW
    #define PB_3_OTYPE     GPIO_OTYPE_PP
    #define PB_3_AF        GPIO_AF0
    #define PB_3_DEFAULT_STATE 0
#else
    #if (PB_3_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_3_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_3_AF not defined'
        #endif
    #else
        #ifdef PB_3_AF
            #error 'PB_3_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_3_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_3_DEFAULT_STATE
            #warning 'PB_3_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_3_DEFAULT_STATE
        #define PB_3_DEFAULT_STATE 0
    #endif
    #ifndef PB_3_AF
        #define PB_3_AF GPIO_AF0
    #endif
    #ifndef PB_3_OTYPE
        #define PB_3_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_3_PUPD
        #define PB_3_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_3_OSPEED
        #define PB_3_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_4_MODE
    #define PB_4_MODE      GPIO_MODE_ANALOG
    #define PB_4_PUPD      GPIO_PUPD_NONE
    #define PB_4_OSPEED    GPIO_OSPEED_LOW
    #define PB_4_OTYPE     GPIO_OTYPE_PP
    #define PB_4_AF        GPIO_AF0
    #define PB_4_DEFAULT_STATE 0
#else
    #if (PB_4_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_4_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_4_AF not defined'
        #endif
    #else
        #ifdef PB_4_AF
            #error 'PB_4_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_4_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_4_DEFAULT_STATE
            #warning 'PB_4_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_4_DEFAULT_STATE
        #define PB_4_DEFAULT_STATE 0
    #endif
    #ifndef PB_4_AF
        #define PB_4_AF GPIO_AF0
    #endif
    #ifndef PB_4_OTYPE
        #define PB_4_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_4_PUPD
        #define PB_4_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_4_OSPEED
        #define PB_4_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_5_MODE
    #define PB_5_MODE      GPIO_MODE_ANALOG
    #define PB_5_PUPD      GPIO_PUPD_NONE
    #define PB_5_OSPEED    GPIO_OSPEED_LOW
    #define PB_5_OTYPE     GPIO_OTYPE_PP
    #define PB_5_AF        GPIO_AF0
    #define PB_5_DEFAULT_STATE 0
#else
    #if (PB_5_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_5_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_5_AF not defined'
        #endif
    #else
        #ifdef PB_5_AF
            #error 'PB_5_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_5_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_5_DEFAULT_STATE
            #warning 'PB_5_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_5_DEFAULT_STATE
        #define PB_5_DEFAULT_STATE 0
    #endif
    #ifndef PB_5_AF
        #define PB_5_AF GPIO_AF0
    #endif
    #ifndef PB_5_OTYPE
        #define PB_5_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_5_PUPD
        #define PB_5_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_5_OSPEED
        #define PB_5_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_6_MODE
    #define PB_6_MODE      GPIO_MODE_ANALOG
    #define PB_6_PUPD      GPIO_PUPD_NONE
    #define PB_6_OSPEED    GPIO_OSPEED_LOW
    #define PB_6_OTYPE     GPIO_OTYPE_PP
    #define PB_6_AF        GPIO_AF0
    #define PB_6_DEFAULT_STATE 0
#else
    #if (PB_6_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_6_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_6_AF not defined'
        #endif
    #else
        #ifdef PB_6_AF
            #error 'PB_6_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_6_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_6_DEFAULT_STATE
            #warning 'PB_6_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_6_DEFAULT_STATE
        #define PB_6_DEFAULT_STATE 0
    #endif
    #ifndef PB_6_AF
        #define PB_6_AF GPIO_AF0
    #endif
    #ifndef PB_6_OTYPE
        #define PB_6_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_6_PUPD
        #define PB_6_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_6_OSPEED
        #define PB_6_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_7_MODE
    #define PB_7_MODE      GPIO_MODE_ANALOG
    #define PB_7_PUPD      GPIO_PUPD_NONE
    #define PB_7_OSPEED    GPIO_OSPEED_LOW
    #define PB_7_OTYPE     GPIO_OTYPE_PP
    #define PB_7_AF        GPIO_AF0
    #define PB_7_DEFAULT_STATE 0
#else
    #if (PB_7_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_7_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_7_AF not defined'
        #endif
    #else
        #ifdef PB_7_AF
            #error 'PB_7_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_7_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_7_DEFAULT_STATE
            #warning 'PB_7_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_7_DEFAULT_STATE
        #define PB_7_DEFAULT_STATE 0
    #endif
    #ifndef PB_7_AF
        #define PB_7_AF GPIO_AF0
    #endif
    #ifndef PB_7_OTYPE
        #define PB_7_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_7_PUPD
        #define PB_7_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_7_OSPEED
        #define PB_7_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_8_MODE
    #define PB_8_MODE      GPIO_MODE_ANALOG
    #define PB_8_PUPD      GPIO_PUPD_NONE
    #define PB_8_OSPEED    GPIO_OSPEED_LOW
    #define PB_8_OTYPE     GPIO_OTYPE_PP
    #define PB_8_AF        GPIO_AF0
    #define PB_8_DEFAULT_STATE 0
#else
    #if (PB_8_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_8_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_8_AF not defined'
        #endif
    #else
        #ifdef PB_8_AF
            #error 'PB_8_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_8_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_8_DEFAULT_STATE
            #warning 'PB_8_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_8_DEFAULT_STATE
        #define PB_8_DEFAULT_STATE 0
    #endif
    #ifndef PB_8_AF
        #define PB_8_AF GPIO_AF0
    #endif
    #ifndef PB_8_OTYPE
        #define PB_8_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_8_PUPD
        #define PB_8_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_8_OSPEED
        #define PB_8_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_9_MODE
    #define PB_9_MODE      GPIO_MODE_ANALOG
    #define PB_9_PUPD      GPIO_PUPD_NONE
    #define PB_9_OSPEED    GPIO_OSPEED_LOW
    #define PB_9_OTYPE     GPIO_OTYPE_PP
    #define PB_9_AF        GPIO_AF0
    #define PB_9_DEFAULT_STATE 0
#else
    #if (PB_9_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_9_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_9_AF not defined'
        #endif
    #else
        #ifdef PB_9_AF
            #error 'PB_9_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_9_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_9_DEFAULT_STATE
            #warning 'PB_9_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_9_DEFAULT_STATE
        #define PB_9_DEFAULT_STATE 0
    #endif
    #ifndef PB_9_AF
        #define PB_9_AF GPIO_AF0
    #endif
    #ifndef PB_9_OTYPE
        #define PB_9_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_9_PUPD
        #define PB_9_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_9_OSPEED
        #define PB_9_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_10_MODE
    #define PB_10_MODE      GPIO_MODE_ANALOG
    #define PB_10_PUPD      GPIO_PUPD_NONE
    #define PB_10_OSPEED    GPIO_OSPEED_LOW
    #define PB_10_OTYPE     GPIO_OTYPE_PP
    #define PB_10_AF        GPIO_AF0
    #define PB_10_DEFAULT_STATE 0
#else
    #if (PB_10_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_10_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_10_AF not defined'
        #endif
    #else
        #ifdef PB_10_AF
            #error 'PB_10_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_10_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_10_DEFAULT_STATE
            #warning 'PB_10_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_10_DEFAULT_STATE
        #define PB_10_DEFAULT_STATE 0
    #endif
    #ifndef PB_10_AF
        #define PB_10_AF GPIO_AF0
    #endif
    #ifndef PB_10_OTYPE
        #define PB_10_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_10_PUPD
        #define PB_10_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_10_OSPEED
        #define PB_10_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_11_MODE
    #define PB_11_MODE      GPIO_MODE_ANALOG
    #define PB_11_PUPD      GPIO_PUPD_NONE
    #define PB_11_OSPEED    GPIO_OSPEED_LOW
    #define PB_11_OTYPE     GPIO_OTYPE_PP
    #define PB_11_AF        GPIO_AF0
    #define PB_11_DEFAULT_STATE 0
#else
    #if (PB_11_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_11_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_11_AF not defined'
        #endif
    #else
        #ifdef PB_11_AF
            #error 'PB_11_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_11_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_11_DEFAULT_STATE
            #warning 'PB_11_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_11_DEFAULT_STATE
        #define PB_11_DEFAULT_STATE 0
    #endif
    #ifndef PB_11_AF
        #define PB_11_AF GPIO_AF0
    #endif
    #ifndef PB_11_OTYPE
        #define PB_11_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_11_PUPD
        #define PB_11_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_11_OSPEED
        #define PB_11_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_12_MODE
    #define PB_12_MODE      GPIO_MODE_ANALOG
    #define PB_12_PUPD      GPIO_PUPD_NONE
    #define PB_12_OSPEED    GPIO_OSPEED_LOW
    #define PB_12_OTYPE     GPIO_OTYPE_PP
    #define PB_12_AF        GPIO_AF0
    #define PB_12_DEFAULT_STATE 0
#else
    #if (PB_12_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_12_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_12_AF not defined'
        #endif
    #else
        #ifdef PB_12_AF
            #error 'PB_12_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_12_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_12_DEFAULT_STATE
            #warning 'PB_12_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_12_DEFAULT_STATE
        #define PB_12_DEFAULT_STATE 0
    #endif
    #ifndef PB_12_AF
        #define PB_12_AF GPIO_AF0
    #endif
    #ifndef PB_12_OTYPE
        #define PB_12_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_12_PUPD
        #define PB_12_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_12_OSPEED
        #define PB_12_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_13_MODE
    #define PB_13_MODE      GPIO_MODE_ANALOG
    #define PB_13_PUPD      GPIO_PUPD_NONE
    #define PB_13_OSPEED    GPIO_OSPEED_LOW
    #define PB_13_OTYPE     GPIO_OTYPE_PP
    #define PB_13_AF        GPIO_AF0
    #define PB_13_DEFAULT_STATE 0
#else
    #if (PB_13_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_13_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_13_AF not defined'
        #endif
    #else
        #ifdef PB_13_AF
            #error 'PB_13_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_13_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_13_DEFAULT_STATE
            #warning 'PB_13_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_13_DEFAULT_STATE
        #define PB_13_DEFAULT_STATE 0
    #endif
    #ifndef PB_13_AF
        #define PB_13_AF GPIO_AF0
    #endif
    #ifndef PB_13_OTYPE
        #define PB_13_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_13_PUPD
        #define PB_13_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_13_OSPEED
        #define PB_13_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_14_MODE
    #define PB_14_MODE      GPIO_MODE_ANALOG
    #define PB_14_PUPD      GPIO_PUPD_NONE
    #define PB_14_OSPEED    GPIO_OSPEED_LOW
    #define PB_14_OTYPE     GPIO_OTYPE_PP
    #define PB_14_AF        GPIO_AF0
    #define PB_14_DEFAULT_STATE 0
#else
    #if (PB_14_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_14_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_14_AF not defined'
        #endif
    #else
        #ifdef PB_14_AF
            #error 'PB_14_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_14_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_14_DEFAULT_STATE
            #warning 'PB_14_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_14_DEFAULT_STATE
        #define PB_14_DEFAULT_STATE 0
    #endif
    #ifndef PB_14_AF
        #define PB_14_AF GPIO_AF0
    #endif
    #ifndef PB_14_OTYPE
        #define PB_14_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_14_PUPD
        #define PB_14_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_14_OSPEED
        #define PB_14_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PB_15_MODE
    #define PB_15_MODE      GPIO_MODE_ANALOG
    #define PB_15_PUPD      GPIO_PUPD_NONE
    #define PB_15_OSPEED    GPIO_OSPEED_LOW
    #define PB_15_OTYPE     GPIO_OTYPE_PP
    #define PB_15_AF        GPIO_AF0
    #define PB_15_DEFAULT_STATE 0
#else
    #if (PB_15_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PB_15_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PB_15_AF not defined'
        #endif
    #else
        #ifdef PB_15_AF
            #error 'PB_15_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PB_15_MODE == GPIO_MODE_OUTPUT)
        #ifndef PB_15_DEFAULT_STATE
            #warning 'PB_15_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PB_15_DEFAULT_STATE
        #define PB_15_DEFAULT_STATE 0
    #endif
    #ifndef PB_15_AF
        #define PB_15_AF GPIO_AF0
    #endif
    #ifndef PB_15_OTYPE
        #define PB_15_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PB_15_PUPD
        #define PB_15_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PB_15_OSPEED
        #define PB_15_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_0_MODE
    #define PC_0_MODE      GPIO_MODE_ANALOG
    #define PC_0_PUPD      GPIO_PUPD_NONE
    #define PC_0_OSPEED    GPIO_OSPEED_LOW
    #define PC_0_OTYPE     GPIO_OTYPE_PP
    #define PC_0_AF        GPIO_AF0
    #define PC_0_DEFAULT_STATE 0
#else
    #if (PC_0_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_0_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_0_AF not defined'
        #endif
    #else
        #ifdef PC_0_AF
            #error 'PC_0_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_0_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_0_DEFAULT_STATE
            #warning 'PC_0_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_0_DEFAULT_STATE
        #define PC_0_DEFAULT_STATE 0
    #endif
    #ifndef PC_0_AF
        #define PC_0_AF GPIO_AF0
    #endif
    #ifndef PC_0_OTYPE
        #define PC_0_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_0_PUPD
        #define PC_0_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_0_OSPEED
        #define PC_0_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_1_MODE
    #define PC_1_MODE      GPIO_MODE_ANALOG
    #define PC_1_PUPD      GPIO_PUPD_NONE
    #define PC_1_OSPEED    GPIO_OSPEED_LOW
    #define PC_1_OTYPE     GPIO_OTYPE_PP
    #define PC_1_AF        GPIO_AF0
    #define PC_1_DEFAULT_STATE 0
#else
    #if (PC_1_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_1_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_1_AF not defined'
        #endif
    #else
        #ifdef PC_1_AF
            #error 'PC_1_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_1_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_1_DEFAULT_STATE
            #warning 'PC_1_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_1_DEFAULT_STATE
        #define PC_1_DEFAULT_STATE 0
    #endif
    #ifndef PC_1_AF
        #define PC_1_AF GPIO_AF0
    #endif
    #ifndef PC_1_OTYPE
        #define PC_1_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_1_PUPD
        #define PC_1_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_1_OSPEED
        #define PC_1_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_2_MODE
    #define PC_2_MODE      GPIO_MODE_ANALOG
    #define PC_2_PUPD      GPIO_PUPD_NONE
    #define PC_2_OSPEED    GPIO_OSPEED_LOW
    #define PC_2_OTYPE     GPIO_OTYPE_PP
    #define PC_2_AF        GPIO_AF0
    #define PC_2_DEFAULT_STATE 0
#else
    #if (PC_2_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_2_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_2_AF not defined'
        #endif
    #else
        #ifdef PC_2_AF
            #error 'PC_2_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_2_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_2_DEFAULT_STATE
            #warning 'PC_2_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_2_DEFAULT_STATE
        #define PC_2_DEFAULT_STATE 0
    #endif
    #ifndef PC_2_AF
        #define PC_2_AF GPIO_AF0
    #endif
    #ifndef PC_2_OTYPE
        #define PC_2_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_2_PUPD
        #define PC_2_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_2_OSPEED
        #define PC_2_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_3_MODE
    #define PC_3_MODE      GPIO_MODE_ANALOG
    #define PC_3_PUPD      GPIO_PUPD_NONE
    #define PC_3_OSPEED    GPIO_OSPEED_LOW
    #define PC_3_OTYPE     GPIO_OTYPE_PP
    #define PC_3_AF        GPIO_AF0
    #define PC_3_DEFAULT_STATE 0
#else
    #if (PC_3_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_3_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_3_AF not defined'
        #endif
    #else
        #ifdef PC_3_AF
            #error 'PC_3_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_3_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_3_DEFAULT_STATE
            #warning 'PC_3_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_3_DEFAULT_STATE
        #define PC_3_DEFAULT_STATE 0
    #endif
    #ifndef PC_3_AF
        #define PC_3_AF GPIO_AF0
    #endif
    #ifndef PC_3_OTYPE
        #define PC_3_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_3_PUPD
        #define PC_3_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_3_OSPEED
        #define PC_3_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_4_MODE
    #define PC_4_MODE      GPIO_MODE_ANALOG
    #define PC_4_PUPD      GPIO_PUPD_NONE
    #define PC_4_OSPEED    GPIO_OSPEED_LOW
    #define PC_4_OTYPE     GPIO_OTYPE_PP
    #define PC_4_AF        GPIO_AF0
    #define PC_4_DEFAULT_STATE 0
#else
    #if (PC_4_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_4_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_4_AF not defined'
        #endif
    #else
        #ifdef PC_4_AF
            #error 'PC_4_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_4_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_4_DEFAULT_STATE
            #warning 'PC_4_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_4_DEFAULT_STATE
        #define PC_4_DEFAULT_STATE 0
    #endif
    #ifndef PC_4_AF
        #define PC_4_AF GPIO_AF0
    #endif
    #ifndef PC_4_OTYPE
        #define PC_4_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_4_PUPD
        #define PC_4_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_4_OSPEED
        #define PC_4_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_5_MODE
    #define PC_5_MODE      GPIO_MODE_ANALOG
    #define PC_5_PUPD      GPIO_PUPD_NONE
    #define PC_5_OSPEED    GPIO_OSPEED_LOW
    #define PC_5_OTYPE     GPIO_OTYPE_PP
    #define PC_5_AF        GPIO_AF0
    #define PC_5_DEFAULT_STATE 0
#else
    #if (PC_5_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_5_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_5_AF not defined'
        #endif
    #else
        #ifdef PC_5_AF
            #error 'PC_5_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_5_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_5_DEFAULT_STATE
            #warning 'PC_5_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_5_DEFAULT_STATE
        #define PC_5_DEFAULT_STATE 0
    #endif
    #ifndef PC_5_AF
        #define PC_5_AF GPIO_AF0
    #endif
    #ifndef PC_5_OTYPE
        #define PC_5_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_5_PUPD
        #define PC_5_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_5_OSPEED
        #define PC_5_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_6_MODE
    #define PC_6_MODE      GPIO_MODE_ANALOG
    #define PC_6_PUPD      GPIO_PUPD_NONE
    #define PC_6_OSPEED    GPIO_OSPEED_LOW
    #define PC_6_OTYPE     GPIO_OTYPE_PP
    #define PC_6_AF        GPIO_AF0
    #define PC_6_DEFAULT_STATE 0
#else
    #if (PC_6_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_6_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_6_AF not defined'
        #endif
    #else
        #ifdef PC_6_AF
            #error 'PC_6_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_6_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_6_DEFAULT_STATE
            #warning 'PC_6_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_6_DEFAULT_STATE
        #define PC_6_DEFAULT_STATE 0
    #endif
    #ifndef PC_6_AF
        #define PC_6_AF GPIO_AF0
    #endif
    #ifndef PC_6_OTYPE
        #define PC_6_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_6_PUPD
        #define PC_6_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_6_OSPEED
        #define PC_6_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_7_MODE
    #define PC_7_MODE      GPIO_MODE_ANALOG
    #define PC_7_PUPD      GPIO_PUPD_NONE
    #define PC_7_OSPEED    GPIO_OSPEED_LOW
    #define PC_7_OTYPE     GPIO_OTYPE_PP
    #define PC_7_AF        GPIO_AF0
    #define PC_7_DEFAULT_STATE 0
#else
    #if (PC_7_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_7_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_7_AF not defined'
        #endif
    #else
        #ifdef PC_7_AF
            #error 'PC_7_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_7_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_7_DEFAULT_STATE
            #warning 'PC_7_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_7_DEFAULT_STATE
        #define PC_7_DEFAULT_STATE 0
    #endif
    #ifndef PC_7_AF
        #define PC_7_AF GPIO_AF0
    #endif
    #ifndef PC_7_OTYPE
        #define PC_7_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_7_PUPD
        #define PC_7_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_7_OSPEED
        #define PC_7_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_8_MODE
    #define PC_8_MODE      GPIO_MODE_ANALOG
    #define PC_8_PUPD      GPIO_PUPD_NONE
    #define PC_8_OSPEED    GPIO_OSPEED_LOW
    #define PC_8_OTYPE     GPIO_OTYPE_PP
    #define PC_8_AF        GPIO_AF0
    #define PC_8_DEFAULT_STATE 0
#else
    #if (PC_8_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_8_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_8_AF not defined'
        #endif
    #else
        #ifdef PC_8_AF
            #error 'PC_8_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_8_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_8_DEFAULT_STATE
            #warning 'PC_8_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_8_DEFAULT_STATE
        #define PC_8_DEFAULT_STATE 0
    #endif
    #ifndef PC_8_AF
        #define PC_8_AF GPIO_AF0
    #endif
    #ifndef PC_8_OTYPE
        #define PC_8_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_8_PUPD
        #define PC_8_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_8_OSPEED
        #define PC_8_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_9_MODE
    #define PC_9_MODE      GPIO_MODE_ANALOG
    #define PC_9_PUPD      GPIO_PUPD_NONE
    #define PC_9_OSPEED    GPIO_OSPEED_LOW
    #define PC_9_OTYPE     GPIO_OTYPE_PP
    #define PC_9_AF        GPIO_AF0
    #define PC_9_DEFAULT_STATE 0
#else
    #if (PC_9_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_9_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_9_AF not defined'
        #endif
    #else
        #ifdef PC_9_AF
            #error 'PC_9_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_9_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_9_DEFAULT_STATE
            #warning 'PC_9_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_9_DEFAULT_STATE
        #define PC_9_DEFAULT_STATE 0
    #endif
    #ifndef PC_9_AF
        #define PC_9_AF GPIO_AF0
    #endif
    #ifndef PC_9_OTYPE
        #define PC_9_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_9_PUPD
        #define PC_9_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_9_OSPEED
        #define PC_9_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_10_MODE
    #define PC_10_MODE      GPIO_MODE_ANALOG
    #define PC_10_PUPD      GPIO_PUPD_NONE
    #define PC_10_OSPEED    GPIO_OSPEED_LOW
    #define PC_10_OTYPE     GPIO_OTYPE_PP
    #define PC_10_AF        GPIO_AF0
    #define PC_10_DEFAULT_STATE 0
#else
    #if (PC_10_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_10_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_10_AF not defined'
        #endif
    #else
        #ifdef PC_10_AF
            #error 'PC_10_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_10_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_10_DEFAULT_STATE
            #warning 'PC_10_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_10_DEFAULT_STATE
        #define PC_10_DEFAULT_STATE 0
    #endif
    #ifndef PC_10_AF
        #define PC_10_AF GPIO_AF0
    #endif
    #ifndef PC_10_OTYPE
        #define PC_10_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_10_PUPD
        #define PC_10_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_10_OSPEED
        #define PC_10_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_11_MODE
    #define PC_11_MODE      GPIO_MODE_ANALOG
    #define PC_11_PUPD      GPIO_PUPD_NONE
    #define PC_11_OSPEED    GPIO_OSPEED_LOW
    #define PC_11_OTYPE     GPIO_OTYPE_PP
    #define PC_11_AF        GPIO_AF0
    #define PC_11_DEFAULT_STATE 0
#else
    #if (PC_11_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_11_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_11_AF not defined'
        #endif
    #else
        #ifdef PC_11_AF
            #error 'PC_11_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_11_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_11_DEFAULT_STATE
            #warning 'PC_11_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_11_DEFAULT_STATE
        #define PC_11_DEFAULT_STATE 0
    #endif
    #ifndef PC_11_AF
        #define PC_11_AF GPIO_AF0
    #endif
    #ifndef PC_11_OTYPE
        #define PC_11_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_11_PUPD
        #define PC_11_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_11_OSPEED
        #define PC_11_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_12_MODE
    #define PC_12_MODE      GPIO_MODE_ANALOG
    #define PC_12_PUPD      GPIO_PUPD_NONE
    #define PC_12_OSPEED    GPIO_OSPEED_LOW
    #define PC_12_OTYPE     GPIO_OTYPE_PP
    #define PC_12_AF        GPIO_AF0
    #define PC_12_DEFAULT_STATE 0
#else
    #if (PC_12_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_12_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_12_AF not defined'
        #endif
    #else
        #ifdef PC_12_AF
            #error 'PC_12_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_12_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_12_DEFAULT_STATE
            #warning 'PC_12_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_12_DEFAULT_STATE
        #define PC_12_DEFAULT_STATE 0
    #endif
    #ifndef PC_12_AF
        #define PC_12_AF GPIO_AF0
    #endif
    #ifndef PC_12_OTYPE
        #define PC_12_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_12_PUPD
        #define PC_12_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_12_OSPEED
        #define PC_12_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_13_MODE
    #define PC_13_MODE      GPIO_MODE_ANALOG
    #define PC_13_PUPD      GPIO_PUPD_NONE
    #define PC_13_OSPEED    GPIO_OSPEED_LOW
    #define PC_13_OTYPE     GPIO_OTYPE_PP
    #define PC_13_AF        GPIO_AF0
    #define PC_13_DEFAULT_STATE 0
#else
    #if (PC_13_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_13_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_13_AF not defined'
        #endif
    #else
        #ifdef PC_13_AF
            #error 'PC_13_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_13_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_13_DEFAULT_STATE
            #warning 'PC_13_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_13_DEFAULT_STATE
        #define PC_13_DEFAULT_STATE 0
    #endif
    #ifndef PC_13_AF
        #define PC_13_AF GPIO_AF0
    #endif
    #ifndef PC_13_OTYPE
        #define PC_13_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_13_PUPD
        #define PC_13_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_13_OSPEED
        #define PC_13_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_14_MODE
    #define PC_14_MODE      GPIO_MODE_ANALOG
    #define PC_14_PUPD      GPIO_PUPD_NONE
    #define PC_14_OSPEED    GPIO_OSPEED_LOW
    #define PC_14_OTYPE     GPIO_OTYPE_PP
    #define PC_14_AF        GPIO_AF0
    #define PC_14_DEFAULT_STATE 0
#else
    #if (PC_14_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_14_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_14_AF not defined'
        #endif
    #else
        #ifdef PC_14_AF
            #error 'PC_14_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_14_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_14_DEFAULT_STATE
            #warning 'PC_14_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_14_DEFAULT_STATE
        #define PC_14_DEFAULT_STATE 0
    #endif
    #ifndef PC_14_AF
        #define PC_14_AF GPIO_AF0
    #endif
    #ifndef PC_14_OTYPE
        #define PC_14_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_14_PUPD
        #define PC_14_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_14_OSPEED
        #define PC_14_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PC_15_MODE
    #define PC_15_MODE      GPIO_MODE_ANALOG
    #define PC_15_PUPD      GPIO_PUPD_NONE
    #define PC_15_OSPEED    GPIO_OSPEED_LOW
    #define PC_15_OTYPE     GPIO_OTYPE_PP
    #define PC_15_AF        GPIO_AF0
    #define PC_15_DEFAULT_STATE 0
#else
    #if (PC_15_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PC_15_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PC_15_AF not defined'
        #endif
    #else
        #ifdef PC_15_AF
            #error 'PC_15_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PC_15_MODE == GPIO_MODE_OUTPUT)
        #ifndef PC_15_DEFAULT_STATE
            #warning 'PC_15_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PC_15_DEFAULT_STATE
        #define PC_15_DEFAULT_STATE 0
    #endif
    #ifndef PC_15_AF
        #define PC_15_AF GPIO_AF0
    #endif
    #ifndef PC_15_OTYPE
        #define PC_15_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PC_15_PUPD
        #define PC_15_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PC_15_OSPEED
        #define PC_15_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_0_MODE
    #define PD_0_MODE      GPIO_MODE_ANALOG
    #define PD_0_PUPD      GPIO_PUPD_NONE
    #define PD_0_OSPEED    GPIO_OSPEED_LOW
    #define PD_0_OTYPE     GPIO_OTYPE_PP
    #define PD_0_AF        GPIO_AF0
    #define PD_0_DEFAULT_STATE 0
#else
    #if (PD_0_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_0_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_0_AF not defined'
        #endif
    #else
        #ifdef PD_0_AF
            #error 'PD_0_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_0_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_0_DEFAULT_STATE
            #warning 'PD_0_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_0_DEFAULT_STATE
        #define PD_0_DEFAULT_STATE 0
    #endif
    #ifndef PD_0_AF
        #define PD_0_AF GPIO_AF0
    #endif
    #ifndef PD_0_OTYPE
        #define PD_0_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_0_PUPD
        #define PD_0_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_0_OSPEED
        #define PD_0_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_1_MODE
    #define PD_1_MODE      GPIO_MODE_ANALOG
    #define PD_1_PUPD      GPIO_PUPD_NONE
    #define PD_1_OSPEED    GPIO_OSPEED_LOW
    #define PD_1_OTYPE     GPIO_OTYPE_PP
    #define PD_1_AF        GPIO_AF0
    #define PD_1_DEFAULT_STATE 0
#else
    #if (PD_1_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_1_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_1_AF not defined'
        #endif
    #else
        #ifdef PD_1_AF
            #error 'PD_1_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_1_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_1_DEFAULT_STATE
            #warning 'PD_1_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_1_DEFAULT_STATE
        #define PD_1_DEFAULT_STATE 0
    #endif
    #ifndef PD_1_AF
        #define PD_1_AF GPIO_AF0
    #endif
    #ifndef PD_1_OTYPE
        #define PD_1_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_1_PUPD
        #define PD_1_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_1_OSPEED
        #define PD_1_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_2_MODE
    #define PD_2_MODE      GPIO_MODE_ANALOG
    #define PD_2_PUPD      GPIO_PUPD_NONE
    #define PD_2_OSPEED    GPIO_OSPEED_LOW
    #define PD_2_OTYPE     GPIO_OTYPE_PP
    #define PD_2_AF        GPIO_AF0
    #define PD_2_DEFAULT_STATE 0
#else
    #if (PD_2_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_2_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_2_AF not defined'
        #endif
    #else
        #ifdef PD_2_AF
            #error 'PD_2_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_2_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_2_DEFAULT_STATE
            #warning 'PD_2_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_2_DEFAULT_STATE
        #define PD_2_DEFAULT_STATE 0
    #endif
    #ifndef PD_2_AF
        #define PD_2_AF GPIO_AF0
    #endif
    #ifndef PD_2_OTYPE
        #define PD_2_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_2_PUPD
        #define PD_2_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_2_OSPEED
        #define PD_2_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_3_MODE
    #define PD_3_MODE      GPIO_MODE_ANALOG
    #define PD_3_PUPD      GPIO_PUPD_NONE
    #define PD_3_OSPEED    GPIO_OSPEED_LOW
    #define PD_3_OTYPE     GPIO_OTYPE_PP
    #define PD_3_AF        GPIO_AF0
    #define PD_3_DEFAULT_STATE 0
#else
    #if (PD_3_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_3_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_3_AF not defined'
        #endif
    #else
        #ifdef PD_3_AF
            #error 'PD_3_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_3_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_3_DEFAULT_STATE
            #warning 'PD_3_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_3_DEFAULT_STATE
        #define PD_3_DEFAULT_STATE 0
    #endif
    #ifndef PD_3_AF
        #define PD_3_AF GPIO_AF0
    #endif
    #ifndef PD_3_OTYPE
        #define PD_3_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_3_PUPD
        #define PD_3_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_3_OSPEED
        #define PD_3_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_4_MODE
    #define PD_4_MODE      GPIO_MODE_ANALOG
    #define PD_4_PUPD      GPIO_PUPD_NONE
    #define PD_4_OSPEED    GPIO_OSPEED_LOW
    #define PD_4_OTYPE     GPIO_OTYPE_PP
    #define PD_4_AF        GPIO_AF0
    #define PD_4_DEFAULT_STATE 0
#else
    #if (PD_4_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_4_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_4_AF not defined'
        #endif
    #else
        #ifdef PD_4_AF
            #error 'PD_4_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_4_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_4_DEFAULT_STATE
            #warning 'PD_4_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_4_DEFAULT_STATE
        #define PD_4_DEFAULT_STATE 0
    #endif
    #ifndef PD_4_AF
        #define PD_4_AF GPIO_AF0
    #endif
    #ifndef PD_4_OTYPE
        #define PD_4_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_4_PUPD
        #define PD_4_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_4_OSPEED
        #define PD_4_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_5_MODE
    #define PD_5_MODE      GPIO_MODE_ANALOG
    #define PD_5_PUPD      GPIO_PUPD_NONE
    #define PD_5_OSPEED    GPIO_OSPEED_LOW
    #define PD_5_OTYPE     GPIO_OTYPE_PP
    #define PD_5_AF        GPIO_AF0
    #define PD_5_DEFAULT_STATE 0
#else
    #if (PD_5_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_5_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_5_AF not defined'
        #endif
    #else
        #ifdef PD_5_AF
            #error 'PD_5_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_5_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_5_DEFAULT_STATE
            #warning 'PD_5_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_5_DEFAULT_STATE
        #define PD_5_DEFAULT_STATE 0
    #endif
    #ifndef PD_5_AF
        #define PD_5_AF GPIO_AF0
    #endif
    #ifndef PD_5_OTYPE
        #define PD_5_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_5_PUPD
        #define PD_5_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_5_OSPEED
        #define PD_5_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_6_MODE
    #define PD_6_MODE      GPIO_MODE_ANALOG
    #define PD_6_PUPD      GPIO_PUPD_NONE
    #define PD_6_OSPEED    GPIO_OSPEED_LOW
    #define PD_6_OTYPE     GPIO_OTYPE_PP
    #define PD_6_AF        GPIO_AF0
    #define PD_6_DEFAULT_STATE 0
#else
    #if (PD_6_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_6_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_6_AF not defined'
        #endif
    #else
        #ifdef PD_6_AF
            #error 'PD_6_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_6_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_6_DEFAULT_STATE
            #warning 'PD_6_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_6_DEFAULT_STATE
        #define PD_6_DEFAULT_STATE 0
    #endif
    #ifndef PD_6_AF
        #define PD_6_AF GPIO_AF0
    #endif
    #ifndef PD_6_OTYPE
        #define PD_6_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_6_PUPD
        #define PD_6_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_6_OSPEED
        #define PD_6_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_7_MODE
    #define PD_7_MODE      GPIO_MODE_ANALOG
    #define PD_7_PUPD      GPIO_PUPD_NONE
    #define PD_7_OSPEED    GPIO_OSPEED_LOW
    #define PD_7_OTYPE     GPIO_OTYPE_PP
    #define PD_7_AF        GPIO_AF0
    #define PD_7_DEFAULT_STATE 0
#else
    #if (PD_7_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_7_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_7_AF not defined'
        #endif
    #else
        #ifdef PD_7_AF
            #error 'PD_7_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_7_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_7_DEFAULT_STATE
            #warning 'PD_7_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_7_DEFAULT_STATE
        #define PD_7_DEFAULT_STATE 0
    #endif
    #ifndef PD_7_AF
        #define PD_7_AF GPIO_AF0
    #endif
    #ifndef PD_7_OTYPE
        #define PD_7_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_7_PUPD
        #define PD_7_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_7_OSPEED
        #define PD_7_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_8_MODE
    #define PD_8_MODE      GPIO_MODE_ANALOG
    #define PD_8_PUPD      GPIO_PUPD_NONE
    #define PD_8_OSPEED    GPIO_OSPEED_LOW
    #define PD_8_OTYPE     GPIO_OTYPE_PP
    #define PD_8_AF        GPIO_AF0
    #define PD_8_DEFAULT_STATE 0
#else
    #if (PD_8_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_8_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_8_AF not defined'
        #endif
    #else
        #ifdef PD_8_AF
            #error 'PD_8_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_8_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_8_DEFAULT_STATE
            #warning 'PD_8_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_8_DEFAULT_STATE
        #define PD_8_DEFAULT_STATE 0
    #endif
    #ifndef PD_8_AF
        #define PD_8_AF GPIO_AF0
    #endif
    #ifndef PD_8_OTYPE
        #define PD_8_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_8_PUPD
        #define PD_8_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_8_OSPEED
        #define PD_8_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_9_MODE
    #define PD_9_MODE      GPIO_MODE_ANALOG
    #define PD_9_PUPD      GPIO_PUPD_NONE
    #define PD_9_OSPEED    GPIO_OSPEED_LOW
    #define PD_9_OTYPE     GPIO_OTYPE_PP
    #define PD_9_AF        GPIO_AF0
    #define PD_9_DEFAULT_STATE 0
#else
    #if (PD_9_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_9_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_9_AF not defined'
        #endif
    #else
        #ifdef PD_9_AF
            #error 'PD_9_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_9_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_9_DEFAULT_STATE
            #warning 'PD_9_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_9_DEFAULT_STATE
        #define PD_9_DEFAULT_STATE 0
    #endif
    #ifndef PD_9_AF
        #define PD_9_AF GPIO_AF0
    #endif
    #ifndef PD_9_OTYPE
        #define PD_9_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_9_PUPD
        #define PD_9_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_9_OSPEED
        #define PD_9_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_10_MODE
    #define PD_10_MODE      GPIO_MODE_ANALOG
    #define PD_10_PUPD      GPIO_PUPD_NONE
    #define PD_10_OSPEED    GPIO_OSPEED_LOW
    #define PD_10_OTYPE     GPIO_OTYPE_PP
    #define PD_10_AF        GPIO_AF0
    #define PD_10_DEFAULT_STATE 0
#else
    #if (PD_10_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_10_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_10_AF not defined'
        #endif
    #else
        #ifdef PD_10_AF
            #error 'PD_10_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_10_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_10_DEFAULT_STATE
            #warning 'PD_10_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_10_DEFAULT_STATE
        #define PD_10_DEFAULT_STATE 0
    #endif
    #ifndef PD_10_AF
        #define PD_10_AF GPIO_AF0
    #endif
    #ifndef PD_10_OTYPE
        #define PD_10_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_10_PUPD
        #define PD_10_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_10_OSPEED
        #define PD_10_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_11_MODE
    #define PD_11_MODE      GPIO_MODE_ANALOG
    #define PD_11_PUPD      GPIO_PUPD_NONE
    #define PD_11_OSPEED    GPIO_OSPEED_LOW
    #define PD_11_OTYPE     GPIO_OTYPE_PP
    #define PD_11_AF        GPIO_AF0
    #define PD_11_DEFAULT_STATE 0
#else
    #if (PD_11_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_11_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_11_AF not defined'
        #endif
    #else
        #ifdef PD_11_AF
            #error 'PD_11_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_11_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_11_DEFAULT_STATE
            #warning 'PD_11_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_11_DEFAULT_STATE
        #define PD_11_DEFAULT_STATE 0
    #endif
    #ifndef PD_11_AF
        #define PD_11_AF GPIO_AF0
    #endif
    #ifndef PD_11_OTYPE
        #define PD_11_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_11_PUPD
        #define PD_11_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_11_OSPEED
        #define PD_11_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_12_MODE
    #define PD_12_MODE      GPIO_MODE_ANALOG
    #define PD_12_PUPD      GPIO_PUPD_NONE
    #define PD_12_OSPEED    GPIO_OSPEED_LOW
    #define PD_12_OTYPE     GPIO_OTYPE_PP
    #define PD_12_AF        GPIO_AF0
    #define PD_12_DEFAULT_STATE 0
#else
    #if (PD_12_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_12_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_12_AF not defined'
        #endif
    #else
        #ifdef PD_12_AF
            #error 'PD_12_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_12_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_12_DEFAULT_STATE
            #warning 'PD_12_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_12_DEFAULT_STATE
        #define PD_12_DEFAULT_STATE 0
    #endif
    #ifndef PD_12_AF
        #define PD_12_AF GPIO_AF0
    #endif
    #ifndef PD_12_OTYPE
        #define PD_12_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_12_PUPD
        #define PD_12_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_12_OSPEED
        #define PD_12_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_13_MODE
    #define PD_13_MODE      GPIO_MODE_ANALOG
    #define PD_13_PUPD      GPIO_PUPD_NONE
    #define PD_13_OSPEED    GPIO_OSPEED_LOW
    #define PD_13_OTYPE     GPIO_OTYPE_PP
    #define PD_13_AF        GPIO_AF0
    #define PD_13_DEFAULT_STATE 0
#else
    #if (PD_13_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_13_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_13_AF not defined'
        #endif
    #else
        #ifdef PD_13_AF
            #error 'PD_13_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_13_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_13_DEFAULT_STATE
            #warning 'PD_13_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_13_DEFAULT_STATE
        #define PD_13_DEFAULT_STATE 0
    #endif
    #ifndef PD_13_AF
        #define PD_13_AF GPIO_AF0
    #endif
    #ifndef PD_13_OTYPE
        #define PD_13_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_13_PUPD
        #define PD_13_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_13_OSPEED
        #define PD_13_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_14_MODE
    #define PD_14_MODE      GPIO_MODE_ANALOG
    #define PD_14_PUPD      GPIO_PUPD_NONE
    #define PD_14_OSPEED    GPIO_OSPEED_LOW
    #define PD_14_OTYPE     GPIO_OTYPE_PP
    #define PD_14_AF        GPIO_AF0
    #define PD_14_DEFAULT_STATE 0
#else
    #if (PD_14_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_14_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_14_AF not defined'
        #endif
    #else
        #ifdef PD_14_AF
            #error 'PD_14_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_14_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_14_DEFAULT_STATE
            #warning 'PD_14_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_14_DEFAULT_STATE
        #define PD_14_DEFAULT_STATE 0
    #endif
    #ifndef PD_14_AF
        #define PD_14_AF GPIO_AF0
    #endif
    #ifndef PD_14_OTYPE
        #define PD_14_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_14_PUPD
        #define PD_14_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_14_OSPEED
        #define PD_14_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PD_15_MODE
    #define PD_15_MODE      GPIO_MODE_ANALOG
    #define PD_15_PUPD      GPIO_PUPD_NONE
    #define PD_15_OSPEED    GPIO_OSPEED_LOW
    #define PD_15_OTYPE     GPIO_OTYPE_PP
    #define PD_15_AF        GPIO_AF0
    #define PD_15_DEFAULT_STATE 0
#else
    #if (PD_15_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PD_15_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PD_15_AF not defined'
        #endif
    #else
        #ifdef PD_15_AF
            #error 'PD_15_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PD_15_MODE == GPIO_MODE_OUTPUT)
        #ifndef PD_15_DEFAULT_STATE
            #warning 'PD_15_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PD_15_DEFAULT_STATE
        #define PD_15_DEFAULT_STATE 0
    #endif
    #ifndef PD_15_AF
        #define PD_15_AF GPIO_AF0
    #endif
    #ifndef PD_15_OTYPE
        #define PD_15_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PD_15_PUPD
        #define PD_15_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PD_15_OSPEED
        #define PD_15_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_0_MODE
    #define PE_0_MODE      GPIO_MODE_ANALOG
    #define PE_0_PUPD      GPIO_PUPD_NONE
    #define PE_0_OSPEED    GPIO_OSPEED_LOW
    #define PE_0_OTYPE     GPIO_OTYPE_PP
    #define PE_0_AF        GPIO_AF0
    #define PE_0_DEFAULT_STATE 0
#else
    #if (PE_0_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_0_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_0_AF not defined'
        #endif
    #else
        #ifdef PE_0_AF
            #error 'PE_0_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_0_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_0_DEFAULT_STATE
            #warning 'PE_0_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_0_DEFAULT_STATE
        #define PE_0_DEFAULT_STATE 0
    #endif
    #ifndef PE_0_AF
        #define PE_0_AF GPIO_AF0
    #endif
    #ifndef PE_0_OTYPE
        #define PE_0_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_0_PUPD
        #define PE_0_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_0_OSPEED
        #define PE_0_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_1_MODE
    #define PE_1_MODE      GPIO_MODE_ANALOG
    #define PE_1_PUPD      GPIO_PUPD_NONE
    #define PE_1_OSPEED    GPIO_OSPEED_LOW
    #define PE_1_OTYPE     GPIO_OTYPE_PP
    #define PE_1_AF        GPIO_AF0
    #define PE_1_DEFAULT_STATE 0
#else
    #if (PE_1_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_1_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_1_AF not defined'
        #endif
    #else
        #ifdef PE_1_AF
            #error 'PE_1_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_1_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_1_DEFAULT_STATE
            #warning 'PE_1_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_1_DEFAULT_STATE
        #define PE_1_DEFAULT_STATE 0
    #endif
    #ifndef PE_1_AF
        #define PE_1_AF GPIO_AF0
    #endif
    #ifndef PE_1_OTYPE
        #define PE_1_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_1_PUPD
        #define PE_1_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_1_OSPEED
        #define PE_1_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_2_MODE
    #define PE_2_MODE      GPIO_MODE_ANALOG
    #define PE_2_PUPD      GPIO_PUPD_NONE
    #define PE_2_OSPEED    GPIO_OSPEED_LOW
    #define PE_2_OTYPE     GPIO_OTYPE_PP
    #define PE_2_AF        GPIO_AF0
    #define PE_2_DEFAULT_STATE 0
#else
    #if (PE_2_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_2_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_2_AF not defined'
        #endif
    #else
        #ifdef PE_2_AF
            #error 'PE_2_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_2_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_2_DEFAULT_STATE
            #warning 'PE_2_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_2_DEFAULT_STATE
        #define PE_2_DEFAULT_STATE 0
    #endif
    #ifndef PE_2_AF
        #define PE_2_AF GPIO_AF0
    #endif
    #ifndef PE_2_OTYPE
        #define PE_2_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_2_PUPD
        #define PE_2_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_2_OSPEED
        #define PE_2_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_3_MODE
    #define PE_3_MODE      GPIO_MODE_ANALOG
    #define PE_3_PUPD      GPIO_PUPD_NONE
    #define PE_3_OSPEED    GPIO_OSPEED_LOW
    #define PE_3_OTYPE     GPIO_OTYPE_PP
    #define PE_3_AF        GPIO_AF0
    #define PE_3_DEFAULT_STATE 0
#else
    #if (PE_3_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_3_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_3_AF not defined'
        #endif
    #else
        #ifdef PE_3_AF
            #error 'PE_3_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_3_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_3_DEFAULT_STATE
            #warning 'PE_3_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_3_DEFAULT_STATE
        #define PE_3_DEFAULT_STATE 0
    #endif
    #ifndef PE_3_AF
        #define PE_3_AF GPIO_AF0
    #endif
    #ifndef PE_3_OTYPE
        #define PE_3_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_3_PUPD
        #define PE_3_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_3_OSPEED
        #define PE_3_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_4_MODE
    #define PE_4_MODE      GPIO_MODE_ANALOG
    #define PE_4_PUPD      GPIO_PUPD_NONE
    #define PE_4_OSPEED    GPIO_OSPEED_LOW
    #define PE_4_OTYPE     GPIO_OTYPE_PP
    #define PE_4_AF        GPIO_AF0
    #define PE_4_DEFAULT_STATE 0
#else
    #if (PE_4_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_4_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_4_AF not defined'
        #endif
    #else
        #ifdef PE_4_AF
            #error 'PE_4_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_4_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_4_DEFAULT_STATE
            #warning 'PE_4_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_4_DEFAULT_STATE
        #define PE_4_DEFAULT_STATE 0
    #endif
    #ifndef PE_4_AF
        #define PE_4_AF GPIO_AF0
    #endif
    #ifndef PE_4_OTYPE
        #define PE_4_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_4_PUPD
        #define PE_4_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_4_OSPEED
        #define PE_4_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_5_MODE
    #define PE_5_MODE      GPIO_MODE_ANALOG
    #define PE_5_PUPD      GPIO_PUPD_NONE
    #define PE_5_OSPEED    GPIO_OSPEED_LOW
    #define PE_5_OTYPE     GPIO_OTYPE_PP
    #define PE_5_AF        GPIO_AF0
    #define PE_5_DEFAULT_STATE 0
#else
    #if (PE_5_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_5_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_5_AF not defined'
        #endif
    #else
        #ifdef PE_5_AF
            #error 'PE_5_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_5_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_5_DEFAULT_STATE
            #warning 'PE_5_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_5_DEFAULT_STATE
        #define PE_5_DEFAULT_STATE 0
    #endif
    #ifndef PE_5_AF
        #define PE_5_AF GPIO_AF0
    #endif
    #ifndef PE_5_OTYPE
        #define PE_5_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_5_PUPD
        #define PE_5_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_5_OSPEED
        #define PE_5_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_6_MODE
    #define PE_6_MODE      GPIO_MODE_ANALOG
    #define PE_6_PUPD      GPIO_PUPD_NONE
    #define PE_6_OSPEED    GPIO_OSPEED_LOW
    #define PE_6_OTYPE     GPIO_OTYPE_PP
    #define PE_6_AF        GPIO_AF0
    #define PE_6_DEFAULT_STATE 0
#else
    #if (PE_6_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_6_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_6_AF not defined'
        #endif
    #else
        #ifdef PE_6_AF
            #error 'PE_6_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_6_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_6_DEFAULT_STATE
            #warning 'PE_6_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_6_DEFAULT_STATE
        #define PE_6_DEFAULT_STATE 0
    #endif
    #ifndef PE_6_AF
        #define PE_6_AF GPIO_AF0
    #endif
    #ifndef PE_6_OTYPE
        #define PE_6_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_6_PUPD
        #define PE_6_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_6_OSPEED
        #define PE_6_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_7_MODE
    #define PE_7_MODE      GPIO_MODE_ANALOG
    #define PE_7_PUPD      GPIO_PUPD_NONE
    #define PE_7_OSPEED    GPIO_OSPEED_LOW
    #define PE_7_OTYPE     GPIO_OTYPE_PP
    #define PE_7_AF        GPIO_AF0
    #define PE_7_DEFAULT_STATE 0
#else
    #if (PE_7_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_7_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_7_AF not defined'
        #endif
    #else
        #ifdef PE_7_AF
            #error 'PE_7_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_7_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_7_DEFAULT_STATE
            #warning 'PE_7_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_7_DEFAULT_STATE
        #define PE_7_DEFAULT_STATE 0
    #endif
    #ifndef PE_7_AF
        #define PE_7_AF GPIO_AF0
    #endif
    #ifndef PE_7_OTYPE
        #define PE_7_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_7_PUPD
        #define PE_7_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_7_OSPEED
        #define PE_7_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_8_MODE
    #define PE_8_MODE      GPIO_MODE_ANALOG
    #define PE_8_PUPD      GPIO_PUPD_NONE
    #define PE_8_OSPEED    GPIO_OSPEED_LOW
    #define PE_8_OTYPE     GPIO_OTYPE_PP
    #define PE_8_AF        GPIO_AF0
    #define PE_8_DEFAULT_STATE 0
#else
    #if (PE_8_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_8_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_8_AF not defined'
        #endif
    #else
        #ifdef PE_8_AF
            #error 'PE_8_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_8_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_8_DEFAULT_STATE
            #warning 'PE_8_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_8_DEFAULT_STATE
        #define PE_8_DEFAULT_STATE 0
    #endif
    #ifndef PE_8_AF
        #define PE_8_AF GPIO_AF0
    #endif
    #ifndef PE_8_OTYPE
        #define PE_8_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_8_PUPD
        #define PE_8_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_8_OSPEED
        #define PE_8_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_9_MODE
    #define PE_9_MODE      GPIO_MODE_ANALOG
    #define PE_9_PUPD      GPIO_PUPD_NONE
    #define PE_9_OSPEED    GPIO_OSPEED_LOW
    #define PE_9_OTYPE     GPIO_OTYPE_PP
    #define PE_9_AF        GPIO_AF0
    #define PE_9_DEFAULT_STATE 0
#else
    #if (PE_9_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_9_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_9_AF not defined'
        #endif
    #else
        #ifdef PE_9_AF
            #error 'PE_9_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_9_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_9_DEFAULT_STATE
            #warning 'PE_9_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_9_DEFAULT_STATE
        #define PE_9_DEFAULT_STATE 0
    #endif
    #ifndef PE_9_AF
        #define PE_9_AF GPIO_AF0
    #endif
    #ifndef PE_9_OTYPE
        #define PE_9_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_9_PUPD
        #define PE_9_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_9_OSPEED
        #define PE_9_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_10_MODE
    #define PE_10_MODE      GPIO_MODE_ANALOG
    #define PE_10_PUPD      GPIO_PUPD_NONE
    #define PE_10_OSPEED    GPIO_OSPEED_LOW
    #define PE_10_OTYPE     GPIO_OTYPE_PP
    #define PE_10_AF        GPIO_AF0
    #define PE_10_DEFAULT_STATE 0
#else
    #if (PE_10_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_10_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_10_AF not defined'
        #endif
    #else
        #ifdef PE_10_AF
            #error 'PE_10_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_10_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_10_DEFAULT_STATE
            #warning 'PE_10_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_10_DEFAULT_STATE
        #define PE_10_DEFAULT_STATE 0
    #endif
    #ifndef PE_10_AF
        #define PE_10_AF GPIO_AF0
    #endif
    #ifndef PE_10_OTYPE
        #define PE_10_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_10_PUPD
        #define PE_10_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_10_OSPEED
        #define PE_10_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_11_MODE
    #define PE_11_MODE      GPIO_MODE_ANALOG
    #define PE_11_PUPD      GPIO_PUPD_NONE
    #define PE_11_OSPEED    GPIO_OSPEED_LOW
    #define PE_11_OTYPE     GPIO_OTYPE_PP
    #define PE_11_AF        GPIO_AF0
    #define PE_11_DEFAULT_STATE 0
#else
    #if (PE_11_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_11_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_11_AF not defined'
        #endif
    #else
        #ifdef PE_11_AF
            #error 'PE_11_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_11_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_11_DEFAULT_STATE
            #warning 'PE_11_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_11_DEFAULT_STATE
        #define PE_11_DEFAULT_STATE 0
    #endif
    #ifndef PE_11_AF
        #define PE_11_AF GPIO_AF0
    #endif
    #ifndef PE_11_OTYPE
        #define PE_11_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_11_PUPD
        #define PE_11_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_11_OSPEED
        #define PE_11_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_12_MODE
    #define PE_12_MODE      GPIO_MODE_ANALOG
    #define PE_12_PUPD      GPIO_PUPD_NONE
    #define PE_12_OSPEED    GPIO_OSPEED_LOW
    #define PE_12_OTYPE     GPIO_OTYPE_PP
    #define PE_12_AF        GPIO_AF0
    #define PE_12_DEFAULT_STATE 0
#else
    #if (PE_12_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_12_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_12_AF not defined'
        #endif
    #else
        #ifdef PE_12_AF
            #error 'PE_12_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_12_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_12_DEFAULT_STATE
            #warning 'PE_12_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_12_DEFAULT_STATE
        #define PE_12_DEFAULT_STATE 0
    #endif
    #ifndef PE_12_AF
        #define PE_12_AF GPIO_AF0
    #endif
    #ifndef PE_12_OTYPE
        #define PE_12_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_12_PUPD
        #define PE_12_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_12_OSPEED
        #define PE_12_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_13_MODE
    #define PE_13_MODE      GPIO_MODE_ANALOG
    #define PE_13_PUPD      GPIO_PUPD_NONE
    #define PE_13_OSPEED    GPIO_OSPEED_LOW
    #define PE_13_OTYPE     GPIO_OTYPE_PP
    #define PE_13_AF        GPIO_AF0
    #define PE_13_DEFAULT_STATE 0
#else
    #if (PE_13_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_13_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_13_AF not defined'
        #endif
    #else
        #ifdef PE_13_AF
            #error 'PE_13_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_13_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_13_DEFAULT_STATE
            #warning 'PE_13_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_13_DEFAULT_STATE
        #define PE_13_DEFAULT_STATE 0
    #endif
    #ifndef PE_13_AF
        #define PE_13_AF GPIO_AF0
    #endif
    #ifndef PE_13_OTYPE
        #define PE_13_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_13_PUPD
        #define PE_13_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_13_OSPEED
        #define PE_13_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_14_MODE
    #define PE_14_MODE      GPIO_MODE_ANALOG
    #define PE_14_PUPD      GPIO_PUPD_NONE
    #define PE_14_OSPEED    GPIO_OSPEED_LOW
    #define PE_14_OTYPE     GPIO_OTYPE_PP
    #define PE_14_AF        GPIO_AF0
    #define PE_14_DEFAULT_STATE 0
#else
    #if (PE_14_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_14_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_14_AF not defined'
        #endif
    #else
        #ifdef PE_14_AF
            #error 'PE_14_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_14_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_14_DEFAULT_STATE
            #warning 'PE_14_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_14_DEFAULT_STATE
        #define PE_14_DEFAULT_STATE 0
    #endif
    #ifndef PE_14_AF
        #define PE_14_AF GPIO_AF0
    #endif
    #ifndef PE_14_OTYPE
        #define PE_14_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_14_PUPD
        #define PE_14_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_14_OSPEED
        #define PE_14_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PE_15_MODE
    #define PE_15_MODE      GPIO_MODE_ANALOG
    #define PE_15_PUPD      GPIO_PUPD_NONE
    #define PE_15_OSPEED    GPIO_OSPEED_LOW
    #define PE_15_OTYPE     GPIO_OTYPE_PP
    #define PE_15_AF        GPIO_AF0
    #define PE_15_DEFAULT_STATE 0
#else
    #if (PE_15_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PE_15_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PE_15_AF not defined'
        #endif
    #else
        #ifdef PE_15_AF
            #error 'PE_15_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PE_15_MODE == GPIO_MODE_OUTPUT)
        #ifndef PE_15_DEFAULT_STATE
            #warning 'PE_15_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PE_15_DEFAULT_STATE
        #define PE_15_DEFAULT_STATE 0
    #endif
    #ifndef PE_15_AF
        #define PE_15_AF GPIO_AF0
    #endif
    #ifndef PE_15_OTYPE
        #define PE_15_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PE_15_PUPD
        #define PE_15_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PE_15_OSPEED
        #define PE_15_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_0_MODE
    #define PF_0_MODE      GPIO_MODE_ANALOG
    #define PF_0_PUPD      GPIO_PUPD_NONE
    #define PF_0_OSPEED    GPIO_OSPEED_LOW
    #define PF_0_OTYPE     GPIO_OTYPE_PP
    #define PF_0_AF        GPIO_AF0
    #define PF_0_DEFAULT_STATE 0
#else
    #if (PF_0_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_0_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_0_AF not defined'
        #endif
    #else
        #ifdef PF_0_AF
            #error 'PF_0_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_0_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_0_DEFAULT_STATE
            #warning 'PF_0_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_0_DEFAULT_STATE
        #define PF_0_DEFAULT_STATE 0
    #endif
    #ifndef PF_0_AF
        #define PF_0_AF GPIO_AF0
    #endif
    #ifndef PF_0_OTYPE
        #define PF_0_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_0_PUPD
        #define PF_0_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_0_OSPEED
        #define PF_0_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_1_MODE
    #define PF_1_MODE      GPIO_MODE_ANALOG
    #define PF_1_PUPD      GPIO_PUPD_NONE
    #define PF_1_OSPEED    GPIO_OSPEED_LOW
    #define PF_1_OTYPE     GPIO_OTYPE_PP
    #define PF_1_AF        GPIO_AF0
    #define PF_1_DEFAULT_STATE 0
#else
    #if (PF_1_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_1_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_1_AF not defined'
        #endif
    #else
        #ifdef PF_1_AF
            #error 'PF_1_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_1_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_1_DEFAULT_STATE
            #warning 'PF_1_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_1_DEFAULT_STATE
        #define PF_1_DEFAULT_STATE 0
    #endif
    #ifndef PF_1_AF
        #define PF_1_AF GPIO_AF0
    #endif
    #ifndef PF_1_OTYPE
        #define PF_1_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_1_PUPD
        #define PF_1_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_1_OSPEED
        #define PF_1_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_2_MODE
    #define PF_2_MODE      GPIO_MODE_ANALOG
    #define PF_2_PUPD      GPIO_PUPD_NONE
    #define PF_2_OSPEED    GPIO_OSPEED_LOW
    #define PF_2_OTYPE     GPIO_OTYPE_PP
    #define PF_2_AF        GPIO_AF0
    #define PF_2_DEFAULT_STATE 0
#else
    #if (PF_2_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_2_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_2_AF not defined'
        #endif
    #else
        #ifdef PF_2_AF
            #error 'PF_2_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_2_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_2_DEFAULT_STATE
            #warning 'PF_2_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_2_DEFAULT_STATE
        #define PF_2_DEFAULT_STATE 0
    #endif
    #ifndef PF_2_AF
        #define PF_2_AF GPIO_AF0
    #endif
    #ifndef PF_2_OTYPE
        #define PF_2_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_2_PUPD
        #define PF_2_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_2_OSPEED
        #define PF_2_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_3_MODE
    #define PF_3_MODE      GPIO_MODE_ANALOG
    #define PF_3_PUPD      GPIO_PUPD_NONE
    #define PF_3_OSPEED    GPIO_OSPEED_LOW
    #define PF_3_OTYPE     GPIO_OTYPE_PP
    #define PF_3_AF        GPIO_AF0
    #define PF_3_DEFAULT_STATE 0
#else
    #if (PF_3_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_3_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_3_AF not defined'
        #endif
    #else
        #ifdef PF_3_AF
            #error 'PF_3_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_3_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_3_DEFAULT_STATE
            #warning 'PF_3_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_3_DEFAULT_STATE
        #define PF_3_DEFAULT_STATE 0
    #endif
    #ifndef PF_3_AF
        #define PF_3_AF GPIO_AF0
    #endif
    #ifndef PF_3_OTYPE
        #define PF_3_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_3_PUPD
        #define PF_3_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_3_OSPEED
        #define PF_3_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_4_MODE
    #define PF_4_MODE      GPIO_MODE_ANALOG
    #define PF_4_PUPD      GPIO_PUPD_NONE
    #define PF_4_OSPEED    GPIO_OSPEED_LOW
    #define PF_4_OTYPE     GPIO_OTYPE_PP
    #define PF_4_AF        GPIO_AF0
    #define PF_4_DEFAULT_STATE 0
#else
    #if (PF_4_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_4_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_4_AF not defined'
        #endif
    #else
        #ifdef PF_4_AF
            #error 'PF_4_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_4_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_4_DEFAULT_STATE
            #warning 'PF_4_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_4_DEFAULT_STATE
        #define PF_4_DEFAULT_STATE 0
    #endif
    #ifndef PF_4_AF
        #define PF_4_AF GPIO_AF0
    #endif
    #ifndef PF_4_OTYPE
        #define PF_4_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_4_PUPD
        #define PF_4_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_4_OSPEED
        #define PF_4_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_5_MODE
    #define PF_5_MODE      GPIO_MODE_ANALOG
    #define PF_5_PUPD      GPIO_PUPD_NONE
    #define PF_5_OSPEED    GPIO_OSPEED_LOW
    #define PF_5_OTYPE     GPIO_OTYPE_PP
    #define PF_5_AF        GPIO_AF0
    #define PF_5_DEFAULT_STATE 0
#else
    #if (PF_5_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_5_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_5_AF not defined'
        #endif
    #else
        #ifdef PF_5_AF
            #error 'PF_5_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_5_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_5_DEFAULT_STATE
            #warning 'PF_5_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_5_DEFAULT_STATE
        #define PF_5_DEFAULT_STATE 0
    #endif
    #ifndef PF_5_AF
        #define PF_5_AF GPIO_AF0
    #endif
    #ifndef PF_5_OTYPE
        #define PF_5_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_5_PUPD
        #define PF_5_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_5_OSPEED
        #define PF_5_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_6_MODE
    #define PF_6_MODE      GPIO_MODE_ANALOG
    #define PF_6_PUPD      GPIO_PUPD_NONE
    #define PF_6_OSPEED    GPIO_OSPEED_LOW
    #define PF_6_OTYPE     GPIO_OTYPE_PP
    #define PF_6_AF        GPIO_AF0
    #define PF_6_DEFAULT_STATE 0
#else
    #if (PF_6_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_6_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_6_AF not defined'
        #endif
    #else
        #ifdef PF_6_AF
            #error 'PF_6_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_6_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_6_DEFAULT_STATE
            #warning 'PF_6_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_6_DEFAULT_STATE
        #define PF_6_DEFAULT_STATE 0
    #endif
    #ifndef PF_6_AF
        #define PF_6_AF GPIO_AF0
    #endif
    #ifndef PF_6_OTYPE
        #define PF_6_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_6_PUPD
        #define PF_6_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_6_OSPEED
        #define PF_6_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_7_MODE
    #define PF_7_MODE      GPIO_MODE_ANALOG
    #define PF_7_PUPD      GPIO_PUPD_NONE
    #define PF_7_OSPEED    GPIO_OSPEED_LOW
    #define PF_7_OTYPE     GPIO_OTYPE_PP
    #define PF_7_AF        GPIO_AF0
    #define PF_7_DEFAULT_STATE 0
#else
    #if (PF_7_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_7_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_7_AF not defined'
        #endif
    #else
        #ifdef PF_7_AF
            #error 'PF_7_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_7_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_7_DEFAULT_STATE
            #warning 'PF_7_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_7_DEFAULT_STATE
        #define PF_7_DEFAULT_STATE 0
    #endif
    #ifndef PF_7_AF
        #define PF_7_AF GPIO_AF0
    #endif
    #ifndef PF_7_OTYPE
        #define PF_7_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_7_PUPD
        #define PF_7_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_7_OSPEED
        #define PF_7_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_8_MODE
    #define PF_8_MODE      GPIO_MODE_ANALOG
    #define PF_8_PUPD      GPIO_PUPD_NONE
    #define PF_8_OSPEED    GPIO_OSPEED_LOW
    #define PF_8_OTYPE     GPIO_OTYPE_PP
    #define PF_8_AF        GPIO_AF0
    #define PF_8_DEFAULT_STATE 0
#else
    #if (PF_8_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_8_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_8_AF not defined'
        #endif
    #else
        #ifdef PF_8_AF
            #error 'PF_8_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_8_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_8_DEFAULT_STATE
            #warning 'PF_8_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_8_DEFAULT_STATE
        #define PF_8_DEFAULT_STATE 0
    #endif
    #ifndef PF_8_AF
        #define PF_8_AF GPIO_AF0
    #endif
    #ifndef PF_8_OTYPE
        #define PF_8_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_8_PUPD
        #define PF_8_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_8_OSPEED
        #define PF_8_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_9_MODE
    #define PF_9_MODE      GPIO_MODE_ANALOG
    #define PF_9_PUPD      GPIO_PUPD_NONE
    #define PF_9_OSPEED    GPIO_OSPEED_LOW
    #define PF_9_OTYPE     GPIO_OTYPE_PP
    #define PF_9_AF        GPIO_AF0
    #define PF_9_DEFAULT_STATE 0
#else
    #if (PF_9_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_9_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_9_AF not defined'
        #endif
    #else
        #ifdef PF_9_AF
            #error 'PF_9_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_9_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_9_DEFAULT_STATE
            #warning 'PF_9_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_9_DEFAULT_STATE
        #define PF_9_DEFAULT_STATE 0
    #endif
    #ifndef PF_9_AF
        #define PF_9_AF GPIO_AF0
    #endif
    #ifndef PF_9_OTYPE
        #define PF_9_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_9_PUPD
        #define PF_9_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_9_OSPEED
        #define PF_9_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_10_MODE
    #define PF_10_MODE      GPIO_MODE_ANALOG
    #define PF_10_PUPD      GPIO_PUPD_NONE
    #define PF_10_OSPEED    GPIO_OSPEED_LOW
    #define PF_10_OTYPE     GPIO_OTYPE_PP
    #define PF_10_AF        GPIO_AF0
    #define PF_10_DEFAULT_STATE 0
#else
    #if (PF_10_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_10_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_10_AF not defined'
        #endif
    #else
        #ifdef PF_10_AF
            #error 'PF_10_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_10_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_10_DEFAULT_STATE
            #warning 'PF_10_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_10_DEFAULT_STATE
        #define PF_10_DEFAULT_STATE 0
    #endif
    #ifndef PF_10_AF
        #define PF_10_AF GPIO_AF0
    #endif
    #ifndef PF_10_OTYPE
        #define PF_10_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_10_PUPD
        #define PF_10_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_10_OSPEED
        #define PF_10_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_11_MODE
    #define PF_11_MODE      GPIO_MODE_ANALOG
    #define PF_11_PUPD      GPIO_PUPD_NONE
    #define PF_11_OSPEED    GPIO_OSPEED_LOW
    #define PF_11_OTYPE     GPIO_OTYPE_PP
    #define PF_11_AF        GPIO_AF0
    #define PF_11_DEFAULT_STATE 0
#else
    #if (PF_11_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_11_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_11_AF not defined'
        #endif
    #else
        #ifdef PF_11_AF
            #error 'PF_11_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_11_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_11_DEFAULT_STATE
            #warning 'PF_11_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_11_DEFAULT_STATE
        #define PF_11_DEFAULT_STATE 0
    #endif
    #ifndef PF_11_AF
        #define PF_11_AF GPIO_AF0
    #endif
    #ifndef PF_11_OTYPE
        #define PF_11_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_11_PUPD
        #define PF_11_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_11_OSPEED
        #define PF_11_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_12_MODE
    #define PF_12_MODE      GPIO_MODE_ANALOG
    #define PF_12_PUPD      GPIO_PUPD_NONE
    #define PF_12_OSPEED    GPIO_OSPEED_LOW
    #define PF_12_OTYPE     GPIO_OTYPE_PP
    #define PF_12_AF        GPIO_AF0
    #define PF_12_DEFAULT_STATE 0
#else
    #if (PF_12_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_12_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_12_AF not defined'
        #endif
    #else
        #ifdef PF_12_AF
            #error 'PF_12_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_12_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_12_DEFAULT_STATE
            #warning 'PF_12_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_12_DEFAULT_STATE
        #define PF_12_DEFAULT_STATE 0
    #endif
    #ifndef PF_12_AF
        #define PF_12_AF GPIO_AF0
    #endif
    #ifndef PF_12_OTYPE
        #define PF_12_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_12_PUPD
        #define PF_12_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_12_OSPEED
        #define PF_12_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_13_MODE
    #define PF_13_MODE      GPIO_MODE_ANALOG
    #define PF_13_PUPD      GPIO_PUPD_NONE
    #define PF_13_OSPEED    GPIO_OSPEED_LOW
    #define PF_13_OTYPE     GPIO_OTYPE_PP
    #define PF_13_AF        GPIO_AF0
    #define PF_13_DEFAULT_STATE 0
#else
    #if (PF_13_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_13_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_13_AF not defined'
        #endif
    #else
        #ifdef PF_13_AF
            #error 'PF_13_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_13_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_13_DEFAULT_STATE
            #warning 'PF_13_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_13_DEFAULT_STATE
        #define PF_13_DEFAULT_STATE 0
    #endif
    #ifndef PF_13_AF
        #define PF_13_AF GPIO_AF0
    #endif
    #ifndef PF_13_OTYPE
        #define PF_13_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_13_PUPD
        #define PF_13_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_13_OSPEED
        #define PF_13_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_14_MODE
    #define PF_14_MODE      GPIO_MODE_ANALOG
    #define PF_14_PUPD      GPIO_PUPD_NONE
    #define PF_14_OSPEED    GPIO_OSPEED_LOW
    #define PF_14_OTYPE     GPIO_OTYPE_PP
    #define PF_14_AF        GPIO_AF0
    #define PF_14_DEFAULT_STATE 0
#else
    #if (PF_14_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_14_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_14_AF not defined'
        #endif
    #else
        #ifdef PF_14_AF
            #error 'PF_14_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_14_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_14_DEFAULT_STATE
            #warning 'PF_14_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_14_DEFAULT_STATE
        #define PF_14_DEFAULT_STATE 0
    #endif
    #ifndef PF_14_AF
        #define PF_14_AF GPIO_AF0
    #endif
    #ifndef PF_14_OTYPE
        #define PF_14_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_14_PUPD
        #define PF_14_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_14_OSPEED
        #define PF_14_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PF_15_MODE
    #define PF_15_MODE      GPIO_MODE_ANALOG
    #define PF_15_PUPD      GPIO_PUPD_NONE
    #define PF_15_OSPEED    GPIO_OSPEED_LOW
    #define PF_15_OTYPE     GPIO_OTYPE_PP
    #define PF_15_AF        GPIO_AF0
    #define PF_15_DEFAULT_STATE 0
#else
    #if (PF_15_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PF_15_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PF_15_AF not defined'
        #endif
    #else
        #ifdef PF_15_AF
            #error 'PF_15_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PF_15_MODE == GPIO_MODE_OUTPUT)
        #ifndef PF_15_DEFAULT_STATE
            #warning 'PF_15_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PF_15_DEFAULT_STATE
        #define PF_15_DEFAULT_STATE 0
    #endif
    #ifndef PF_15_AF
        #define PF_15_AF GPIO_AF0
    #endif
    #ifndef PF_15_OTYPE
        #define PF_15_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PF_15_PUPD
        #define PF_15_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PF_15_OSPEED
        #define PF_15_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_0_MODE
    #define PG_0_MODE      GPIO_MODE_ANALOG
    #define PG_0_PUPD      GPIO_PUPD_NONE
    #define PG_0_OSPEED    GPIO_OSPEED_LOW
    #define PG_0_OTYPE     GPIO_OTYPE_PP
    #define PG_0_AF        GPIO_AF0
    #define PG_0_DEFAULT_STATE 0
#else
    #if (PG_0_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_0_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_0_AF not defined'
        #endif
    #else
        #ifdef PG_0_AF
            #error 'PG_0_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_0_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_0_DEFAULT_STATE
            #warning 'PG_0_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_0_DEFAULT_STATE
        #define PG_0_DEFAULT_STATE 0
    #endif
    #ifndef PG_0_AF
        #define PG_0_AF GPIO_AF0
    #endif
    #ifndef PG_0_OTYPE
        #define PG_0_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_0_PUPD
        #define PG_0_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_0_OSPEED
        #define PG_0_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_1_MODE
    #define PG_1_MODE      GPIO_MODE_ANALOG
    #define PG_1_PUPD      GPIO_PUPD_NONE
    #define PG_1_OSPEED    GPIO_OSPEED_LOW
    #define PG_1_OTYPE     GPIO_OTYPE_PP
    #define PG_1_AF        GPIO_AF0
    #define PG_1_DEFAULT_STATE 0
#else
    #if (PG_1_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_1_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_1_AF not defined'
        #endif
    #else
        #ifdef PG_1_AF
            #error 'PG_1_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_1_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_1_DEFAULT_STATE
            #warning 'PG_1_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_1_DEFAULT_STATE
        #define PG_1_DEFAULT_STATE 0
    #endif
    #ifndef PG_1_AF
        #define PG_1_AF GPIO_AF0
    #endif
    #ifndef PG_1_OTYPE
        #define PG_1_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_1_PUPD
        #define PG_1_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_1_OSPEED
        #define PG_1_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_2_MODE
    #define PG_2_MODE      GPIO_MODE_ANALOG
    #define PG_2_PUPD      GPIO_PUPD_NONE
    #define PG_2_OSPEED    GPIO_OSPEED_LOW
    #define PG_2_OTYPE     GPIO_OTYPE_PP
    #define PG_2_AF        GPIO_AF0
    #define PG_2_DEFAULT_STATE 0
#else
    #if (PG_2_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_2_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_2_AF not defined'
        #endif
    #else
        #ifdef PG_2_AF
            #error 'PG_2_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_2_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_2_DEFAULT_STATE
            #warning 'PG_2_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_2_DEFAULT_STATE
        #define PG_2_DEFAULT_STATE 0
    #endif
    #ifndef PG_2_AF
        #define PG_2_AF GPIO_AF0
    #endif
    #ifndef PG_2_OTYPE
        #define PG_2_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_2_PUPD
        #define PG_2_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_2_OSPEED
        #define PG_2_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_3_MODE
    #define PG_3_MODE      GPIO_MODE_ANALOG
    #define PG_3_PUPD      GPIO_PUPD_NONE
    #define PG_3_OSPEED    GPIO_OSPEED_LOW
    #define PG_3_OTYPE     GPIO_OTYPE_PP
    #define PG_3_AF        GPIO_AF0
    #define PG_3_DEFAULT_STATE 0
#else
    #if (PG_3_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_3_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_3_AF not defined'
        #endif
    #else
        #ifdef PG_3_AF
            #error 'PG_3_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_3_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_3_DEFAULT_STATE
            #warning 'PG_3_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_3_DEFAULT_STATE
        #define PG_3_DEFAULT_STATE 0
    #endif
    #ifndef PG_3_AF
        #define PG_3_AF GPIO_AF0
    #endif
    #ifndef PG_3_OTYPE
        #define PG_3_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_3_PUPD
        #define PG_3_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_3_OSPEED
        #define PG_3_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_4_MODE
    #define PG_4_MODE      GPIO_MODE_ANALOG
    #define PG_4_PUPD      GPIO_PUPD_NONE
    #define PG_4_OSPEED    GPIO_OSPEED_LOW
    #define PG_4_OTYPE     GPIO_OTYPE_PP
    #define PG_4_AF        GPIO_AF0
    #define PG_4_DEFAULT_STATE 0
#else
    #if (PG_4_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_4_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_4_AF not defined'
        #endif
    #else
        #ifdef PG_4_AF
            #error 'PG_4_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_4_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_4_DEFAULT_STATE
            #warning 'PG_4_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_4_DEFAULT_STATE
        #define PG_4_DEFAULT_STATE 0
    #endif
    #ifndef PG_4_AF
        #define PG_4_AF GPIO_AF0
    #endif
    #ifndef PG_4_OTYPE
        #define PG_4_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_4_PUPD
        #define PG_4_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_4_OSPEED
        #define PG_4_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_5_MODE
    #define PG_5_MODE      GPIO_MODE_ANALOG
    #define PG_5_PUPD      GPIO_PUPD_NONE
    #define PG_5_OSPEED    GPIO_OSPEED_LOW
    #define PG_5_OTYPE     GPIO_OTYPE_PP
    #define PG_5_AF        GPIO_AF0
    #define PG_5_DEFAULT_STATE 0
#else
    #if (PG_5_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_5_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_5_AF not defined'
        #endif
    #else
        #ifdef PG_5_AF
            #error 'PG_5_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_5_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_5_DEFAULT_STATE
            #warning 'PG_5_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_5_DEFAULT_STATE
        #define PG_5_DEFAULT_STATE 0
    #endif
    #ifndef PG_5_AF
        #define PG_5_AF GPIO_AF0
    #endif
    #ifndef PG_5_OTYPE
        #define PG_5_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_5_PUPD
        #define PG_5_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_5_OSPEED
        #define PG_5_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_6_MODE
    #define PG_6_MODE      GPIO_MODE_ANALOG
    #define PG_6_PUPD      GPIO_PUPD_NONE
    #define PG_6_OSPEED    GPIO_OSPEED_LOW
    #define PG_6_OTYPE     GPIO_OTYPE_PP
    #define PG_6_AF        GPIO_AF0
    #define PG_6_DEFAULT_STATE 0
#else
    #if (PG_6_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_6_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_6_AF not defined'
        #endif
    #else
        #ifdef PG_6_AF
            #error 'PG_6_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_6_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_6_DEFAULT_STATE
            #warning 'PG_6_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_6_DEFAULT_STATE
        #define PG_6_DEFAULT_STATE 0
    #endif
    #ifndef PG_6_AF
        #define PG_6_AF GPIO_AF0
    #endif
    #ifndef PG_6_OTYPE
        #define PG_6_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_6_PUPD
        #define PG_6_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_6_OSPEED
        #define PG_6_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_7_MODE
    #define PG_7_MODE      GPIO_MODE_ANALOG
    #define PG_7_PUPD      GPIO_PUPD_NONE
    #define PG_7_OSPEED    GPIO_OSPEED_LOW
    #define PG_7_OTYPE     GPIO_OTYPE_PP
    #define PG_7_AF        GPIO_AF0
    #define PG_7_DEFAULT_STATE 0
#else
    #if (PG_7_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_7_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_7_AF not defined'
        #endif
    #else
        #ifdef PG_7_AF
            #error 'PG_7_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_7_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_7_DEFAULT_STATE
            #warning 'PG_7_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_7_DEFAULT_STATE
        #define PG_7_DEFAULT_STATE 0
    #endif
    #ifndef PG_7_AF
        #define PG_7_AF GPIO_AF0
    #endif
    #ifndef PG_7_OTYPE
        #define PG_7_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_7_PUPD
        #define PG_7_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_7_OSPEED
        #define PG_7_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_8_MODE
    #define PG_8_MODE      GPIO_MODE_ANALOG
    #define PG_8_PUPD      GPIO_PUPD_NONE
    #define PG_8_OSPEED    GPIO_OSPEED_LOW
    #define PG_8_OTYPE     GPIO_OTYPE_PP
    #define PG_8_AF        GPIO_AF0
    #define PG_8_DEFAULT_STATE 0
#else
    #if (PG_8_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_8_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_8_AF not defined'
        #endif
    #else
        #ifdef PG_8_AF
            #error 'PG_8_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_8_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_8_DEFAULT_STATE
            #warning 'PG_8_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_8_DEFAULT_STATE
        #define PG_8_DEFAULT_STATE 0
    #endif
    #ifndef PG_8_AF
        #define PG_8_AF GPIO_AF0
    #endif
    #ifndef PG_8_OTYPE
        #define PG_8_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_8_PUPD
        #define PG_8_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_8_OSPEED
        #define PG_8_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_9_MODE
    #define PG_9_MODE      GPIO_MODE_ANALOG
    #define PG_9_PUPD      GPIO_PUPD_NONE
    #define PG_9_OSPEED    GPIO_OSPEED_LOW
    #define PG_9_OTYPE     GPIO_OTYPE_PP
    #define PG_9_AF        GPIO_AF0
    #define PG_9_DEFAULT_STATE 0
#else
    #if (PG_9_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_9_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_9_AF not defined'
        #endif
    #else
        #ifdef PG_9_AF
            #error 'PG_9_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_9_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_9_DEFAULT_STATE
            #warning 'PG_9_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_9_DEFAULT_STATE
        #define PG_9_DEFAULT_STATE 0
    #endif
    #ifndef PG_9_AF
        #define PG_9_AF GPIO_AF0
    #endif
    #ifndef PG_9_OTYPE
        #define PG_9_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_9_PUPD
        #define PG_9_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_9_OSPEED
        #define PG_9_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_10_MODE
    #define PG_10_MODE      GPIO_MODE_ANALOG
    #define PG_10_PUPD      GPIO_PUPD_NONE
    #define PG_10_OSPEED    GPIO_OSPEED_LOW
    #define PG_10_OTYPE     GPIO_OTYPE_PP
    #define PG_10_AF        GPIO_AF0
    #define PG_10_DEFAULT_STATE 0
#else
    #if (PG_10_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_10_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_10_AF not defined'
        #endif
    #else
        #ifdef PG_10_AF
            #error 'PG_10_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_10_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_10_DEFAULT_STATE
            #warning 'PG_10_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_10_DEFAULT_STATE
        #define PG_10_DEFAULT_STATE 0
    #endif
    #ifndef PG_10_AF
        #define PG_10_AF GPIO_AF0
    #endif
    #ifndef PG_10_OTYPE
        #define PG_10_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_10_PUPD
        #define PG_10_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_10_OSPEED
        #define PG_10_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_11_MODE
    #define PG_11_MODE      GPIO_MODE_ANALOG
    #define PG_11_PUPD      GPIO_PUPD_NONE
    #define PG_11_OSPEED    GPIO_OSPEED_LOW
    #define PG_11_OTYPE     GPIO_OTYPE_PP
    #define PG_11_AF        GPIO_AF0
    #define PG_11_DEFAULT_STATE 0
#else
    #if (PG_11_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_11_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_11_AF not defined'
        #endif
    #else
        #ifdef PG_11_AF
            #error 'PG_11_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_11_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_11_DEFAULT_STATE
            #warning 'PG_11_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_11_DEFAULT_STATE
        #define PG_11_DEFAULT_STATE 0
    #endif
    #ifndef PG_11_AF
        #define PG_11_AF GPIO_AF0
    #endif
    #ifndef PG_11_OTYPE
        #define PG_11_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_11_PUPD
        #define PG_11_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_11_OSPEED
        #define PG_11_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_12_MODE
    #define PG_12_MODE      GPIO_MODE_ANALOG
    #define PG_12_PUPD      GPIO_PUPD_NONE
    #define PG_12_OSPEED    GPIO_OSPEED_LOW
    #define PG_12_OTYPE     GPIO_OTYPE_PP
    #define PG_12_AF        GPIO_AF0
    #define PG_12_DEFAULT_STATE 0
#else
    #if (PG_12_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_12_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_12_AF not defined'
        #endif
    #else
        #ifdef PG_12_AF
            #error 'PG_12_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_12_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_12_DEFAULT_STATE
            #warning 'PG_12_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_12_DEFAULT_STATE
        #define PG_12_DEFAULT_STATE 0
    #endif
    #ifndef PG_12_AF
        #define PG_12_AF GPIO_AF0
    #endif
    #ifndef PG_12_OTYPE
        #define PG_12_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_12_PUPD
        #define PG_12_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_12_OSPEED
        #define PG_12_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_13_MODE
    #define PG_13_MODE      GPIO_MODE_ANALOG
    #define PG_13_PUPD      GPIO_PUPD_NONE
    #define PG_13_OSPEED    GPIO_OSPEED_LOW
    #define PG_13_OTYPE     GPIO_OTYPE_PP
    #define PG_13_AF        GPIO_AF0
    #define PG_13_DEFAULT_STATE 0
#else
    #if (PG_13_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_13_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_13_AF not defined'
        #endif
    #else
        #ifdef PG_13_AF
            #error 'PG_13_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_13_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_13_DEFAULT_STATE
            #warning 'PG_13_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_13_DEFAULT_STATE
        #define PG_13_DEFAULT_STATE 0
    #endif
    #ifndef PG_13_AF
        #define PG_13_AF GPIO_AF0
    #endif
    #ifndef PG_13_OTYPE
        #define PG_13_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_13_PUPD
        #define PG_13_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_13_OSPEED
        #define PG_13_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_14_MODE
    #define PG_14_MODE      GPIO_MODE_ANALOG
    #define PG_14_PUPD      GPIO_PUPD_NONE
    #define PG_14_OSPEED    GPIO_OSPEED_LOW
    #define PG_14_OTYPE     GPIO_OTYPE_PP
    #define PG_14_AF        GPIO_AF0
    #define PG_14_DEFAULT_STATE 0
#else
    #if (PG_14_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_14_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_14_AF not defined'
        #endif
    #else
        #ifdef PG_14_AF
            #error 'PG_14_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_14_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_14_DEFAULT_STATE
            #warning 'PG_14_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_14_DEFAULT_STATE
        #define PG_14_DEFAULT_STATE 0
    #endif
    #ifndef PG_14_AF
        #define PG_14_AF GPIO_AF0
    #endif
    #ifndef PG_14_OTYPE
        #define PG_14_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_14_PUPD
        #define PG_14_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_14_OSPEED
        #define PG_14_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PG_15_MODE
    #define PG_15_MODE      GPIO_MODE_ANALOG
    #define PG_15_PUPD      GPIO_PUPD_NONE
    #define PG_15_OSPEED    GPIO_OSPEED_LOW
    #define PG_15_OTYPE     GPIO_OTYPE_PP
    #define PG_15_AF        GPIO_AF0
    #define PG_15_DEFAULT_STATE 0
#else
    #if (PG_15_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PG_15_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PG_15_AF not defined'
        #endif
    #else
        #ifdef PG_15_AF
            #error 'PG_15_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PG_15_MODE == GPIO_MODE_OUTPUT)
        #ifndef PG_15_DEFAULT_STATE
            #warning 'PG_15_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PG_15_DEFAULT_STATE
        #define PG_15_DEFAULT_STATE 0
    #endif
    #ifndef PG_15_AF
        #define PG_15_AF GPIO_AF0
    #endif
    #ifndef PG_15_OTYPE
        #define PG_15_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PG_15_PUPD
        #define PG_15_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PG_15_OSPEED
        #define PG_15_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_0_MODE
    #define PH_0_MODE      GPIO_MODE_ANALOG
    #define PH_0_PUPD      GPIO_PUPD_NONE
    #define PH_0_OSPEED    GPIO_OSPEED_LOW
    #define PH_0_OTYPE     GPIO_OTYPE_PP
    #define PH_0_AF        GPIO_AF0
    #define PH_0_DEFAULT_STATE 0
#else
    #if (PH_0_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_0_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_0_AF not defined'
        #endif
    #else
        #ifdef PH_0_AF
            #error 'PH_0_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_0_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_0_DEFAULT_STATE
            #warning 'PH_0_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_0_DEFAULT_STATE
        #define PH_0_DEFAULT_STATE 0
    #endif
    #ifndef PH_0_AF
        #define PH_0_AF GPIO_AF0
    #endif
    #ifndef PH_0_OTYPE
        #define PH_0_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_0_PUPD
        #define PH_0_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_0_OSPEED
        #define PH_0_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_1_MODE
    #define PH_1_MODE      GPIO_MODE_ANALOG
    #define PH_1_PUPD      GPIO_PUPD_NONE
    #define PH_1_OSPEED    GPIO_OSPEED_LOW
    #define PH_1_OTYPE     GPIO_OTYPE_PP
    #define PH_1_AF        GPIO_AF0
    #define PH_1_DEFAULT_STATE 0
#else
    #if (PH_1_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_1_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_1_AF not defined'
        #endif
    #else
        #ifdef PH_1_AF
            #error 'PH_1_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_1_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_1_DEFAULT_STATE
            #warning 'PH_1_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_1_DEFAULT_STATE
        #define PH_1_DEFAULT_STATE 0
    #endif
    #ifndef PH_1_AF
        #define PH_1_AF GPIO_AF0
    #endif
    #ifndef PH_1_OTYPE
        #define PH_1_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_1_PUPD
        #define PH_1_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_1_OSPEED
        #define PH_1_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_2_MODE
    #define PH_2_MODE      GPIO_MODE_ANALOG
    #define PH_2_PUPD      GPIO_PUPD_NONE
    #define PH_2_OSPEED    GPIO_OSPEED_LOW
    #define PH_2_OTYPE     GPIO_OTYPE_PP
    #define PH_2_AF        GPIO_AF0
    #define PH_2_DEFAULT_STATE 0
#else
    #if (PH_2_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_2_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_2_AF not defined'
        #endif
    #else
        #ifdef PH_2_AF
            #error 'PH_2_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_2_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_2_DEFAULT_STATE
            #warning 'PH_2_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_2_DEFAULT_STATE
        #define PH_2_DEFAULT_STATE 0
    #endif
    #ifndef PH_2_AF
        #define PH_2_AF GPIO_AF0
    #endif
    #ifndef PH_2_OTYPE
        #define PH_2_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_2_PUPD
        #define PH_2_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_2_OSPEED
        #define PH_2_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_3_MODE
    #define PH_3_MODE      GPIO_MODE_ANALOG
    #define PH_3_PUPD      GPIO_PUPD_NONE
    #define PH_3_OSPEED    GPIO_OSPEED_LOW
    #define PH_3_OTYPE     GPIO_OTYPE_PP
    #define PH_3_AF        GPIO_AF0
    #define PH_3_DEFAULT_STATE 0
#else
    #if (PH_3_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_3_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_3_AF not defined'
        #endif
    #else
        #ifdef PH_3_AF
            #error 'PH_3_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_3_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_3_DEFAULT_STATE
            #warning 'PH_3_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_3_DEFAULT_STATE
        #define PH_3_DEFAULT_STATE 0
    #endif
    #ifndef PH_3_AF
        #define PH_3_AF GPIO_AF0
    #endif
    #ifndef PH_3_OTYPE
        #define PH_3_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_3_PUPD
        #define PH_3_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_3_OSPEED
        #define PH_3_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_4_MODE
    #define PH_4_MODE      GPIO_MODE_ANALOG
    #define PH_4_PUPD      GPIO_PUPD_NONE
    #define PH_4_OSPEED    GPIO_OSPEED_LOW
    #define PH_4_OTYPE     GPIO_OTYPE_PP
    #define PH_4_AF        GPIO_AF0
    #define PH_4_DEFAULT_STATE 0
#else
    #if (PH_4_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_4_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_4_AF not defined'
        #endif
    #else
        #ifdef PH_4_AF
            #error 'PH_4_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_4_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_4_DEFAULT_STATE
            #warning 'PH_4_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_4_DEFAULT_STATE
        #define PH_4_DEFAULT_STATE 0
    #endif
    #ifndef PH_4_AF
        #define PH_4_AF GPIO_AF0
    #endif
    #ifndef PH_4_OTYPE
        #define PH_4_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_4_PUPD
        #define PH_4_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_4_OSPEED
        #define PH_4_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_5_MODE
    #define PH_5_MODE      GPIO_MODE_ANALOG
    #define PH_5_PUPD      GPIO_PUPD_NONE
    #define PH_5_OSPEED    GPIO_OSPEED_LOW
    #define PH_5_OTYPE     GPIO_OTYPE_PP
    #define PH_5_AF        GPIO_AF0
    #define PH_5_DEFAULT_STATE 0
#else
    #if (PH_5_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_5_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_5_AF not defined'
        #endif
    #else
        #ifdef PH_5_AF
            #error 'PH_5_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_5_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_5_DEFAULT_STATE
            #warning 'PH_5_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_5_DEFAULT_STATE
        #define PH_5_DEFAULT_STATE 0
    #endif
    #ifndef PH_5_AF
        #define PH_5_AF GPIO_AF0
    #endif
    #ifndef PH_5_OTYPE
        #define PH_5_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_5_PUPD
        #define PH_5_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_5_OSPEED
        #define PH_5_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_6_MODE
    #define PH_6_MODE      GPIO_MODE_ANALOG
    #define PH_6_PUPD      GPIO_PUPD_NONE
    #define PH_6_OSPEED    GPIO_OSPEED_LOW
    #define PH_6_OTYPE     GPIO_OTYPE_PP
    #define PH_6_AF        GPIO_AF0
    #define PH_6_DEFAULT_STATE 0
#else
    #if (PH_6_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_6_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_6_AF not defined'
        #endif
    #else
        #ifdef PH_6_AF
            #error 'PH_6_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_6_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_6_DEFAULT_STATE
            #warning 'PH_6_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_6_DEFAULT_STATE
        #define PH_6_DEFAULT_STATE 0
    #endif
    #ifndef PH_6_AF
        #define PH_6_AF GPIO_AF0
    #endif
    #ifndef PH_6_OTYPE
        #define PH_6_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_6_PUPD
        #define PH_6_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_6_OSPEED
        #define PH_6_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_7_MODE
    #define PH_7_MODE      GPIO_MODE_ANALOG
    #define PH_7_PUPD      GPIO_PUPD_NONE
    #define PH_7_OSPEED    GPIO_OSPEED_LOW
    #define PH_7_OTYPE     GPIO_OTYPE_PP
    #define PH_7_AF        GPIO_AF0
    #define PH_7_DEFAULT_STATE 0
#else
    #if (PH_7_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_7_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_7_AF not defined'
        #endif
    #else
        #ifdef PH_7_AF
            #error 'PH_7_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_7_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_7_DEFAULT_STATE
            #warning 'PH_7_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_7_DEFAULT_STATE
        #define PH_7_DEFAULT_STATE 0
    #endif
    #ifndef PH_7_AF
        #define PH_7_AF GPIO_AF0
    #endif
    #ifndef PH_7_OTYPE
        #define PH_7_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_7_PUPD
        #define PH_7_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_7_OSPEED
        #define PH_7_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_8_MODE
    #define PH_8_MODE      GPIO_MODE_ANALOG
    #define PH_8_PUPD      GPIO_PUPD_NONE
    #define PH_8_OSPEED    GPIO_OSPEED_LOW
    #define PH_8_OTYPE     GPIO_OTYPE_PP
    #define PH_8_AF        GPIO_AF0
    #define PH_8_DEFAULT_STATE 0
#else
    #if (PH_8_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_8_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_8_AF not defined'
        #endif
    #else
        #ifdef PH_8_AF
            #error 'PH_8_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_8_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_8_DEFAULT_STATE
            #warning 'PH_8_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_8_DEFAULT_STATE
        #define PH_8_DEFAULT_STATE 0
    #endif
    #ifndef PH_8_AF
        #define PH_8_AF GPIO_AF0
    #endif
    #ifndef PH_8_OTYPE
        #define PH_8_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_8_PUPD
        #define PH_8_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_8_OSPEED
        #define PH_8_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_9_MODE
    #define PH_9_MODE      GPIO_MODE_ANALOG
    #define PH_9_PUPD      GPIO_PUPD_NONE
    #define PH_9_OSPEED    GPIO_OSPEED_LOW
    #define PH_9_OTYPE     GPIO_OTYPE_PP
    #define PH_9_AF        GPIO_AF0
    #define PH_9_DEFAULT_STATE 0
#else
    #if (PH_9_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_9_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_9_AF not defined'
        #endif
    #else
        #ifdef PH_9_AF
            #error 'PH_9_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_9_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_9_DEFAULT_STATE
            #warning 'PH_9_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_9_DEFAULT_STATE
        #define PH_9_DEFAULT_STATE 0
    #endif
    #ifndef PH_9_AF
        #define PH_9_AF GPIO_AF0
    #endif
    #ifndef PH_9_OTYPE
        #define PH_9_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_9_PUPD
        #define PH_9_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_9_OSPEED
        #define PH_9_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_10_MODE
    #define PH_10_MODE      GPIO_MODE_ANALOG
    #define PH_10_PUPD      GPIO_PUPD_NONE
    #define PH_10_OSPEED    GPIO_OSPEED_LOW
    #define PH_10_OTYPE     GPIO_OTYPE_PP
    #define PH_10_AF        GPIO_AF0
    #define PH_10_DEFAULT_STATE 0
#else
    #if (PH_10_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_10_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_10_AF not defined'
        #endif
    #else
        #ifdef PH_10_AF
            #error 'PH_10_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_10_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_10_DEFAULT_STATE
            #warning 'PH_10_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_10_DEFAULT_STATE
        #define PH_10_DEFAULT_STATE 0
    #endif
    #ifndef PH_10_AF
        #define PH_10_AF GPIO_AF0
    #endif
    #ifndef PH_10_OTYPE
        #define PH_10_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_10_PUPD
        #define PH_10_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_10_OSPEED
        #define PH_10_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_11_MODE
    #define PH_11_MODE      GPIO_MODE_ANALOG
    #define PH_11_PUPD      GPIO_PUPD_NONE
    #define PH_11_OSPEED    GPIO_OSPEED_LOW
    #define PH_11_OTYPE     GPIO_OTYPE_PP
    #define PH_11_AF        GPIO_AF0
    #define PH_11_DEFAULT_STATE 0
#else
    #if (PH_11_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_11_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_11_AF not defined'
        #endif
    #else
        #ifdef PH_11_AF
            #error 'PH_11_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_11_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_11_DEFAULT_STATE
            #warning 'PH_11_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_11_DEFAULT_STATE
        #define PH_11_DEFAULT_STATE 0
    #endif
    #ifndef PH_11_AF
        #define PH_11_AF GPIO_AF0
    #endif
    #ifndef PH_11_OTYPE
        #define PH_11_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_11_PUPD
        #define PH_11_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_11_OSPEED
        #define PH_11_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_12_MODE
    #define PH_12_MODE      GPIO_MODE_ANALOG
    #define PH_12_PUPD      GPIO_PUPD_NONE
    #define PH_12_OSPEED    GPIO_OSPEED_LOW
    #define PH_12_OTYPE     GPIO_OTYPE_PP
    #define PH_12_AF        GPIO_AF0
    #define PH_12_DEFAULT_STATE 0
#else
    #if (PH_12_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_12_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_12_AF not defined'
        #endif
    #else
        #ifdef PH_12_AF
            #error 'PH_12_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_12_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_12_DEFAULT_STATE
            #warning 'PH_12_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_12_DEFAULT_STATE
        #define PH_12_DEFAULT_STATE 0
    #endif
    #ifndef PH_12_AF
        #define PH_12_AF GPIO_AF0
    #endif
    #ifndef PH_12_OTYPE
        #define PH_12_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_12_PUPD
        #define PH_12_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_12_OSPEED
        #define PH_12_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_13_MODE
    #define PH_13_MODE      GPIO_MODE_ANALOG
    #define PH_13_PUPD      GPIO_PUPD_NONE
    #define PH_13_OSPEED    GPIO_OSPEED_LOW
    #define PH_13_OTYPE     GPIO_OTYPE_PP
    #define PH_13_AF        GPIO_AF0
    #define PH_13_DEFAULT_STATE 0
#else
    #if (PH_13_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_13_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_13_AF not defined'
        #endif
    #else
        #ifdef PH_13_AF
            #error 'PH_13_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_13_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_13_DEFAULT_STATE
            #warning 'PH_13_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_13_DEFAULT_STATE
        #define PH_13_DEFAULT_STATE 0
    #endif
    #ifndef PH_13_AF
        #define PH_13_AF GPIO_AF0
    #endif
    #ifndef PH_13_OTYPE
        #define PH_13_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_13_PUPD
        #define PH_13_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_13_OSPEED
        #define PH_13_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_14_MODE
    #define PH_14_MODE      GPIO_MODE_ANALOG
    #define PH_14_PUPD      GPIO_PUPD_NONE
    #define PH_14_OSPEED    GPIO_OSPEED_LOW
    #define PH_14_OTYPE     GPIO_OTYPE_PP
    #define PH_14_AF        GPIO_AF0
    #define PH_14_DEFAULT_STATE 0
#else
    #if (PH_14_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_14_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_14_AF not defined'
        #endif
    #else
        #ifdef PH_14_AF
            #error 'PH_14_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_14_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_14_DEFAULT_STATE
            #warning 'PH_14_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_14_DEFAULT_STATE
        #define PH_14_DEFAULT_STATE 0
    #endif
    #ifndef PH_14_AF
        #define PH_14_AF GPIO_AF0
    #endif
    #ifndef PH_14_OTYPE
        #define PH_14_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_14_PUPD
        #define PH_14_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_14_OSPEED
        #define PH_14_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PH_15_MODE
    #define PH_15_MODE      GPIO_MODE_ANALOG
    #define PH_15_PUPD      GPIO_PUPD_NONE
    #define PH_15_OSPEED    GPIO_OSPEED_LOW
    #define PH_15_OTYPE     GPIO_OTYPE_PP
    #define PH_15_AF        GPIO_AF0
    #define PH_15_DEFAULT_STATE 0
#else
    #if (PH_15_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PH_15_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PH_15_AF not defined'
        #endif
    #else
        #ifdef PH_15_AF
            #error 'PH_15_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PH_15_MODE == GPIO_MODE_OUTPUT)
        #ifndef PH_15_DEFAULT_STATE
            #warning 'PH_15_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PH_15_DEFAULT_STATE
        #define PH_15_DEFAULT_STATE 0
    #endif
    #ifndef PH_15_AF
        #define PH_15_AF GPIO_AF0
    #endif
    #ifndef PH_15_OTYPE
        #define PH_15_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PH_15_PUPD
        #define PH_15_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PH_15_OSPEED
        #define PH_15_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_0_MODE
    #define PI_0_MODE      GPIO_MODE_ANALOG
    #define PI_0_PUPD      GPIO_PUPD_NONE
    #define PI_0_OSPEED    GPIO_OSPEED_LOW
    #define PI_0_OTYPE     GPIO_OTYPE_PP
    #define PI_0_AF        GPIO_AF0
    #define PI_0_DEFAULT_STATE 0
#else
    #if (PI_0_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_0_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_0_AF not defined'
        #endif
    #else
        #ifdef PI_0_AF
            #error 'PI_0_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_0_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_0_DEFAULT_STATE
            #warning 'PI_0_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_0_DEFAULT_STATE
        #define PI_0_DEFAULT_STATE 0
    #endif
    #ifndef PI_0_AF
        #define PI_0_AF GPIO_AF0
    #endif
    #ifndef PI_0_OTYPE
        #define PI_0_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_0_PUPD
        #define PI_0_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_0_OSPEED
        #define PI_0_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_1_MODE
    #define PI_1_MODE      GPIO_MODE_ANALOG
    #define PI_1_PUPD      GPIO_PUPD_NONE
    #define PI_1_OSPEED    GPIO_OSPEED_LOW
    #define PI_1_OTYPE     GPIO_OTYPE_PP
    #define PI_1_AF        GPIO_AF0
    #define PI_1_DEFAULT_STATE 0
#else
    #if (PI_1_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_1_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_1_AF not defined'
        #endif
    #else
        #ifdef PI_1_AF
            #error 'PI_1_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_1_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_1_DEFAULT_STATE
            #warning 'PI_1_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_1_DEFAULT_STATE
        #define PI_1_DEFAULT_STATE 0
    #endif
    #ifndef PI_1_AF
        #define PI_1_AF GPIO_AF0
    #endif
    #ifndef PI_1_OTYPE
        #define PI_1_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_1_PUPD
        #define PI_1_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_1_OSPEED
        #define PI_1_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_2_MODE
    #define PI_2_MODE      GPIO_MODE_ANALOG
    #define PI_2_PUPD      GPIO_PUPD_NONE
    #define PI_2_OSPEED    GPIO_OSPEED_LOW
    #define PI_2_OTYPE     GPIO_OTYPE_PP
    #define PI_2_AF        GPIO_AF0
    #define PI_2_DEFAULT_STATE 0
#else
    #if (PI_2_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_2_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_2_AF not defined'
        #endif
    #else
        #ifdef PI_2_AF
            #error 'PI_2_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_2_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_2_DEFAULT_STATE
            #warning 'PI_2_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_2_DEFAULT_STATE
        #define PI_2_DEFAULT_STATE 0
    #endif
    #ifndef PI_2_AF
        #define PI_2_AF GPIO_AF0
    #endif
    #ifndef PI_2_OTYPE
        #define PI_2_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_2_PUPD
        #define PI_2_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_2_OSPEED
        #define PI_2_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_3_MODE
    #define PI_3_MODE      GPIO_MODE_ANALOG
    #define PI_3_PUPD      GPIO_PUPD_NONE
    #define PI_3_OSPEED    GPIO_OSPEED_LOW
    #define PI_3_OTYPE     GPIO_OTYPE_PP
    #define PI_3_AF        GPIO_AF0
    #define PI_3_DEFAULT_STATE 0
#else
    #if (PI_3_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_3_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_3_AF not defined'
        #endif
    #else
        #ifdef PI_3_AF
            #error 'PI_3_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_3_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_3_DEFAULT_STATE
            #warning 'PI_3_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_3_DEFAULT_STATE
        #define PI_3_DEFAULT_STATE 0
    #endif
    #ifndef PI_3_AF
        #define PI_3_AF GPIO_AF0
    #endif
    #ifndef PI_3_OTYPE
        #define PI_3_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_3_PUPD
        #define PI_3_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_3_OSPEED
        #define PI_3_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_4_MODE
    #define PI_4_MODE      GPIO_MODE_ANALOG
    #define PI_4_PUPD      GPIO_PUPD_NONE
    #define PI_4_OSPEED    GPIO_OSPEED_LOW
    #define PI_4_OTYPE     GPIO_OTYPE_PP
    #define PI_4_AF        GPIO_AF0
    #define PI_4_DEFAULT_STATE 0
#else
    #if (PI_4_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_4_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_4_AF not defined'
        #endif
    #else
        #ifdef PI_4_AF
            #error 'PI_4_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_4_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_4_DEFAULT_STATE
            #warning 'PI_4_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_4_DEFAULT_STATE
        #define PI_4_DEFAULT_STATE 0
    #endif
    #ifndef PI_4_AF
        #define PI_4_AF GPIO_AF0
    #endif
    #ifndef PI_4_OTYPE
        #define PI_4_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_4_PUPD
        #define PI_4_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_4_OSPEED
        #define PI_4_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_5_MODE
    #define PI_5_MODE      GPIO_MODE_ANALOG
    #define PI_5_PUPD      GPIO_PUPD_NONE
    #define PI_5_OSPEED    GPIO_OSPEED_LOW
    #define PI_5_OTYPE     GPIO_OTYPE_PP
    #define PI_5_AF        GPIO_AF0
    #define PI_5_DEFAULT_STATE 0
#else
    #if (PI_5_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_5_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_5_AF not defined'
        #endif
    #else
        #ifdef PI_5_AF
            #error 'PI_5_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_5_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_5_DEFAULT_STATE
            #warning 'PI_5_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_5_DEFAULT_STATE
        #define PI_5_DEFAULT_STATE 0
    #endif
    #ifndef PI_5_AF
        #define PI_5_AF GPIO_AF0
    #endif
    #ifndef PI_5_OTYPE
        #define PI_5_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_5_PUPD
        #define PI_5_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_5_OSPEED
        #define PI_5_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_6_MODE
    #define PI_6_MODE      GPIO_MODE_ANALOG
    #define PI_6_PUPD      GPIO_PUPD_NONE
    #define PI_6_OSPEED    GPIO_OSPEED_LOW
    #define PI_6_OTYPE     GPIO_OTYPE_PP
    #define PI_6_AF        GPIO_AF0
    #define PI_6_DEFAULT_STATE 0
#else
    #if (PI_6_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_6_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_6_AF not defined'
        #endif
    #else
        #ifdef PI_6_AF
            #error 'PI_6_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_6_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_6_DEFAULT_STATE
            #warning 'PI_6_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_6_DEFAULT_STATE
        #define PI_6_DEFAULT_STATE 0
    #endif
    #ifndef PI_6_AF
        #define PI_6_AF GPIO_AF0
    #endif
    #ifndef PI_6_OTYPE
        #define PI_6_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_6_PUPD
        #define PI_6_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_6_OSPEED
        #define PI_6_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_7_MODE
    #define PI_7_MODE      GPIO_MODE_ANALOG
    #define PI_7_PUPD      GPIO_PUPD_NONE
    #define PI_7_OSPEED    GPIO_OSPEED_LOW
    #define PI_7_OTYPE     GPIO_OTYPE_PP
    #define PI_7_AF        GPIO_AF0
    #define PI_7_DEFAULT_STATE 0
#else
    #if (PI_7_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_7_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_7_AF not defined'
        #endif
    #else
        #ifdef PI_7_AF
            #error 'PI_7_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_7_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_7_DEFAULT_STATE
            #warning 'PI_7_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_7_DEFAULT_STATE
        #define PI_7_DEFAULT_STATE 0
    #endif
    #ifndef PI_7_AF
        #define PI_7_AF GPIO_AF0
    #endif
    #ifndef PI_7_OTYPE
        #define PI_7_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_7_PUPD
        #define PI_7_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_7_OSPEED
        #define PI_7_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_8_MODE
    #define PI_8_MODE      GPIO_MODE_ANALOG
    #define PI_8_PUPD      GPIO_PUPD_NONE
    #define PI_8_OSPEED    GPIO_OSPEED_LOW
    #define PI_8_OTYPE     GPIO_OTYPE_PP
    #define PI_8_AF        GPIO_AF0
    #define PI_8_DEFAULT_STATE 0
#else
    #if (PI_8_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_8_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_8_AF not defined'
        #endif
    #else
        #ifdef PI_8_AF
            #error 'PI_8_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_8_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_8_DEFAULT_STATE
            #warning 'PI_8_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_8_DEFAULT_STATE
        #define PI_8_DEFAULT_STATE 0
    #endif
    #ifndef PI_8_AF
        #define PI_8_AF GPIO_AF0
    #endif
    #ifndef PI_8_OTYPE
        #define PI_8_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_8_PUPD
        #define PI_8_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_8_OSPEED
        #define PI_8_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_9_MODE
    #define PI_9_MODE      GPIO_MODE_ANALOG
    #define PI_9_PUPD      GPIO_PUPD_NONE
    #define PI_9_OSPEED    GPIO_OSPEED_LOW
    #define PI_9_OTYPE     GPIO_OTYPE_PP
    #define PI_9_AF        GPIO_AF0
    #define PI_9_DEFAULT_STATE 0
#else
    #if (PI_9_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_9_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_9_AF not defined'
        #endif
    #else
        #ifdef PI_9_AF
            #error 'PI_9_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_9_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_9_DEFAULT_STATE
            #warning 'PI_9_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_9_DEFAULT_STATE
        #define PI_9_DEFAULT_STATE 0
    #endif
    #ifndef PI_9_AF
        #define PI_9_AF GPIO_AF0
    #endif
    #ifndef PI_9_OTYPE
        #define PI_9_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_9_PUPD
        #define PI_9_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_9_OSPEED
        #define PI_9_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_10_MODE
    #define PI_10_MODE      GPIO_MODE_ANALOG
    #define PI_10_PUPD      GPIO_PUPD_NONE
    #define PI_10_OSPEED    GPIO_OSPEED_LOW
    #define PI_10_OTYPE     GPIO_OTYPE_PP
    #define PI_10_AF        GPIO_AF0
    #define PI_10_DEFAULT_STATE 0
#else
    #if (PI_10_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_10_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_10_AF not defined'
        #endif
    #else
        #ifdef PI_10_AF
            #error 'PI_10_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_10_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_10_DEFAULT_STATE
            #warning 'PI_10_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_10_DEFAULT_STATE
        #define PI_10_DEFAULT_STATE 0
    #endif
    #ifndef PI_10_AF
        #define PI_10_AF GPIO_AF0
    #endif
    #ifndef PI_10_OTYPE
        #define PI_10_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_10_PUPD
        #define PI_10_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_10_OSPEED
        #define PI_10_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_11_MODE
    #define PI_11_MODE      GPIO_MODE_ANALOG
    #define PI_11_PUPD      GPIO_PUPD_NONE
    #define PI_11_OSPEED    GPIO_OSPEED_LOW
    #define PI_11_OTYPE     GPIO_OTYPE_PP
    #define PI_11_AF        GPIO_AF0
    #define PI_11_DEFAULT_STATE 0
#else
    #if (PI_11_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_11_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_11_AF not defined'
        #endif
    #else
        #ifdef PI_11_AF
            #error 'PI_11_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_11_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_11_DEFAULT_STATE
            #warning 'PI_11_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_11_DEFAULT_STATE
        #define PI_11_DEFAULT_STATE 0
    #endif
    #ifndef PI_11_AF
        #define PI_11_AF GPIO_AF0
    #endif
    #ifndef PI_11_OTYPE
        #define PI_11_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_11_PUPD
        #define PI_11_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_11_OSPEED
        #define PI_11_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_12_MODE
    #define PI_12_MODE      GPIO_MODE_ANALOG
    #define PI_12_PUPD      GPIO_PUPD_NONE
    #define PI_12_OSPEED    GPIO_OSPEED_LOW
    #define PI_12_OTYPE     GPIO_OTYPE_PP
    #define PI_12_AF        GPIO_AF0
    #define PI_12_DEFAULT_STATE 0
#else
    #if (PI_12_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_12_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_12_AF not defined'
        #endif
    #else
        #ifdef PI_12_AF
            #error 'PI_12_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_12_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_12_DEFAULT_STATE
            #warning 'PI_12_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_12_DEFAULT_STATE
        #define PI_12_DEFAULT_STATE 0
    #endif
    #ifndef PI_12_AF
        #define PI_12_AF GPIO_AF0
    #endif
    #ifndef PI_12_OTYPE
        #define PI_12_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_12_PUPD
        #define PI_12_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_12_OSPEED
        #define PI_12_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_13_MODE
    #define PI_13_MODE      GPIO_MODE_ANALOG
    #define PI_13_PUPD      GPIO_PUPD_NONE
    #define PI_13_OSPEED    GPIO_OSPEED_LOW
    #define PI_13_OTYPE     GPIO_OTYPE_PP
    #define PI_13_AF        GPIO_AF0
    #define PI_13_DEFAULT_STATE 0
#else
    #if (PI_13_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_13_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_13_AF not defined'
        #endif
    #else
        #ifdef PI_13_AF
            #error 'PI_13_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_13_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_13_DEFAULT_STATE
            #warning 'PI_13_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_13_DEFAULT_STATE
        #define PI_13_DEFAULT_STATE 0
    #endif
    #ifndef PI_13_AF
        #define PI_13_AF GPIO_AF0
    #endif
    #ifndef PI_13_OTYPE
        #define PI_13_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_13_PUPD
        #define PI_13_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_13_OSPEED
        #define PI_13_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_14_MODE
    #define PI_14_MODE      GPIO_MODE_ANALOG
    #define PI_14_PUPD      GPIO_PUPD_NONE
    #define PI_14_OSPEED    GPIO_OSPEED_LOW
    #define PI_14_OTYPE     GPIO_OTYPE_PP
    #define PI_14_AF        GPIO_AF0
    #define PI_14_DEFAULT_STATE 0
#else
    #if (PI_14_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_14_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_14_AF not defined'
        #endif
    #else
        #ifdef PI_14_AF
            #error 'PI_14_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_14_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_14_DEFAULT_STATE
            #warning 'PI_14_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_14_DEFAULT_STATE
        #define PI_14_DEFAULT_STATE 0
    #endif
    #ifndef PI_14_AF
        #define PI_14_AF GPIO_AF0
    #endif
    #ifndef PI_14_OTYPE
        #define PI_14_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_14_PUPD
        #define PI_14_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_14_OSPEED
        #define PI_14_OSPEED GPIO_OSPEED_LOW
    #endif
#endif

#ifndef PI_15_MODE
    #define PI_15_MODE      GPIO_MODE_ANALOG
    #define PI_15_PUPD      GPIO_PUPD_NONE
    #define PI_15_OSPEED    GPIO_OSPEED_LOW
    #define PI_15_OTYPE     GPIO_OTYPE_PP
    #define PI_15_AF        GPIO_AF0
    #define PI_15_DEFAULT_STATE 0
#else
    #if (PI_15_MODE	== GPIO_MODE_ALTERNATE)
        #ifndef PI_15_AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but PI_15_AF not defined'
        #endif
    #else
        #ifdef PI_15_AF
            #error 'PI_15_AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if (PI_15_MODE == GPIO_MODE_OUTPUT)
        #ifndef PI_15_DEFAULT_STATE
            #warning 'PI_15_MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef PI_15_DEFAULT_STATE
        #define PI_15_DEFAULT_STATE 0
    #endif
    #ifndef PI_15_AF
        #define PI_15_AF GPIO_AF0
    #endif
    #ifndef PI_15_OTYPE
        #define PI_15_OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef PI_15_PUPD
        #define PI_15_PUPD GPIO_PUPD_NONE
    #endif
    #ifndef PI_15_OSPEED
        #define PI_15_OSPEED GPIO_OSPEED_LOW
    #endif
#endif
/*END of insane macros, let's do some C...*/
void gpio_init(void)
{
    bit_set(RCC->AHB1ENR, \
                RCC_AHB1ENR_GPIOAEN |\
                RCC_AHB1ENR_GPIOBEN |\
                RCC_AHB1ENR_GPIOCEN |\
                RCC_AHB1ENR_GPIODEN |\
                RCC_AHB1ENR_GPIOEEN |\
                RCC_AHB1ENR_GPIOFEN |\
                RCC_AHB1ENR_GPIOGEN |\
                RCC_AHB1ENR_GPIOHEN |\
                RCC_AHB1ENR_GPIOIEN |\
                0);

/*GPIOA*/
    GPIOA->ODR = \
                    PA_0_DEFAULT_STATE  << 0 |\
                    PA_1_DEFAULT_STATE  << 1 |\
                    PA_2_DEFAULT_STATE  << 2 |\
                    PA_3_DEFAULT_STATE  << 3 |\
                    PA_4_DEFAULT_STATE  << 4 |\
                    PA_5_DEFAULT_STATE  << 5 |\
                    PA_6_DEFAULT_STATE  << 6 |\
                    PA_7_DEFAULT_STATE  << 7 |\
                    PA_8_DEFAULT_STATE  << 8 |\
                    PA_9_DEFAULT_STATE  << 9 |\
                    PA_10_DEFAULT_STATE  << 10 |\
                    PA_11_DEFAULT_STATE  << 11 |\
                    PA_12_DEFAULT_STATE  << 12 |\
                    PA_13_DEFAULT_STATE  << 13 |\
                    PA_14_DEFAULT_STATE  << 14 |\
                    PA_15_DEFAULT_STATE  << 15 |\
                    0;

    GPIOA->PUPDR = \
                    PA_0_PUPD  << GPIO_PUPDR_PUPDR0_Pos |\
                    PA_1_PUPD  << GPIO_PUPDR_PUPDR1_Pos |\
                    PA_2_PUPD  << GPIO_PUPDR_PUPDR2_Pos |\
                    PA_3_PUPD  << GPIO_PUPDR_PUPDR3_Pos |\
                    PA_4_PUPD  << GPIO_PUPDR_PUPDR4_Pos |\
                    PA_5_PUPD  << GPIO_PUPDR_PUPDR5_Pos |\
                    PA_6_PUPD  << GPIO_PUPDR_PUPDR6_Pos |\
                    PA_7_PUPD  << GPIO_PUPDR_PUPDR7_Pos |\
                    PA_8_PUPD  << GPIO_PUPDR_PUPDR8_Pos |\
                    PA_9_PUPD  << GPIO_PUPDR_PUPDR9_Pos |\
                    PA_10_PUPD  << GPIO_PUPDR_PUPDR10_Pos |\
                    PA_11_PUPD  << GPIO_PUPDR_PUPDR11_Pos |\
                    PA_12_PUPD  << GPIO_PUPDR_PUPDR12_Pos |\
                    PA_13_PUPD  << GPIO_PUPDR_PUPDR13_Pos |\
                    PA_14_PUPD  << GPIO_PUPDR_PUPDR14_Pos |\
                    PA_15_PUPD  << GPIO_PUPDR_PUPDR15_Pos |\
                    0;

    GPIOA->MODER = \
                    PA_0_MODE  << GPIO_MODER_MODER0_Pos |\
                    PA_1_MODE  << GPIO_MODER_MODER1_Pos |\
                    PA_2_MODE  << GPIO_MODER_MODER2_Pos |\
                    PA_3_MODE  << GPIO_MODER_MODER3_Pos |\
                    PA_4_MODE  << GPIO_MODER_MODER4_Pos |\
                    PA_5_MODE  << GPIO_MODER_MODER5_Pos |\
                    PA_6_MODE  << GPIO_MODER_MODER6_Pos |\
                    PA_7_MODE  << GPIO_MODER_MODER7_Pos |\
                    PA_8_MODE  << GPIO_MODER_MODER8_Pos |\
                    PA_9_MODE  << GPIO_MODER_MODER9_Pos |\
                    PA_10_MODE  << GPIO_MODER_MODER10_Pos |\
                    PA_11_MODE  << GPIO_MODER_MODER11_Pos |\
                    PA_12_MODE  << GPIO_MODER_MODER12_Pos |\
                    PA_13_MODE  << GPIO_MODER_MODER13_Pos |\
                    PA_14_MODE  << GPIO_MODER_MODER14_Pos |\
                    PA_15_MODE  << GPIO_MODER_MODER15_Pos |\
                    0;

    GPIOA->AFR[0] = \
                    PA_0_AF  << GPIO_AFRL_AFRL0_Pos |\
                    PA_1_AF  << GPIO_AFRL_AFRL1_Pos |\
                    PA_2_AF  << GPIO_AFRL_AFRL2_Pos |\
                    PA_3_AF  << GPIO_AFRL_AFRL3_Pos |\
                    PA_4_AF  << GPIO_AFRL_AFRL4_Pos |\
                    PA_5_AF  << GPIO_AFRL_AFRL5_Pos |\
                    PA_6_AF  << GPIO_AFRL_AFRL6_Pos |\
                    PA_7_AF  << GPIO_AFRL_AFRL7_Pos |\
                    0;

    GPIOA->AFR[1] = \
                    PA_8_AF  << GPIO_AFRH_AFRH0_Pos |\
                    PA_9_AF  << GPIO_AFRH_AFRH1_Pos |\
                    PA_10_AF  << GPIO_AFRH_AFRH2_Pos |\
                    PA_11_AF  << GPIO_AFRH_AFRH3_Pos |\
                    PA_12_AF  << GPIO_AFRH_AFRH4_Pos |\
                    PA_13_AF  << GPIO_AFRH_AFRH5_Pos |\
                    PA_14_AF  << GPIO_AFRH_AFRH6_Pos |\
                    PA_15_AF  << GPIO_AFRH_AFRH7_Pos |\
                    0;

    GPIOA->OTYPER = \
                    PA_0_OTYPE  << 0 |\
                    PA_1_OTYPE  << 1 |\
                    PA_2_OTYPE  << 2 |\
                    PA_3_OTYPE  << 3 |\
                    PA_4_OTYPE  << 4 |\
                    PA_5_OTYPE  << 5 |\
                    PA_6_OTYPE  << 6 |\
                    PA_7_OTYPE  << 7 |\
                    PA_8_OTYPE  << 8 |\
                    PA_9_OTYPE  << 9 |\
                    PA_10_OTYPE  << 10 |\
                    PA_11_OTYPE  << 11 |\
                    PA_12_OTYPE  << 12 |\
                    PA_13_OTYPE  << 13 |\
                    PA_14_OTYPE  << 14 |\
                    PA_15_OTYPE  << 15 |\
                    0;

    GPIOA->OSPEEDR = \
                    PA_0_OSPEED  << GPIO_OSPEEDER_OSPEEDR0_Pos |\
                    PA_1_OSPEED  << GPIO_OSPEEDER_OSPEEDR1_Pos |\
                    PA_2_OSPEED  << GPIO_OSPEEDER_OSPEEDR2_Pos |\
                    PA_3_OSPEED  << GPIO_OSPEEDER_OSPEEDR3_Pos |\
                    PA_4_OSPEED  << GPIO_OSPEEDER_OSPEEDR4_Pos |\
                    PA_5_OSPEED  << GPIO_OSPEEDER_OSPEEDR5_Pos |\
                    PA_6_OSPEED  << GPIO_OSPEEDER_OSPEEDR6_Pos |\
                    PA_7_OSPEED  << GPIO_OSPEEDER_OSPEEDR7_Pos |\
                    PA_8_OSPEED  << GPIO_OSPEEDER_OSPEEDR8_Pos |\
                    PA_9_OSPEED  << GPIO_OSPEEDER_OSPEEDR9_Pos |\
                    PA_10_OSPEED  << GPIO_OSPEEDER_OSPEEDR10_Pos |\
                    PA_11_OSPEED  << GPIO_OSPEEDER_OSPEEDR11_Pos |\
                    PA_12_OSPEED  << GPIO_OSPEEDER_OSPEEDR12_Pos |\
                    PA_13_OSPEED  << GPIO_OSPEEDER_OSPEEDR13_Pos |\
                    PA_14_OSPEED  << GPIO_OSPEEDER_OSPEEDR14_Pos |\
                    PA_15_OSPEED  << GPIO_OSPEEDER_OSPEEDR15_Pos |\
                    0;

/*GPIOB*/
    GPIOB->ODR = \
                    PB_0_DEFAULT_STATE  << 0 |\
                    PB_1_DEFAULT_STATE  << 1 |\
                    PB_2_DEFAULT_STATE  << 2 |\
                    PB_3_DEFAULT_STATE  << 3 |\
                    PB_4_DEFAULT_STATE  << 4 |\
                    PB_5_DEFAULT_STATE  << 5 |\
                    PB_6_DEFAULT_STATE  << 6 |\
                    PB_7_DEFAULT_STATE  << 7 |\
                    PB_8_DEFAULT_STATE  << 8 |\
                    PB_9_DEFAULT_STATE  << 9 |\
                    PB_10_DEFAULT_STATE  << 10 |\
                    PB_11_DEFAULT_STATE  << 11 |\
                    PB_12_DEFAULT_STATE  << 12 |\
                    PB_13_DEFAULT_STATE  << 13 |\
                    PB_14_DEFAULT_STATE  << 14 |\
                    PB_15_DEFAULT_STATE  << 15 |\
                    0;

    GPIOB->PUPDR = \
                    PB_0_PUPD  << GPIO_PUPDR_PUPDR0_Pos |\
                    PB_1_PUPD  << GPIO_PUPDR_PUPDR1_Pos |\
                    PB_2_PUPD  << GPIO_PUPDR_PUPDR2_Pos |\
                    PB_3_PUPD  << GPIO_PUPDR_PUPDR3_Pos |\
                    PB_4_PUPD  << GPIO_PUPDR_PUPDR4_Pos |\
                    PB_5_PUPD  << GPIO_PUPDR_PUPDR5_Pos |\
                    PB_6_PUPD  << GPIO_PUPDR_PUPDR6_Pos |\
                    PB_7_PUPD  << GPIO_PUPDR_PUPDR7_Pos |\
                    PB_8_PUPD  << GPIO_PUPDR_PUPDR8_Pos |\
                    PB_9_PUPD  << GPIO_PUPDR_PUPDR9_Pos |\
                    PB_10_PUPD  << GPIO_PUPDR_PUPDR10_Pos |\
                    PB_11_PUPD  << GPIO_PUPDR_PUPDR11_Pos |\
                    PB_12_PUPD  << GPIO_PUPDR_PUPDR12_Pos |\
                    PB_13_PUPD  << GPIO_PUPDR_PUPDR13_Pos |\
                    PB_14_PUPD  << GPIO_PUPDR_PUPDR14_Pos |\
                    PB_15_PUPD  << GPIO_PUPDR_PUPDR15_Pos |\
                    0;

    GPIOB->MODER = \
                    PB_0_MODE  << GPIO_MODER_MODER0_Pos |\
                    PB_1_MODE  << GPIO_MODER_MODER1_Pos |\
                    PB_2_MODE  << GPIO_MODER_MODER2_Pos |\
                    PB_3_MODE  << GPIO_MODER_MODER3_Pos |\
                    PB_4_MODE  << GPIO_MODER_MODER4_Pos |\
                    PB_5_MODE  << GPIO_MODER_MODER5_Pos |\
                    PB_6_MODE  << GPIO_MODER_MODER6_Pos |\
                    PB_7_MODE  << GPIO_MODER_MODER7_Pos |\
                    PB_8_MODE  << GPIO_MODER_MODER8_Pos |\
                    PB_9_MODE  << GPIO_MODER_MODER9_Pos |\
                    PB_10_MODE  << GPIO_MODER_MODER10_Pos |\
                    PB_11_MODE  << GPIO_MODER_MODER11_Pos |\
                    PB_12_MODE  << GPIO_MODER_MODER12_Pos |\
                    PB_13_MODE  << GPIO_MODER_MODER13_Pos |\
                    PB_14_MODE  << GPIO_MODER_MODER14_Pos |\
                    PB_15_MODE  << GPIO_MODER_MODER15_Pos |\
                    0;

    GPIOB->AFR[0] = \
                    PB_0_AF  << GPIO_AFRL_AFRL0_Pos |\
                    PB_1_AF  << GPIO_AFRL_AFRL1_Pos |\
                    PB_2_AF  << GPIO_AFRL_AFRL2_Pos |\
                    PB_3_AF  << GPIO_AFRL_AFRL3_Pos |\
                    PB_4_AF  << GPIO_AFRL_AFRL4_Pos |\
                    PB_5_AF  << GPIO_AFRL_AFRL5_Pos |\
                    PB_6_AF  << GPIO_AFRL_AFRL6_Pos |\
                    PB_7_AF  << GPIO_AFRL_AFRL7_Pos |\
                    0;

    GPIOB->AFR[1] = \
                    PB_8_AF  << GPIO_AFRH_AFRH0_Pos |\
                    PB_9_AF  << GPIO_AFRH_AFRH1_Pos |\
                    PB_10_AF  << GPIO_AFRH_AFRH2_Pos |\
                    PB_11_AF  << GPIO_AFRH_AFRH3_Pos |\
                    PB_12_AF  << GPIO_AFRH_AFRH4_Pos |\
                    PB_13_AF  << GPIO_AFRH_AFRH5_Pos |\
                    PB_14_AF  << GPIO_AFRH_AFRH6_Pos |\
                    PB_15_AF  << GPIO_AFRH_AFRH7_Pos |\
                    0;

    GPIOB->OTYPER = \
                    PB_0_OTYPE  << 0 |\
                    PB_1_OTYPE  << 1 |\
                    PB_2_OTYPE  << 2 |\
                    PB_3_OTYPE  << 3 |\
                    PB_4_OTYPE  << 4 |\
                    PB_5_OTYPE  << 5 |\
                    PB_6_OTYPE  << 6 |\
                    PB_7_OTYPE  << 7 |\
                    PB_8_OTYPE  << 8 |\
                    PB_9_OTYPE  << 9 |\
                    PB_10_OTYPE  << 10 |\
                    PB_11_OTYPE  << 11 |\
                    PB_12_OTYPE  << 12 |\
                    PB_13_OTYPE  << 13 |\
                    PB_14_OTYPE  << 14 |\
                    PB_15_OTYPE  << 15 |\
                    0;

    GPIOB->OSPEEDR = \
                    PB_0_OSPEED  << GPIO_OSPEEDER_OSPEEDR0_Pos |\
                    PB_1_OSPEED  << GPIO_OSPEEDER_OSPEEDR1_Pos |\
                    PB_2_OSPEED  << GPIO_OSPEEDER_OSPEEDR2_Pos |\
                    PB_3_OSPEED  << GPIO_OSPEEDER_OSPEEDR3_Pos |\
                    PB_4_OSPEED  << GPIO_OSPEEDER_OSPEEDR4_Pos |\
                    PB_5_OSPEED  << GPIO_OSPEEDER_OSPEEDR5_Pos |\
                    PB_6_OSPEED  << GPIO_OSPEEDER_OSPEEDR6_Pos |\
                    PB_7_OSPEED  << GPIO_OSPEEDER_OSPEEDR7_Pos |\
                    PB_8_OSPEED  << GPIO_OSPEEDER_OSPEEDR8_Pos |\
                    PB_9_OSPEED  << GPIO_OSPEEDER_OSPEEDR9_Pos |\
                    PB_10_OSPEED  << GPIO_OSPEEDER_OSPEEDR10_Pos |\
                    PB_11_OSPEED  << GPIO_OSPEEDER_OSPEEDR11_Pos |\
                    PB_12_OSPEED  << GPIO_OSPEEDER_OSPEEDR12_Pos |\
                    PB_13_OSPEED  << GPIO_OSPEEDER_OSPEEDR13_Pos |\
                    PB_14_OSPEED  << GPIO_OSPEEDER_OSPEEDR14_Pos |\
                    PB_15_OSPEED  << GPIO_OSPEEDER_OSPEEDR15_Pos |\
                    0;

/*GPIOC*/
    GPIOC->ODR = \
                    PC_0_DEFAULT_STATE  << 0 |\
                    PC_1_DEFAULT_STATE  << 1 |\
                    PC_2_DEFAULT_STATE  << 2 |\
                    PC_3_DEFAULT_STATE  << 3 |\
                    PC_4_DEFAULT_STATE  << 4 |\
                    PC_5_DEFAULT_STATE  << 5 |\
                    PC_6_DEFAULT_STATE  << 6 |\
                    PC_7_DEFAULT_STATE  << 7 |\
                    PC_8_DEFAULT_STATE  << 8 |\
                    PC_9_DEFAULT_STATE  << 9 |\
                    PC_10_DEFAULT_STATE  << 10 |\
                    PC_11_DEFAULT_STATE  << 11 |\
                    PC_12_DEFAULT_STATE  << 12 |\
                    PC_13_DEFAULT_STATE  << 13 |\
                    PC_14_DEFAULT_STATE  << 14 |\
                    PC_15_DEFAULT_STATE  << 15 |\
                    0;

    GPIOC->PUPDR = \
                    PC_0_PUPD  << GPIO_PUPDR_PUPDR0_Pos |\
                    PC_1_PUPD  << GPIO_PUPDR_PUPDR1_Pos |\
                    PC_2_PUPD  << GPIO_PUPDR_PUPDR2_Pos |\
                    PC_3_PUPD  << GPIO_PUPDR_PUPDR3_Pos |\
                    PC_4_PUPD  << GPIO_PUPDR_PUPDR4_Pos |\
                    PC_5_PUPD  << GPIO_PUPDR_PUPDR5_Pos |\
                    PC_6_PUPD  << GPIO_PUPDR_PUPDR6_Pos |\
                    PC_7_PUPD  << GPIO_PUPDR_PUPDR7_Pos |\
                    PC_8_PUPD  << GPIO_PUPDR_PUPDR8_Pos |\
                    PC_9_PUPD  << GPIO_PUPDR_PUPDR9_Pos |\
                    PC_10_PUPD  << GPIO_PUPDR_PUPDR10_Pos |\
                    PC_11_PUPD  << GPIO_PUPDR_PUPDR11_Pos |\
                    PC_12_PUPD  << GPIO_PUPDR_PUPDR12_Pos |\
                    PC_13_PUPD  << GPIO_PUPDR_PUPDR13_Pos |\
                    PC_14_PUPD  << GPIO_PUPDR_PUPDR14_Pos |\
                    PC_15_PUPD  << GPIO_PUPDR_PUPDR15_Pos |\
                    0;

    GPIOC->MODER = \
                    PC_0_MODE  << GPIO_MODER_MODER0_Pos |\
                    PC_1_MODE  << GPIO_MODER_MODER1_Pos |\
                    PC_2_MODE  << GPIO_MODER_MODER2_Pos |\
                    PC_3_MODE  << GPIO_MODER_MODER3_Pos |\
                    PC_4_MODE  << GPIO_MODER_MODER4_Pos |\
                    PC_5_MODE  << GPIO_MODER_MODER5_Pos |\
                    PC_6_MODE  << GPIO_MODER_MODER6_Pos |\
                    PC_7_MODE  << GPIO_MODER_MODER7_Pos |\
                    PC_8_MODE  << GPIO_MODER_MODER8_Pos |\
                    PC_9_MODE  << GPIO_MODER_MODER9_Pos |\
                    PC_10_MODE  << GPIO_MODER_MODER10_Pos |\
                    PC_11_MODE  << GPIO_MODER_MODER11_Pos |\
                    PC_12_MODE  << GPIO_MODER_MODER12_Pos |\
                    PC_13_MODE  << GPIO_MODER_MODER13_Pos |\
                    PC_14_MODE  << GPIO_MODER_MODER14_Pos |\
                    PC_15_MODE  << GPIO_MODER_MODER15_Pos |\
                    0;

    GPIOC->AFR[0] = \
                    PC_0_AF  << GPIO_AFRL_AFRL0_Pos |\
                    PC_1_AF  << GPIO_AFRL_AFRL1_Pos |\
                    PC_2_AF  << GPIO_AFRL_AFRL2_Pos |\
                    PC_3_AF  << GPIO_AFRL_AFRL3_Pos |\
                    PC_4_AF  << GPIO_AFRL_AFRL4_Pos |\
                    PC_5_AF  << GPIO_AFRL_AFRL5_Pos |\
                    PC_6_AF  << GPIO_AFRL_AFRL6_Pos |\
                    PC_7_AF  << GPIO_AFRL_AFRL7_Pos |\
                    0;

    GPIOC->AFR[1] = \
                    PC_8_AF  << GPIO_AFRH_AFRH0_Pos |\
                    PC_9_AF  << GPIO_AFRH_AFRH1_Pos |\
                    PC_10_AF  << GPIO_AFRH_AFRH2_Pos |\
                    PC_11_AF  << GPIO_AFRH_AFRH3_Pos |\
                    PC_12_AF  << GPIO_AFRH_AFRH4_Pos |\
                    PC_13_AF  << GPIO_AFRH_AFRH5_Pos |\
                    PC_14_AF  << GPIO_AFRH_AFRH6_Pos |\
                    PC_15_AF  << GPIO_AFRH_AFRH7_Pos |\
                    0;

    GPIOC->OTYPER = \
                    PC_0_OTYPE  << 0 |\
                    PC_1_OTYPE  << 1 |\
                    PC_2_OTYPE  << 2 |\
                    PC_3_OTYPE  << 3 |\
                    PC_4_OTYPE  << 4 |\
                    PC_5_OTYPE  << 5 |\
                    PC_6_OTYPE  << 6 |\
                    PC_7_OTYPE  << 7 |\
                    PC_8_OTYPE  << 8 |\
                    PC_9_OTYPE  << 9 |\
                    PC_10_OTYPE  << 10 |\
                    PC_11_OTYPE  << 11 |\
                    PC_12_OTYPE  << 12 |\
                    PC_13_OTYPE  << 13 |\
                    PC_14_OTYPE  << 14 |\
                    PC_15_OTYPE  << 15 |\
                    0;

    GPIOC->OSPEEDR = \
                    PC_0_OSPEED  << GPIO_OSPEEDER_OSPEEDR0_Pos |\
                    PC_1_OSPEED  << GPIO_OSPEEDER_OSPEEDR1_Pos |\
                    PC_2_OSPEED  << GPIO_OSPEEDER_OSPEEDR2_Pos |\
                    PC_3_OSPEED  << GPIO_OSPEEDER_OSPEEDR3_Pos |\
                    PC_4_OSPEED  << GPIO_OSPEEDER_OSPEEDR4_Pos |\
                    PC_5_OSPEED  << GPIO_OSPEEDER_OSPEEDR5_Pos |\
                    PC_6_OSPEED  << GPIO_OSPEEDER_OSPEEDR6_Pos |\
                    PC_7_OSPEED  << GPIO_OSPEEDER_OSPEEDR7_Pos |\
                    PC_8_OSPEED  << GPIO_OSPEEDER_OSPEEDR8_Pos |\
                    PC_9_OSPEED  << GPIO_OSPEEDER_OSPEEDR9_Pos |\
                    PC_10_OSPEED  << GPIO_OSPEEDER_OSPEEDR10_Pos |\
                    PC_11_OSPEED  << GPIO_OSPEEDER_OSPEEDR11_Pos |\
                    PC_12_OSPEED  << GPIO_OSPEEDER_OSPEEDR12_Pos |\
                    PC_13_OSPEED  << GPIO_OSPEEDER_OSPEEDR13_Pos |\
                    PC_14_OSPEED  << GPIO_OSPEEDER_OSPEEDR14_Pos |\
                    PC_15_OSPEED  << GPIO_OSPEEDER_OSPEEDR15_Pos |\
                    0;

/*GPIOD*/
    GPIOD->ODR = \
                    PD_0_DEFAULT_STATE  << 0 |\
                    PD_1_DEFAULT_STATE  << 1 |\
                    PD_2_DEFAULT_STATE  << 2 |\
                    PD_3_DEFAULT_STATE  << 3 |\
                    PD_4_DEFAULT_STATE  << 4 |\
                    PD_5_DEFAULT_STATE  << 5 |\
                    PD_6_DEFAULT_STATE  << 6 |\
                    PD_7_DEFAULT_STATE  << 7 |\
                    PD_8_DEFAULT_STATE  << 8 |\
                    PD_9_DEFAULT_STATE  << 9 |\
                    PD_10_DEFAULT_STATE  << 10 |\
                    PD_11_DEFAULT_STATE  << 11 |\
                    PD_12_DEFAULT_STATE  << 12 |\
                    PD_13_DEFAULT_STATE  << 13 |\
                    PD_14_DEFAULT_STATE  << 14 |\
                    PD_15_DEFAULT_STATE  << 15 |\
                    0;

    GPIOD->PUPDR = \
                    PD_0_PUPD  << GPIO_PUPDR_PUPDR0_Pos |\
                    PD_1_PUPD  << GPIO_PUPDR_PUPDR1_Pos |\
                    PD_2_PUPD  << GPIO_PUPDR_PUPDR2_Pos |\
                    PD_3_PUPD  << GPIO_PUPDR_PUPDR3_Pos |\
                    PD_4_PUPD  << GPIO_PUPDR_PUPDR4_Pos |\
                    PD_5_PUPD  << GPIO_PUPDR_PUPDR5_Pos |\
                    PD_6_PUPD  << GPIO_PUPDR_PUPDR6_Pos |\
                    PD_7_PUPD  << GPIO_PUPDR_PUPDR7_Pos |\
                    PD_8_PUPD  << GPIO_PUPDR_PUPDR8_Pos |\
                    PD_9_PUPD  << GPIO_PUPDR_PUPDR9_Pos |\
                    PD_10_PUPD  << GPIO_PUPDR_PUPDR10_Pos |\
                    PD_11_PUPD  << GPIO_PUPDR_PUPDR11_Pos |\
                    PD_12_PUPD  << GPIO_PUPDR_PUPDR12_Pos |\
                    PD_13_PUPD  << GPIO_PUPDR_PUPDR13_Pos |\
                    PD_14_PUPD  << GPIO_PUPDR_PUPDR14_Pos |\
                    PD_15_PUPD  << GPIO_PUPDR_PUPDR15_Pos |\
                    0;

    GPIOD->MODER = \
                    PD_0_MODE  << GPIO_MODER_MODER0_Pos |\
                    PD_1_MODE  << GPIO_MODER_MODER1_Pos |\
                    PD_2_MODE  << GPIO_MODER_MODER2_Pos |\
                    PD_3_MODE  << GPIO_MODER_MODER3_Pos |\
                    PD_4_MODE  << GPIO_MODER_MODER4_Pos |\
                    PD_5_MODE  << GPIO_MODER_MODER5_Pos |\
                    PD_6_MODE  << GPIO_MODER_MODER6_Pos |\
                    PD_7_MODE  << GPIO_MODER_MODER7_Pos |\
                    PD_8_MODE  << GPIO_MODER_MODER8_Pos |\
                    PD_9_MODE  << GPIO_MODER_MODER9_Pos |\
                    PD_10_MODE  << GPIO_MODER_MODER10_Pos |\
                    PD_11_MODE  << GPIO_MODER_MODER11_Pos |\
                    PD_12_MODE  << GPIO_MODER_MODER12_Pos |\
                    PD_13_MODE  << GPIO_MODER_MODER13_Pos |\
                    PD_14_MODE  << GPIO_MODER_MODER14_Pos |\
                    PD_15_MODE  << GPIO_MODER_MODER15_Pos |\
                    0;

    GPIOD->AFR[0] = \
                    PD_0_AF  << GPIO_AFRL_AFRL0_Pos |\
                    PD_1_AF  << GPIO_AFRL_AFRL1_Pos |\
                    PD_2_AF  << GPIO_AFRL_AFRL2_Pos |\
                    PD_3_AF  << GPIO_AFRL_AFRL3_Pos |\
                    PD_4_AF  << GPIO_AFRL_AFRL4_Pos |\
                    PD_5_AF  << GPIO_AFRL_AFRL5_Pos |\
                    PD_6_AF  << GPIO_AFRL_AFRL6_Pos |\
                    PD_7_AF  << GPIO_AFRL_AFRL7_Pos |\
                    0;

    GPIOD->AFR[1] = \
                    PD_8_AF  << GPIO_AFRH_AFRH0_Pos |\
                    PD_9_AF  << GPIO_AFRH_AFRH1_Pos |\
                    PD_10_AF  << GPIO_AFRH_AFRH2_Pos |\
                    PD_11_AF  << GPIO_AFRH_AFRH3_Pos |\
                    PD_12_AF  << GPIO_AFRH_AFRH4_Pos |\
                    PD_13_AF  << GPIO_AFRH_AFRH5_Pos |\
                    PD_14_AF  << GPIO_AFRH_AFRH6_Pos |\
                    PD_15_AF  << GPIO_AFRH_AFRH7_Pos |\
                    0;

    GPIOD->OTYPER = \
                    PD_0_OTYPE  << 0 |\
                    PD_1_OTYPE  << 1 |\
                    PD_2_OTYPE  << 2 |\
                    PD_3_OTYPE  << 3 |\
                    PD_4_OTYPE  << 4 |\
                    PD_5_OTYPE  << 5 |\
                    PD_6_OTYPE  << 6 |\
                    PD_7_OTYPE  << 7 |\
                    PD_8_OTYPE  << 8 |\
                    PD_9_OTYPE  << 9 |\
                    PD_10_OTYPE  << 10 |\
                    PD_11_OTYPE  << 11 |\
                    PD_12_OTYPE  << 12 |\
                    PD_13_OTYPE  << 13 |\
                    PD_14_OTYPE  << 14 |\
                    PD_15_OTYPE  << 15 |\
                    0;

    GPIOD->OSPEEDR = \
                    PD_0_OSPEED  << GPIO_OSPEEDER_OSPEEDR0_Pos |\
                    PD_1_OSPEED  << GPIO_OSPEEDER_OSPEEDR1_Pos |\
                    PD_2_OSPEED  << GPIO_OSPEEDER_OSPEEDR2_Pos |\
                    PD_3_OSPEED  << GPIO_OSPEEDER_OSPEEDR3_Pos |\
                    PD_4_OSPEED  << GPIO_OSPEEDER_OSPEEDR4_Pos |\
                    PD_5_OSPEED  << GPIO_OSPEEDER_OSPEEDR5_Pos |\
                    PD_6_OSPEED  << GPIO_OSPEEDER_OSPEEDR6_Pos |\
                    PD_7_OSPEED  << GPIO_OSPEEDER_OSPEEDR7_Pos |\
                    PD_8_OSPEED  << GPIO_OSPEEDER_OSPEEDR8_Pos |\
                    PD_9_OSPEED  << GPIO_OSPEEDER_OSPEEDR9_Pos |\
                    PD_10_OSPEED  << GPIO_OSPEEDER_OSPEEDR10_Pos |\
                    PD_11_OSPEED  << GPIO_OSPEEDER_OSPEEDR11_Pos |\
                    PD_12_OSPEED  << GPIO_OSPEEDER_OSPEEDR12_Pos |\
                    PD_13_OSPEED  << GPIO_OSPEEDER_OSPEEDR13_Pos |\
                    PD_14_OSPEED  << GPIO_OSPEEDER_OSPEEDR14_Pos |\
                    PD_15_OSPEED  << GPIO_OSPEEDER_OSPEEDR15_Pos |\
                    0;

/*GPIOE*/
    GPIOE->ODR = \
                    PE_0_DEFAULT_STATE  << 0 |\
                    PE_1_DEFAULT_STATE  << 1 |\
                    PE_2_DEFAULT_STATE  << 2 |\
                    PE_3_DEFAULT_STATE  << 3 |\
                    PE_4_DEFAULT_STATE  << 4 |\
                    PE_5_DEFAULT_STATE  << 5 |\
                    PE_6_DEFAULT_STATE  << 6 |\
                    PE_7_DEFAULT_STATE  << 7 |\
                    PE_8_DEFAULT_STATE  << 8 |\
                    PE_9_DEFAULT_STATE  << 9 |\
                    PE_10_DEFAULT_STATE  << 10 |\
                    PE_11_DEFAULT_STATE  << 11 |\
                    PE_12_DEFAULT_STATE  << 12 |\
                    PE_13_DEFAULT_STATE  << 13 |\
                    PE_14_DEFAULT_STATE  << 14 |\
                    PE_15_DEFAULT_STATE  << 15 |\
                    0;

    GPIOE->PUPDR = \
                    PE_0_PUPD  << GPIO_PUPDR_PUPDR0_Pos |\
                    PE_1_PUPD  << GPIO_PUPDR_PUPDR1_Pos |\
                    PE_2_PUPD  << GPIO_PUPDR_PUPDR2_Pos |\
                    PE_3_PUPD  << GPIO_PUPDR_PUPDR3_Pos |\
                    PE_4_PUPD  << GPIO_PUPDR_PUPDR4_Pos |\
                    PE_5_PUPD  << GPIO_PUPDR_PUPDR5_Pos |\
                    PE_6_PUPD  << GPIO_PUPDR_PUPDR6_Pos |\
                    PE_7_PUPD  << GPIO_PUPDR_PUPDR7_Pos |\
                    PE_8_PUPD  << GPIO_PUPDR_PUPDR8_Pos |\
                    PE_9_PUPD  << GPIO_PUPDR_PUPDR9_Pos |\
                    PE_10_PUPD  << GPIO_PUPDR_PUPDR10_Pos |\
                    PE_11_PUPD  << GPIO_PUPDR_PUPDR11_Pos |\
                    PE_12_PUPD  << GPIO_PUPDR_PUPDR12_Pos |\
                    PE_13_PUPD  << GPIO_PUPDR_PUPDR13_Pos |\
                    PE_14_PUPD  << GPIO_PUPDR_PUPDR14_Pos |\
                    PE_15_PUPD  << GPIO_PUPDR_PUPDR15_Pos |\
                    0;

    GPIOE->MODER = \
                    PE_0_MODE  << GPIO_MODER_MODER0_Pos |\
                    PE_1_MODE  << GPIO_MODER_MODER1_Pos |\
                    PE_2_MODE  << GPIO_MODER_MODER2_Pos |\
                    PE_3_MODE  << GPIO_MODER_MODER3_Pos |\
                    PE_4_MODE  << GPIO_MODER_MODER4_Pos |\
                    PE_5_MODE  << GPIO_MODER_MODER5_Pos |\
                    PE_6_MODE  << GPIO_MODER_MODER6_Pos |\
                    PE_7_MODE  << GPIO_MODER_MODER7_Pos |\
                    PE_8_MODE  << GPIO_MODER_MODER8_Pos |\
                    PE_9_MODE  << GPIO_MODER_MODER9_Pos |\
                    PE_10_MODE  << GPIO_MODER_MODER10_Pos |\
                    PE_11_MODE  << GPIO_MODER_MODER11_Pos |\
                    PE_12_MODE  << GPIO_MODER_MODER12_Pos |\
                    PE_13_MODE  << GPIO_MODER_MODER13_Pos |\
                    PE_14_MODE  << GPIO_MODER_MODER14_Pos |\
                    PE_15_MODE  << GPIO_MODER_MODER15_Pos |\
                    0;

    GPIOE->AFR[0] = \
                    PE_0_AF  << GPIO_AFRL_AFRL0_Pos |\
                    PE_1_AF  << GPIO_AFRL_AFRL1_Pos |\
                    PE_2_AF  << GPIO_AFRL_AFRL2_Pos |\
                    PE_3_AF  << GPIO_AFRL_AFRL3_Pos |\
                    PE_4_AF  << GPIO_AFRL_AFRL4_Pos |\
                    PE_5_AF  << GPIO_AFRL_AFRL5_Pos |\
                    PE_6_AF  << GPIO_AFRL_AFRL6_Pos |\
                    PE_7_AF  << GPIO_AFRL_AFRL7_Pos |\
                    0;

    GPIOE->AFR[1] = \
                    PE_8_AF  << GPIO_AFRH_AFRH0_Pos |\
                    PE_9_AF  << GPIO_AFRH_AFRH1_Pos |\
                    PE_10_AF  << GPIO_AFRH_AFRH2_Pos |\
                    PE_11_AF  << GPIO_AFRH_AFRH3_Pos |\
                    PE_12_AF  << GPIO_AFRH_AFRH4_Pos |\
                    PE_13_AF  << GPIO_AFRH_AFRH5_Pos |\
                    PE_14_AF  << GPIO_AFRH_AFRH6_Pos |\
                    PE_15_AF  << GPIO_AFRH_AFRH7_Pos |\
                    0;

    GPIOE->OTYPER = \
                    PE_0_OTYPE  << 0 |\
                    PE_1_OTYPE  << 1 |\
                    PE_2_OTYPE  << 2 |\
                    PE_3_OTYPE  << 3 |\
                    PE_4_OTYPE  << 4 |\
                    PE_5_OTYPE  << 5 |\
                    PE_6_OTYPE  << 6 |\
                    PE_7_OTYPE  << 7 |\
                    PE_8_OTYPE  << 8 |\
                    PE_9_OTYPE  << 9 |\
                    PE_10_OTYPE  << 10 |\
                    PE_11_OTYPE  << 11 |\
                    PE_12_OTYPE  << 12 |\
                    PE_13_OTYPE  << 13 |\
                    PE_14_OTYPE  << 14 |\
                    PE_15_OTYPE  << 15 |\
                    0;

    GPIOE->OSPEEDR = \
                    PE_0_OSPEED  << GPIO_OSPEEDER_OSPEEDR0_Pos |\
                    PE_1_OSPEED  << GPIO_OSPEEDER_OSPEEDR1_Pos |\
                    PE_2_OSPEED  << GPIO_OSPEEDER_OSPEEDR2_Pos |\
                    PE_3_OSPEED  << GPIO_OSPEEDER_OSPEEDR3_Pos |\
                    PE_4_OSPEED  << GPIO_OSPEEDER_OSPEEDR4_Pos |\
                    PE_5_OSPEED  << GPIO_OSPEEDER_OSPEEDR5_Pos |\
                    PE_6_OSPEED  << GPIO_OSPEEDER_OSPEEDR6_Pos |\
                    PE_7_OSPEED  << GPIO_OSPEEDER_OSPEEDR7_Pos |\
                    PE_8_OSPEED  << GPIO_OSPEEDER_OSPEEDR8_Pos |\
                    PE_9_OSPEED  << GPIO_OSPEEDER_OSPEEDR9_Pos |\
                    PE_10_OSPEED  << GPIO_OSPEEDER_OSPEEDR10_Pos |\
                    PE_11_OSPEED  << GPIO_OSPEEDER_OSPEEDR11_Pos |\
                    PE_12_OSPEED  << GPIO_OSPEEDER_OSPEEDR12_Pos |\
                    PE_13_OSPEED  << GPIO_OSPEEDER_OSPEEDR13_Pos |\
                    PE_14_OSPEED  << GPIO_OSPEEDER_OSPEEDR14_Pos |\
                    PE_15_OSPEED  << GPIO_OSPEEDER_OSPEEDR15_Pos |\
                    0;

/*GPIOF*/
    GPIOF->ODR = \
                    PF_0_DEFAULT_STATE  << 0 |\
                    PF_1_DEFAULT_STATE  << 1 |\
                    PF_2_DEFAULT_STATE  << 2 |\
                    PF_3_DEFAULT_STATE  << 3 |\
                    PF_4_DEFAULT_STATE  << 4 |\
                    PF_5_DEFAULT_STATE  << 5 |\
                    PF_6_DEFAULT_STATE  << 6 |\
                    PF_7_DEFAULT_STATE  << 7 |\
                    PF_8_DEFAULT_STATE  << 8 |\
                    PF_9_DEFAULT_STATE  << 9 |\
                    PF_10_DEFAULT_STATE  << 10 |\
                    PF_11_DEFAULT_STATE  << 11 |\
                    PF_12_DEFAULT_STATE  << 12 |\
                    PF_13_DEFAULT_STATE  << 13 |\
                    PF_14_DEFAULT_STATE  << 14 |\
                    PF_15_DEFAULT_STATE  << 15 |\
                    0;

    GPIOF->PUPDR = \
                    PF_0_PUPD  << GPIO_PUPDR_PUPDR0_Pos |\
                    PF_1_PUPD  << GPIO_PUPDR_PUPDR1_Pos |\
                    PF_2_PUPD  << GPIO_PUPDR_PUPDR2_Pos |\
                    PF_3_PUPD  << GPIO_PUPDR_PUPDR3_Pos |\
                    PF_4_PUPD  << GPIO_PUPDR_PUPDR4_Pos |\
                    PF_5_PUPD  << GPIO_PUPDR_PUPDR5_Pos |\
                    PF_6_PUPD  << GPIO_PUPDR_PUPDR6_Pos |\
                    PF_7_PUPD  << GPIO_PUPDR_PUPDR7_Pos |\
                    PF_8_PUPD  << GPIO_PUPDR_PUPDR8_Pos |\
                    PF_9_PUPD  << GPIO_PUPDR_PUPDR9_Pos |\
                    PF_10_PUPD  << GPIO_PUPDR_PUPDR10_Pos |\
                    PF_11_PUPD  << GPIO_PUPDR_PUPDR11_Pos |\
                    PF_12_PUPD  << GPIO_PUPDR_PUPDR12_Pos |\
                    PF_13_PUPD  << GPIO_PUPDR_PUPDR13_Pos |\
                    PF_14_PUPD  << GPIO_PUPDR_PUPDR14_Pos |\
                    PF_15_PUPD  << GPIO_PUPDR_PUPDR15_Pos |\
                    0;

    GPIOF->MODER = \
                    PF_0_MODE  << GPIO_MODER_MODER0_Pos |\
                    PF_1_MODE  << GPIO_MODER_MODER1_Pos |\
                    PF_2_MODE  << GPIO_MODER_MODER2_Pos |\
                    PF_3_MODE  << GPIO_MODER_MODER3_Pos |\
                    PF_4_MODE  << GPIO_MODER_MODER4_Pos |\
                    PF_5_MODE  << GPIO_MODER_MODER5_Pos |\
                    PF_6_MODE  << GPIO_MODER_MODER6_Pos |\
                    PF_7_MODE  << GPIO_MODER_MODER7_Pos |\
                    PF_8_MODE  << GPIO_MODER_MODER8_Pos |\
                    PF_9_MODE  << GPIO_MODER_MODER9_Pos |\
                    PF_10_MODE  << GPIO_MODER_MODER10_Pos |\
                    PF_11_MODE  << GPIO_MODER_MODER11_Pos |\
                    PF_12_MODE  << GPIO_MODER_MODER12_Pos |\
                    PF_13_MODE  << GPIO_MODER_MODER13_Pos |\
                    PF_14_MODE  << GPIO_MODER_MODER14_Pos |\
                    PF_15_MODE  << GPIO_MODER_MODER15_Pos |\
                    0;

    GPIOF->AFR[0] = \
                    PF_0_AF  << GPIO_AFRL_AFRL0_Pos |\
                    PF_1_AF  << GPIO_AFRL_AFRL1_Pos |\
                    PF_2_AF  << GPIO_AFRL_AFRL2_Pos |\
                    PF_3_AF  << GPIO_AFRL_AFRL3_Pos |\
                    PF_4_AF  << GPIO_AFRL_AFRL4_Pos |\
                    PF_5_AF  << GPIO_AFRL_AFRL5_Pos |\
                    PF_6_AF  << GPIO_AFRL_AFRL6_Pos |\
                    PF_7_AF  << GPIO_AFRL_AFRL7_Pos |\
                    0;

    GPIOF->AFR[1] = \
                    PF_8_AF  << GPIO_AFRH_AFRH0_Pos |\
                    PF_9_AF  << GPIO_AFRH_AFRH1_Pos |\
                    PF_10_AF  << GPIO_AFRH_AFRH2_Pos |\
                    PF_11_AF  << GPIO_AFRH_AFRH3_Pos |\
                    PF_12_AF  << GPIO_AFRH_AFRH4_Pos |\
                    PF_13_AF  << GPIO_AFRH_AFRH5_Pos |\
                    PF_14_AF  << GPIO_AFRH_AFRH6_Pos |\
                    PF_15_AF  << GPIO_AFRH_AFRH7_Pos |\
                    0;

    GPIOF->OTYPER = \
                    PF_0_OTYPE  << 0 |\
                    PF_1_OTYPE  << 1 |\
                    PF_2_OTYPE  << 2 |\
                    PF_3_OTYPE  << 3 |\
                    PF_4_OTYPE  << 4 |\
                    PF_5_OTYPE  << 5 |\
                    PF_6_OTYPE  << 6 |\
                    PF_7_OTYPE  << 7 |\
                    PF_8_OTYPE  << 8 |\
                    PF_9_OTYPE  << 9 |\
                    PF_10_OTYPE  << 10 |\
                    PF_11_OTYPE  << 11 |\
                    PF_12_OTYPE  << 12 |\
                    PF_13_OTYPE  << 13 |\
                    PF_14_OTYPE  << 14 |\
                    PF_15_OTYPE  << 15 |\
                    0;

    GPIOF->OSPEEDR = \
                    PF_0_OSPEED  << GPIO_OSPEEDER_OSPEEDR0_Pos |\
                    PF_1_OSPEED  << GPIO_OSPEEDER_OSPEEDR1_Pos |\
                    PF_2_OSPEED  << GPIO_OSPEEDER_OSPEEDR2_Pos |\
                    PF_3_OSPEED  << GPIO_OSPEEDER_OSPEEDR3_Pos |\
                    PF_4_OSPEED  << GPIO_OSPEEDER_OSPEEDR4_Pos |\
                    PF_5_OSPEED  << GPIO_OSPEEDER_OSPEEDR5_Pos |\
                    PF_6_OSPEED  << GPIO_OSPEEDER_OSPEEDR6_Pos |\
                    PF_7_OSPEED  << GPIO_OSPEEDER_OSPEEDR7_Pos |\
                    PF_8_OSPEED  << GPIO_OSPEEDER_OSPEEDR8_Pos |\
                    PF_9_OSPEED  << GPIO_OSPEEDER_OSPEEDR9_Pos |\
                    PF_10_OSPEED  << GPIO_OSPEEDER_OSPEEDR10_Pos |\
                    PF_11_OSPEED  << GPIO_OSPEEDER_OSPEEDR11_Pos |\
                    PF_12_OSPEED  << GPIO_OSPEEDER_OSPEEDR12_Pos |\
                    PF_13_OSPEED  << GPIO_OSPEEDER_OSPEEDR13_Pos |\
                    PF_14_OSPEED  << GPIO_OSPEEDER_OSPEEDR14_Pos |\
                    PF_15_OSPEED  << GPIO_OSPEEDER_OSPEEDR15_Pos |\
                    0;

/*GPIOG*/
    GPIOG->ODR = \
                    PG_0_DEFAULT_STATE  << 0 |\
                    PG_1_DEFAULT_STATE  << 1 |\
                    PG_2_DEFAULT_STATE  << 2 |\
                    PG_3_DEFAULT_STATE  << 3 |\
                    PG_4_DEFAULT_STATE  << 4 |\
                    PG_5_DEFAULT_STATE  << 5 |\
                    PG_6_DEFAULT_STATE  << 6 |\
                    PG_7_DEFAULT_STATE  << 7 |\
                    PG_8_DEFAULT_STATE  << 8 |\
                    PG_9_DEFAULT_STATE  << 9 |\
                    PG_10_DEFAULT_STATE  << 10 |\
                    PG_11_DEFAULT_STATE  << 11 |\
                    PG_12_DEFAULT_STATE  << 12 |\
                    PG_13_DEFAULT_STATE  << 13 |\
                    PG_14_DEFAULT_STATE  << 14 |\
                    PG_15_DEFAULT_STATE  << 15 |\
                    0;

    GPIOG->PUPDR = \
                    PG_0_PUPD  << GPIO_PUPDR_PUPDR0_Pos |\
                    PG_1_PUPD  << GPIO_PUPDR_PUPDR1_Pos |\
                    PG_2_PUPD  << GPIO_PUPDR_PUPDR2_Pos |\
                    PG_3_PUPD  << GPIO_PUPDR_PUPDR3_Pos |\
                    PG_4_PUPD  << GPIO_PUPDR_PUPDR4_Pos |\
                    PG_5_PUPD  << GPIO_PUPDR_PUPDR5_Pos |\
                    PG_6_PUPD  << GPIO_PUPDR_PUPDR6_Pos |\
                    PG_7_PUPD  << GPIO_PUPDR_PUPDR7_Pos |\
                    PG_8_PUPD  << GPIO_PUPDR_PUPDR8_Pos |\
                    PG_9_PUPD  << GPIO_PUPDR_PUPDR9_Pos |\
                    PG_10_PUPD  << GPIO_PUPDR_PUPDR10_Pos |\
                    PG_11_PUPD  << GPIO_PUPDR_PUPDR11_Pos |\
                    PG_12_PUPD  << GPIO_PUPDR_PUPDR12_Pos |\
                    PG_13_PUPD  << GPIO_PUPDR_PUPDR13_Pos |\
                    PG_14_PUPD  << GPIO_PUPDR_PUPDR14_Pos |\
                    PG_15_PUPD  << GPIO_PUPDR_PUPDR15_Pos |\
                    0;

    GPIOG->MODER = \
                    PG_0_MODE  << GPIO_MODER_MODER0_Pos |\
                    PG_1_MODE  << GPIO_MODER_MODER1_Pos |\
                    PG_2_MODE  << GPIO_MODER_MODER2_Pos |\
                    PG_3_MODE  << GPIO_MODER_MODER3_Pos |\
                    PG_4_MODE  << GPIO_MODER_MODER4_Pos |\
                    PG_5_MODE  << GPIO_MODER_MODER5_Pos |\
                    PG_6_MODE  << GPIO_MODER_MODER6_Pos |\
                    PG_7_MODE  << GPIO_MODER_MODER7_Pos |\
                    PG_8_MODE  << GPIO_MODER_MODER8_Pos |\
                    PG_9_MODE  << GPIO_MODER_MODER9_Pos |\
                    PG_10_MODE  << GPIO_MODER_MODER10_Pos |\
                    PG_11_MODE  << GPIO_MODER_MODER11_Pos |\
                    PG_12_MODE  << GPIO_MODER_MODER12_Pos |\
                    PG_13_MODE  << GPIO_MODER_MODER13_Pos |\
                    PG_14_MODE  << GPIO_MODER_MODER14_Pos |\
                    PG_15_MODE  << GPIO_MODER_MODER15_Pos |\
                    0;

    GPIOG->AFR[0] = \
                    PG_0_AF  << GPIO_AFRL_AFRL0_Pos |\
                    PG_1_AF  << GPIO_AFRL_AFRL1_Pos |\
                    PG_2_AF  << GPIO_AFRL_AFRL2_Pos |\
                    PG_3_AF  << GPIO_AFRL_AFRL3_Pos |\
                    PG_4_AF  << GPIO_AFRL_AFRL4_Pos |\
                    PG_5_AF  << GPIO_AFRL_AFRL5_Pos |\
                    PG_6_AF  << GPIO_AFRL_AFRL6_Pos |\
                    PG_7_AF  << GPIO_AFRL_AFRL7_Pos |\
                    0;

    GPIOG->AFR[1] = \
                    PG_8_AF  << GPIO_AFRH_AFRH0_Pos |\
                    PG_9_AF  << GPIO_AFRH_AFRH1_Pos |\
                    PG_10_AF  << GPIO_AFRH_AFRH2_Pos |\
                    PG_11_AF  << GPIO_AFRH_AFRH3_Pos |\
                    PG_12_AF  << GPIO_AFRH_AFRH4_Pos |\
                    PG_13_AF  << GPIO_AFRH_AFRH5_Pos |\
                    PG_14_AF  << GPIO_AFRH_AFRH6_Pos |\
                    PG_15_AF  << GPIO_AFRH_AFRH7_Pos |\
                    0;

    GPIOG->OTYPER = \
                    PG_0_OTYPE  << 0 |\
                    PG_1_OTYPE  << 1 |\
                    PG_2_OTYPE  << 2 |\
                    PG_3_OTYPE  << 3 |\
                    PG_4_OTYPE  << 4 |\
                    PG_5_OTYPE  << 5 |\
                    PG_6_OTYPE  << 6 |\
                    PG_7_OTYPE  << 7 |\
                    PG_8_OTYPE  << 8 |\
                    PG_9_OTYPE  << 9 |\
                    PG_10_OTYPE  << 10 |\
                    PG_11_OTYPE  << 11 |\
                    PG_12_OTYPE  << 12 |\
                    PG_13_OTYPE  << 13 |\
                    PG_14_OTYPE  << 14 |\
                    PG_15_OTYPE  << 15 |\
                    0;

    GPIOG->OSPEEDR = \
                    PG_0_OSPEED  << GPIO_OSPEEDER_OSPEEDR0_Pos |\
                    PG_1_OSPEED  << GPIO_OSPEEDER_OSPEEDR1_Pos |\
                    PG_2_OSPEED  << GPIO_OSPEEDER_OSPEEDR2_Pos |\
                    PG_3_OSPEED  << GPIO_OSPEEDER_OSPEEDR3_Pos |\
                    PG_4_OSPEED  << GPIO_OSPEEDER_OSPEEDR4_Pos |\
                    PG_5_OSPEED  << GPIO_OSPEEDER_OSPEEDR5_Pos |\
                    PG_6_OSPEED  << GPIO_OSPEEDER_OSPEEDR6_Pos |\
                    PG_7_OSPEED  << GPIO_OSPEEDER_OSPEEDR7_Pos |\
                    PG_8_OSPEED  << GPIO_OSPEEDER_OSPEEDR8_Pos |\
                    PG_9_OSPEED  << GPIO_OSPEEDER_OSPEEDR9_Pos |\
                    PG_10_OSPEED  << GPIO_OSPEEDER_OSPEEDR10_Pos |\
                    PG_11_OSPEED  << GPIO_OSPEEDER_OSPEEDR11_Pos |\
                    PG_12_OSPEED  << GPIO_OSPEEDER_OSPEEDR12_Pos |\
                    PG_13_OSPEED  << GPIO_OSPEEDER_OSPEEDR13_Pos |\
                    PG_14_OSPEED  << GPIO_OSPEEDER_OSPEEDR14_Pos |\
                    PG_15_OSPEED  << GPIO_OSPEEDER_OSPEEDR15_Pos |\
                    0;

/*GPIOH*/
    GPIOH->ODR = \
                    PH_0_DEFAULT_STATE  << 0 |\
                    PH_1_DEFAULT_STATE  << 1 |\
                    PH_2_DEFAULT_STATE  << 2 |\
                    PH_3_DEFAULT_STATE  << 3 |\
                    PH_4_DEFAULT_STATE  << 4 |\
                    PH_5_DEFAULT_STATE  << 5 |\
                    PH_6_DEFAULT_STATE  << 6 |\
                    PH_7_DEFAULT_STATE  << 7 |\
                    PH_8_DEFAULT_STATE  << 8 |\
                    PH_9_DEFAULT_STATE  << 9 |\
                    PH_10_DEFAULT_STATE  << 10 |\
                    PH_11_DEFAULT_STATE  << 11 |\
                    PH_12_DEFAULT_STATE  << 12 |\
                    PH_13_DEFAULT_STATE  << 13 |\
                    PH_14_DEFAULT_STATE  << 14 |\
                    PH_15_DEFAULT_STATE  << 15 |\
                    0;

    GPIOH->PUPDR = \
                    PH_0_PUPD  << GPIO_PUPDR_PUPDR0_Pos |\
                    PH_1_PUPD  << GPIO_PUPDR_PUPDR1_Pos |\
                    PH_2_PUPD  << GPIO_PUPDR_PUPDR2_Pos |\
                    PH_3_PUPD  << GPIO_PUPDR_PUPDR3_Pos |\
                    PH_4_PUPD  << GPIO_PUPDR_PUPDR4_Pos |\
                    PH_5_PUPD  << GPIO_PUPDR_PUPDR5_Pos |\
                    PH_6_PUPD  << GPIO_PUPDR_PUPDR6_Pos |\
                    PH_7_PUPD  << GPIO_PUPDR_PUPDR7_Pos |\
                    PH_8_PUPD  << GPIO_PUPDR_PUPDR8_Pos |\
                    PH_9_PUPD  << GPIO_PUPDR_PUPDR9_Pos |\
                    PH_10_PUPD  << GPIO_PUPDR_PUPDR10_Pos |\
                    PH_11_PUPD  << GPIO_PUPDR_PUPDR11_Pos |\
                    PH_12_PUPD  << GPIO_PUPDR_PUPDR12_Pos |\
                    PH_13_PUPD  << GPIO_PUPDR_PUPDR13_Pos |\
                    PH_14_PUPD  << GPIO_PUPDR_PUPDR14_Pos |\
                    PH_15_PUPD  << GPIO_PUPDR_PUPDR15_Pos |\
                    0;

    GPIOH->MODER = \
                    PH_0_MODE  << GPIO_MODER_MODER0_Pos |\
                    PH_1_MODE  << GPIO_MODER_MODER1_Pos |\
                    PH_2_MODE  << GPIO_MODER_MODER2_Pos |\
                    PH_3_MODE  << GPIO_MODER_MODER3_Pos |\
                    PH_4_MODE  << GPIO_MODER_MODER4_Pos |\
                    PH_5_MODE  << GPIO_MODER_MODER5_Pos |\
                    PH_6_MODE  << GPIO_MODER_MODER6_Pos |\
                    PH_7_MODE  << GPIO_MODER_MODER7_Pos |\
                    PH_8_MODE  << GPIO_MODER_MODER8_Pos |\
                    PH_9_MODE  << GPIO_MODER_MODER9_Pos |\
                    PH_10_MODE  << GPIO_MODER_MODER10_Pos |\
                    PH_11_MODE  << GPIO_MODER_MODER11_Pos |\
                    PH_12_MODE  << GPIO_MODER_MODER12_Pos |\
                    PH_13_MODE  << GPIO_MODER_MODER13_Pos |\
                    PH_14_MODE  << GPIO_MODER_MODER14_Pos |\
                    PH_15_MODE  << GPIO_MODER_MODER15_Pos |\
                    0;

    GPIOH->AFR[0] = \
                    PH_0_AF  << GPIO_AFRL_AFRL0_Pos |\
                    PH_1_AF  << GPIO_AFRL_AFRL1_Pos |\
                    PH_2_AF  << GPIO_AFRL_AFRL2_Pos |\
                    PH_3_AF  << GPIO_AFRL_AFRL3_Pos |\
                    PH_4_AF  << GPIO_AFRL_AFRL4_Pos |\
                    PH_5_AF  << GPIO_AFRL_AFRL5_Pos |\
                    PH_6_AF  << GPIO_AFRL_AFRL6_Pos |\
                    PH_7_AF  << GPIO_AFRL_AFRL7_Pos |\
                    0;

    GPIOH->AFR[1] = \
                    PH_8_AF  << GPIO_AFRH_AFRH0_Pos |\
                    PH_9_AF  << GPIO_AFRH_AFRH1_Pos |\
                    PH_10_AF  << GPIO_AFRH_AFRH2_Pos |\
                    PH_11_AF  << GPIO_AFRH_AFRH3_Pos |\
                    PH_12_AF  << GPIO_AFRH_AFRH4_Pos |\
                    PH_13_AF  << GPIO_AFRH_AFRH5_Pos |\
                    PH_14_AF  << GPIO_AFRH_AFRH6_Pos |\
                    PH_15_AF  << GPIO_AFRH_AFRH7_Pos |\
                    0;

    GPIOH->OTYPER = \
                    PH_0_OTYPE  << 0 |\
                    PH_1_OTYPE  << 1 |\
                    PH_2_OTYPE  << 2 |\
                    PH_3_OTYPE  << 3 |\
                    PH_4_OTYPE  << 4 |\
                    PH_5_OTYPE  << 5 |\
                    PH_6_OTYPE  << 6 |\
                    PH_7_OTYPE  << 7 |\
                    PH_8_OTYPE  << 8 |\
                    PH_9_OTYPE  << 9 |\
                    PH_10_OTYPE  << 10 |\
                    PH_11_OTYPE  << 11 |\
                    PH_12_OTYPE  << 12 |\
                    PH_13_OTYPE  << 13 |\
                    PH_14_OTYPE  << 14 |\
                    PH_15_OTYPE  << 15 |\
                    0;

    GPIOH->OSPEEDR = \
                    PH_0_OSPEED  << GPIO_OSPEEDER_OSPEEDR0_Pos |\
                    PH_1_OSPEED  << GPIO_OSPEEDER_OSPEEDR1_Pos |\
                    PH_2_OSPEED  << GPIO_OSPEEDER_OSPEEDR2_Pos |\
                    PH_3_OSPEED  << GPIO_OSPEEDER_OSPEEDR3_Pos |\
                    PH_4_OSPEED  << GPIO_OSPEEDER_OSPEEDR4_Pos |\
                    PH_5_OSPEED  << GPIO_OSPEEDER_OSPEEDR5_Pos |\
                    PH_6_OSPEED  << GPIO_OSPEEDER_OSPEEDR6_Pos |\
                    PH_7_OSPEED  << GPIO_OSPEEDER_OSPEEDR7_Pos |\
                    PH_8_OSPEED  << GPIO_OSPEEDER_OSPEEDR8_Pos |\
                    PH_9_OSPEED  << GPIO_OSPEEDER_OSPEEDR9_Pos |\
                    PH_10_OSPEED  << GPIO_OSPEEDER_OSPEEDR10_Pos |\
                    PH_11_OSPEED  << GPIO_OSPEEDER_OSPEEDR11_Pos |\
                    PH_12_OSPEED  << GPIO_OSPEEDER_OSPEEDR12_Pos |\
                    PH_13_OSPEED  << GPIO_OSPEEDER_OSPEEDR13_Pos |\
                    PH_14_OSPEED  << GPIO_OSPEEDER_OSPEEDR14_Pos |\
                    PH_15_OSPEED  << GPIO_OSPEEDER_OSPEEDR15_Pos |\
                    0;

/*GPIOI*/
    GPIOI->ODR = \
                    PI_0_DEFAULT_STATE  << 0 |\
                    PI_1_DEFAULT_STATE  << 1 |\
                    PI_2_DEFAULT_STATE  << 2 |\
                    PI_3_DEFAULT_STATE  << 3 |\
                    PI_4_DEFAULT_STATE  << 4 |\
                    PI_5_DEFAULT_STATE  << 5 |\
                    PI_6_DEFAULT_STATE  << 6 |\
                    PI_7_DEFAULT_STATE  << 7 |\
                    PI_8_DEFAULT_STATE  << 8 |\
                    PI_9_DEFAULT_STATE  << 9 |\
                    PI_10_DEFAULT_STATE  << 10 |\
                    PI_11_DEFAULT_STATE  << 11 |\
                    PI_12_DEFAULT_STATE  << 12 |\
                    PI_13_DEFAULT_STATE  << 13 |\
                    PI_14_DEFAULT_STATE  << 14 |\
                    PI_15_DEFAULT_STATE  << 15 |\
                    0;

    GPIOI->PUPDR = \
                    PI_0_PUPD  << GPIO_PUPDR_PUPDR0_Pos |\
                    PI_1_PUPD  << GPIO_PUPDR_PUPDR1_Pos |\
                    PI_2_PUPD  << GPIO_PUPDR_PUPDR2_Pos |\
                    PI_3_PUPD  << GPIO_PUPDR_PUPDR3_Pos |\
                    PI_4_PUPD  << GPIO_PUPDR_PUPDR4_Pos |\
                    PI_5_PUPD  << GPIO_PUPDR_PUPDR5_Pos |\
                    PI_6_PUPD  << GPIO_PUPDR_PUPDR6_Pos |\
                    PI_7_PUPD  << GPIO_PUPDR_PUPDR7_Pos |\
                    PI_8_PUPD  << GPIO_PUPDR_PUPDR8_Pos |\
                    PI_9_PUPD  << GPIO_PUPDR_PUPDR9_Pos |\
                    PI_10_PUPD  << GPIO_PUPDR_PUPDR10_Pos |\
                    PI_11_PUPD  << GPIO_PUPDR_PUPDR11_Pos |\
                    PI_12_PUPD  << GPIO_PUPDR_PUPDR12_Pos |\
                    PI_13_PUPD  << GPIO_PUPDR_PUPDR13_Pos |\
                    PI_14_PUPD  << GPIO_PUPDR_PUPDR14_Pos |\
                    PI_15_PUPD  << GPIO_PUPDR_PUPDR15_Pos |\
                    0;

    GPIOI->MODER = \
                    PI_0_MODE  << GPIO_MODER_MODER0_Pos |\
                    PI_1_MODE  << GPIO_MODER_MODER1_Pos |\
                    PI_2_MODE  << GPIO_MODER_MODER2_Pos |\
                    PI_3_MODE  << GPIO_MODER_MODER3_Pos |\
                    PI_4_MODE  << GPIO_MODER_MODER4_Pos |\
                    PI_5_MODE  << GPIO_MODER_MODER5_Pos |\
                    PI_6_MODE  << GPIO_MODER_MODER6_Pos |\
                    PI_7_MODE  << GPIO_MODER_MODER7_Pos |\
                    PI_8_MODE  << GPIO_MODER_MODER8_Pos |\
                    PI_9_MODE  << GPIO_MODER_MODER9_Pos |\
                    PI_10_MODE  << GPIO_MODER_MODER10_Pos |\
                    PI_11_MODE  << GPIO_MODER_MODER11_Pos |\
                    PI_12_MODE  << GPIO_MODER_MODER12_Pos |\
                    PI_13_MODE  << GPIO_MODER_MODER13_Pos |\
                    PI_14_MODE  << GPIO_MODER_MODER14_Pos |\
                    PI_15_MODE  << GPIO_MODER_MODER15_Pos |\
                    0;

    GPIOI->AFR[0] = \
                    PI_0_AF  << GPIO_AFRL_AFRL0_Pos |\
                    PI_1_AF  << GPIO_AFRL_AFRL1_Pos |\
                    PI_2_AF  << GPIO_AFRL_AFRL2_Pos |\
                    PI_3_AF  << GPIO_AFRL_AFRL3_Pos |\
                    PI_4_AF  << GPIO_AFRL_AFRL4_Pos |\
                    PI_5_AF  << GPIO_AFRL_AFRL5_Pos |\
                    PI_6_AF  << GPIO_AFRL_AFRL6_Pos |\
                    PI_7_AF  << GPIO_AFRL_AFRL7_Pos |\
                    0;

    GPIOI->AFR[1] = \
                    PI_8_AF  << GPIO_AFRH_AFRH0_Pos |\
                    PI_9_AF  << GPIO_AFRH_AFRH1_Pos |\
                    PI_10_AF  << GPIO_AFRH_AFRH2_Pos |\
                    PI_11_AF  << GPIO_AFRH_AFRH3_Pos |\
                    PI_12_AF  << GPIO_AFRH_AFRH4_Pos |\
                    PI_13_AF  << GPIO_AFRH_AFRH5_Pos |\
                    PI_14_AF  << GPIO_AFRH_AFRH6_Pos |\
                    PI_15_AF  << GPIO_AFRH_AFRH7_Pos |\
                    0;

    GPIOI->OTYPER = \
                    PI_0_OTYPE  << 0 |\
                    PI_1_OTYPE  << 1 |\
                    PI_2_OTYPE  << 2 |\
                    PI_3_OTYPE  << 3 |\
                    PI_4_OTYPE  << 4 |\
                    PI_5_OTYPE  << 5 |\
                    PI_6_OTYPE  << 6 |\
                    PI_7_OTYPE  << 7 |\
                    PI_8_OTYPE  << 8 |\
                    PI_9_OTYPE  << 9 |\
                    PI_10_OTYPE  << 10 |\
                    PI_11_OTYPE  << 11 |\
                    PI_12_OTYPE  << 12 |\
                    PI_13_OTYPE  << 13 |\
                    PI_14_OTYPE  << 14 |\
                    PI_15_OTYPE  << 15 |\
                    0;

    GPIOI->OSPEEDR = \
                    PI_0_OSPEED  << GPIO_OSPEEDER_OSPEEDR0_Pos |\
                    PI_1_OSPEED  << GPIO_OSPEEDER_OSPEEDR1_Pos |\
                    PI_2_OSPEED  << GPIO_OSPEEDER_OSPEEDR2_Pos |\
                    PI_3_OSPEED  << GPIO_OSPEEDER_OSPEEDR3_Pos |\
                    PI_4_OSPEED  << GPIO_OSPEEDER_OSPEEDR4_Pos |\
                    PI_5_OSPEED  << GPIO_OSPEEDER_OSPEEDR5_Pos |\
                    PI_6_OSPEED  << GPIO_OSPEEDER_OSPEEDR6_Pos |\
                    PI_7_OSPEED  << GPIO_OSPEEDER_OSPEEDR7_Pos |\
                    PI_8_OSPEED  << GPIO_OSPEEDER_OSPEEDR8_Pos |\
                    PI_9_OSPEED  << GPIO_OSPEEDER_OSPEEDR9_Pos |\
                    PI_10_OSPEED  << GPIO_OSPEEDER_OSPEEDR10_Pos |\
                    PI_11_OSPEED  << GPIO_OSPEEDER_OSPEEDR11_Pos |\
                    PI_12_OSPEED  << GPIO_OSPEEDER_OSPEEDR12_Pos |\
                    PI_13_OSPEED  << GPIO_OSPEEDER_OSPEEDR13_Pos |\
                    PI_14_OSPEED  << GPIO_OSPEEDER_OSPEEDR14_Pos |\
                    PI_15_OSPEED  << GPIO_OSPEEDER_OSPEEDR15_Pos |\
                    0;

}
/*That is all!*/