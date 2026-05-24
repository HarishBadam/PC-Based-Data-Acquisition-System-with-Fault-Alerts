#define FOSC 12000000
#define CCLK (5*FOSC)
#define PCLK (CCLK/4)
#define ADC_CLK 3000000
#define DIVISOR ((PCLK/ADC_CLK)-1)

#define CLK_DIV_BITS 8
#define PDN_BIT 21
#define START_CONV_BITS 24

#define DONE_BIT 31
#define ADCVAL_BITS 6
