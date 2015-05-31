int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
	if (!gas || !gasSize || !cost || !costSize || gasSize != costSize)
		return(-1);
	if (gasSize == 1)
		return(gas[0] >= cost[0] ? 0 : -1);

	int	index, sum, total;
	int	i;

	index = -1;
	sum = total = 0;
	for (i = 0; i < gasSize; i++) {
		sum += gas[i] - cost[i];
		total += sum;
		if (sum < 0) {
			sum = 0;
			index = i;
		}
	}

	if (total < 0)
		return(-1);
	else 
		return(++index % gasSize);
}
