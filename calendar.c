#include <stdio.h>
int isLeapYear(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonth[month - 1];
}
int getFirstDayOfWeek(int month, int year) {
    int dayOfWeek;
    int day = 1;
    int monthTable[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    dayOfWeek = (year % 100) / 4 + (year / 400) * 2 - monthTable[month - 1] + day + (year % 100) - (year % 100) / 4;
    if (isLeapYear(year) && month < 3) {
        dayOfWeek--;
    }
    dayOfWeek %= 7;
    return dayOfWeek;
}
void printCalendar(int month, int year) {
    int daysInMonth = getDaysInMonth(month, year);
    int firstDayOfWeek = getFirstDayOfWeek(month, year);
    int i, j;
    
    printf("   Month: %d, Year: %d\n", month, year);
    printf("-----------------------------\n");
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
    for (i = 0; i < firstDayOfWeek; i++) {
        printf("    ");
    }
    for (i = 1; i <= daysInMonth; i++) {
        printf("%4d", i);
        if ((i + firstDayOfWeek) % 7 == 0 || i == daysInMonth) {
            printf("\n");
        }
    }
}
int main() {
    int month, year;
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);
    printCalendar(month, year);
    return 0;
}
