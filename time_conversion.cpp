/*
Given a time in - hour AM / PM format, convert it to military(-hour) time.

Note: Midnight 12:00:00AM -> 00:00::00.Noon 12:00:00PM -> 12:00:00.

	  Input Format

	  A single string containing a time in - hour clock format(i.e.: or), where and .

	  Output Format

	  Convert and print the given time in - hour format, where .

	  Sample Input

	  07:05 : 45PM

	  Sample Output

	  19 : 05 : 45
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	int hh, mm, ss;
	char t12[3];

	scanf("%d:%d:%d%s", &hh, &mm, &ss, t12);
	if (strcmp(t12, "PM") == 0 && hh != 12) hh += 12;
	if (strcmp(t12, "AM") == 0 && hh == 12) hh = 0;

	printf("%02d:%02d:%02d", hh, mm, ss);	
	return 0;
}
