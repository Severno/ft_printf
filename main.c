#include <stdio.h>
#include <math.h>
#include "includes/ft_printf.h"

//void static test_func(void **value)
//{
//	char *str;
//	str = (char *)value;
//	int i = 0;
//	while (str[i])
//	{
//		putchar(str[i]);
//		i++;
//	}
//
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdint.h>
//#include <math.h>
//
//#define ABSOLUTE_WIDTH 61
//#define MANTISSA_WIDTH 52
//#define EXPONENT_WIDTH 8
//#define EXPONENT_MASK 0xffu
//#define MANTISSA_MASK 0x007fffffu
//#define EXPONENT_BIAS 127
//
//union float_bits {
//	float f;
//	uint32_t bits;
//};
//
//void print_float( FILE *output, float f ) {
//	union float_bits t; t.f = f;
//
//	uint32_t sign_bit = ( t.bits >> ABSOLUTE_WIDTH );
//	uint32_t exponent = ( t.bits >> MANTISSA_WIDTH ) & EXPONENT_MASK;
//	uint32_t mantissa = ( t.bits  &  MANTISSA_MASK );
//
//	if( sign_bit != 0 ) {
//		fprintf( output, "-" );
//	}
//
//	if( exponent > 2 * EXPONENT_BIAS ) {
//		fprintf( output, "Inf\n" ); /* Infinity */
//		return;
//	} else if( exponent == 0 ) {
//		fprintf( output, "0." ); /* Zero or Denormal */
//		exponent = ( mantissa != 0 ) ? exponent + 1 : exponent;
//	} else {
//		fprintf( output, "1." ); /* Usual */
//	}
//
//	for( int k = MANTISSA_WIDTH - 1; k >= 0; --k ) {
//		fprintf( output, "%d", ( mantissa >> k ) & 1 );
//	}
//
//	if( exponent != 0 || mantissa != 0 ) {
//		fprintf( output, " * 2^%d\n", (int) ( exponent - EXPONENT_BIAS ) );
//	}
//}
//inline double fraction(double x)
//{
//	// Get the fraction
//	uint64_t frac_mask = (1ul << 52) - 1;                      // Get 52 1's
////    uint64_t xint = *reinterpret_cast<uint64_t*>(&x);        // Interpret x's bits as an int
//	uint64_t xint;
//	memcpy(&xint, &x, sizeof(xint));        // Interpret x's bits as an int
//	int64_t frac_num = xint & frac_mask;                                    // Get the fraction as an int
//	frac_num += 1ul << 52; // Add hidden bit.
//	double fraction = double(frac_num) / double(2ul << 52);              // Divide frac_num by 2^52
//
//	return fraction;
//}

int main()
{
//	char res[20];
//	float n = 233.007f / 3.3f;
//	float n1 = 233.007f / 3.3f;
//	printf("%12f", 1234.235600);
//	printf("\n");
//	ft_printf("%12f", 1234.235600);
//	unsigned r = 0;
//	for (unsigned i=12; i<=16; i++)
//		r |= 1 << i;
//	double f = 123.356;
//	union float_bits t; t.f = f;
//
//	uint32_t sign_bit = ( t.bits >> ABSOLUTE_WIDTH );
//	uint32_t exponent = ( t.bits >> MANTISSA_WIDTH ) & EXPONENT_MASK;
//	uint32_t mantissa = ( t.bits  &  MANTISSA_MASK );
//	double dbl = 123.999;
//	int a = 255;
//	int b = 120;
//	int c = 0;
//	c = a << 2;
//	printf("a = %d\n", a);
//	printf("b = %d\n", b);
//	printf("c = %d\n", c);
//	printf("sign bit = %d\n", sign_bit);
//	printf("exponent = %d\n", exponent);
//	printf("mantissa = %d\n", mantissa);
//	printf("%hhu, %hu, %u", (char)123, (short) 40000, 1234567890);
//	printf("\n");
//	ft_printf("%hhu, %hu, %u", (char)123, (short) 40000, 1234567890);
	printf("%#37lx", 22337203685477ul);
	printf("\n");
	ft_printf("%#37lx", 22337203685477ul);
	return 0;
}