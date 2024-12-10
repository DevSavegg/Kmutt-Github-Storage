#include <stdio.h>
#include <string.h>

#define DUE_DATE 75

char month_list[13][255] = {
	"",
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Oct",
	"Nov",
	"Dec"
};

int month_day_amount[13] = {
	-1,
	31,
	28,
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};

int main() {
    	int date, month, year;
	printf("Input dd,mm,yyyy : ");
	scanf("%d,%d,%d", &date, &month, &year);

	date = date + DUE_DATE;

	for (int i = 0;; i++) {
		int currentMonth;
		int isLeapYear = year % 4 == 0 ? 1 : 0;
		
		currentMonth = month_day_amount[month];
		if (isLeapYear == 1 && month == 2) {
			currentMonth = currentMonth + 1;
		}		

		if (date > currentMonth) {
			date = date - currentMonth;
			month++;
		} else {
			break;
		}
		if (month > 12) {
			month = 1;
			year++;
			
			if (year % 4 == 0) {
				isLeapYear = 1;
			}
		}
	}

	printf("Due Date : ");
	printf("%d %s %d", date, month_list[month], year);
	return 0;
}
