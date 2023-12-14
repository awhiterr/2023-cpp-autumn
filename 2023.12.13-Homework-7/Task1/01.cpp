#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

	void CountSize(char* filename, int& lines, int& maxLine)
	{
		FILE* file = fopen("help.txt", "r");
		int currentLen = 0;
		while (!feof(file))
		{
			char c = 0;
			fscanf_s(file, "%c", &c);
			if (c == '\n')
			{
				lines++;
				currentLen = 0;
			}
			else
			{
				currentLen++;
			}
			maxLine = (maxLine > currentLen ? maxLine : currentLen);
		}
		lines++;
		fclose(file);
	}

	int strlength(char* str)
	{
		int res = 0;
		while (str[res++] != '\0');
		return res;
	}

	void ReadLines(char* filename, char** lines, int maxlen)
	{
		FILE* file = fopen(filename, "r");

		int ind = 0;
		while (!feof(file))
		{
			fgets(lines[ind], maxlen, file);
			ind++;
		}

		fclose(file);
	}

	char* strcat(char* str1, char* str2)
	{

	}

	int strcompare(char* str1, char* str2)
	{
		int strlen1 = strlength(str1);

		for (int i = 0; i <= strlen1; i++)
		{

			if (str1[i] > str2[i])
			{
				return 1;
			}

			if (str1[i] < str2[i])
			{
				return -1;
			}
		}

		return 0;
	}

	char* strcpy()
	{

	}


	int main(int argc, char** argv)
	{
		FILE* file = fopen("help.txt", "r");

		char a[255] = { 0 };
		fscanf(file, "%s", &a);

		char b[255] = { 0 };
		fscanf(file, "%s", &b);

		fclose(file);

		/*

			int w = 0;
			int h = 0;
			char filename[255];
			strcpy(filename, "in.txt");
			CountSize(filename, h, w);
			char** lines = (char**)malloc(sizeof(char*) * h);
			for (int i = 0; i < h; ++i)
			{
				lines[i] = (char*)malloc(sizeof(char) * w);
			}
			ReadLines(filename, lines, w);


			for (int i = 0; i < h; ++i)
			{
				free(lines[i]);
			}
			free(lines);
			*/
		return EXIT_SUCCESS;
	}