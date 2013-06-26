#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LEN 10
#define MAX_NUM_STR_LEN (MAX_NUM_LEN + 1)

int compare(const void *a, const void *b)
{
	char tmp1[2*MAX_NUM_LEN + 1] = {0};
	char tmp2[2*MAX_NUM_LEN + 1] = {0};

	strcpy(tmp1, *(const char **)a);
	strcat(tmp1, *(const char **)b);

	strcpy(tmp2, *(const char **)b);
	strcat(tmp2, *(const char **)a);

	return strcmp(tmp1, tmp2);
}

int number_connect(int *numbers, int len)
{
	char **num_strs = NULL;
	int i = 0;
	num_strs = (char **)malloc(len * sizeof(char *));
	if(NULL == num_strs)
		return -1;
	for(i = 0; i < len; i++) {
		num_strs[i] = (char *)malloc(MAX_NUM_STR_LEN);
		sprintf(num_strs[i],"%d",numbers[i]);
	}
	qsort(num_strs, len, sizeof(char *), compare);

	for(i = 0; i < len; i++) {
		printf("%s", num_strs[i]);
		free(num_strs[i]);
	}
	printf("\r\n");

	if(num_strs)
		free(num_strs);

	return 0;
}

int main(int argc, char **argv)
{
	int numbers[10] = {3, 32, 321, 19, 2, 3, 9, 99883312,111, 121};
	int i = 0;

	for(i = 0; i < 10; i++)
		printf("%d ", numbers[i]);
	printf("\r\n");
	number_connect(numbers, 10);

	return 0;
}

