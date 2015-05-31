#include <stdint.h>

static char bits[] = {
	0, 8, 4, 12, 
	2, 10, 6, 14,
	1, 9, 5, 13,
	3, 11, 7, 15,
};

uint32_t reverseBits(uint32_t n)
{
	uint32_t i;
	uint32_t res = 0;

	for (i = 0; i < 8; i++) {
		res = (res << 4) + bits[n & (uint32_t)15];
		n >>= 4;
	}
	return(res);
}

int main(void)
{}
