/*
 * if this function is called many times, change it to assemble code.
 */
uint32_t reverseBits(uint32_t n)
{
	int	 bit;
	uint32_t res = 0;

	for (bit = 0; bit < 32; bit++) {
		res <<= 1;
		if (n & (1 << bit))
			res += 1;
	}

	return res;
}
