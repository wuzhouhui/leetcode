int hammingWeight(uint32_t n)
{
	int bit = 0;
	int	nr = 0;

	while (bit <= 31) {
		if (n & (1 << bit))
			nr++;
		bit++;
	}

	return nr;
}
