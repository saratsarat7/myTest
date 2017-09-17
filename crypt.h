void encrypt(char *array, int array_size)
{
    int i;
	int j = 0;
    char secret[8] = { 22, 53, 44, 71, 66, 177, 253, 122 };
    for(i = 0; i < array_size; i++)
	{
		// printf("%d %d \n",i, j);
        array[i] ^= secret[j];
		if (j == 7)
			j = 0;
		j++;
	}
}

void decrypt(char *array, int array_size)
{
    int i;
	int j = 0;
    char secret[8] = { 22, 53, 44, 71, 66, 177, 253, 122 };
    for(i = 0; i < array_size; i++)
	{
		// printf("%d %d \n",i, j);
        array[i] ^= secret[j];
		if (j == 7)
			j = 0;
		j++;
	}
}