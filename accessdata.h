void getData(char * fileName, char * fileData, int dataSize)
{
	FILE * fp;
	
	fp = fopen (fileName, "a+");
	fread(fileData, dataSize, 1, fp);

	fclose(fp);
}

void writeData(char * fileName, char * data)
{
	FILE * fp;
	
	fp = fopen (fileName, "w+");
	encrypt(data, strlen(data));	
	fprintf(fp, "%s", data);
	
	fclose(fp);
}