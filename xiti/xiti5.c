/*
 * @Author: fengsc
 * @Date: 2021-03-09 15:25:16
 * @LastEditTime: 2021-03-24 13:22:21
 */

#include <stdio.h>
#include <string.h>

int CountDigit(int number, int digit);

int main()
{
	int number, digit;

	scanf("%d %d", &number, &digit);
	printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));

	return 0;
}
int CountDigit(int number, int digit)
/*{
		int sum = 0, m = 0;
		while (number != 0)
			
		{
			m = number % 10;
			if (m == digit)
				sum ++;
			number = number / 10;
		}
		return sum;
	}*/
{

	char num[10];
	int sum = 0;
	sprintf(num, "%d", number);
	for (int i = 0; i < strlen(num); i++)

	{

		if (num[i] == '0' + digit)

			sum++;
	}

	return sum;
}

