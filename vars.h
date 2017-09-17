struct platformVar {
   int  varId;
   char varData[100];
};

struct staticVar {
	char s1[10];
	int s2;
	float s3;
	char s4[10];
	double s5;
	char s6[1];
	float s7;
	struct platformVar s8;
};

struct offsetVar {
  int offset;
  int length;
};
