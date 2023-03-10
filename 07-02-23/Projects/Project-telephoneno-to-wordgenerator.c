#include <stdio.h>
#include <string.h>

const char hashTable[10][5]
	= { "", "", "abc", "def", "ghi",
		"jkl", "mno", "pqrs", "tuv", "wxyz" };

void printWordsUtil(int number[], int curr_digit,
					char output[], int n)
{
	int i;
	if (curr_digit == n) {
		printf("%s ", output);
		return;
	}

	for (i = 0; i < strlen(hashTable[number[curr_digit]]);
		i++) {
		output[curr_digit]
			= hashTable[number[curr_digit]][i];
		printWordsUtil(number, curr_digit + 1, output, n);
		if (number[curr_digit] == 0
			|| number[curr_digit] == 1)
			return;
	}
}

void printWords(int number[], int n)
{
	char result[n + 1];
	result[n] = '\0';
	printWordsUtil(number, 0, result, n);
}

int main(void)
{
	int number[7],num;
	printf("Enter number\n");
	scanf("%d",&num);

	for(int i = 0;i<7;i++)
	{
		int rem=num%10;
		number[i]=rem;
		num=num/10;
	}
	printf("\n\n");

	for(int i = 0;i<7;i++){
		printf("%d ",number[i]);
	}
	int n = sizeof(number) / sizeof(number[0]);

	printWords(number, n);
	
	return 0;
}
