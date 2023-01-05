#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
    // Get the month and year from the command-line arguments
    int month = 0;
    int year = 0;
    if (argc == 3) {
        month = atoi(argv[1]);
        year = atoi(argv[2]);
    } else if (argc == 2 ) {
	int a = atoi(argv[1]);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	if (a > 31) {
		year = a;
		month = tm.tm_mon + 1;
	}
	else {
		year = tm.tm_year + 1900;
    		month = a;
	}
    }
    else {
        // Get the current month and year if no arguments are provided
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        month = tm.tm_mon + 1;
        year = tm.tm_year + 1900;
    }

    // Get the number of days in the month
    int days_in_month = 0;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days_in_month = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days_in_month = 30;
            break;
        case 2:
            days_in_month = 28;
            break;
    }

    // Get the day of the week of the first day of the month
    struct tm tm;
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = 1;
    mktime(&tm);
    int first_day = tm.tm_wday;

    // Print the calendar header
    printf("     %d %d\n", month, year);
    printf("Su Mo Tu We Th Fr Sa\n");

    // Print the calendar body
    for (int i = 0; i < first_day; i++) {
        printf("   ");
    }

    for (int i = 1; i <= days_in_month; i++) {
        if (i < 10) {
            printf(" ");
        }
        printf("%d", i);
        if ( (i + first_day - 1) % 7 == 0) {
            printf("\n");
        } else {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}
