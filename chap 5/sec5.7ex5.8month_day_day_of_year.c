#include<stdio.h>
main()
{
    int month, day;
    month_day(2024, 32, &month, &day);
    printf("\t%d\t%d\n", month, day);

}
static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 20, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

//day_of_year: return day of year from month and day
int day_of_year(int year, int month, int day)
{
    int i , leap;

    leap =  year%4==0 && year%100!=0 || year%400==0;
    if((month<=12 && month>=1) &&
        day<=daytab[leap][month] && day>=1) {
        for (i = 1; i < month; i++)
            day = day + daytab[leap][i];
        return day;
    }
    else
        printf("invalid day or month");
    return 0;

}

//month_day: return month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i ,leap;

    leap = year%4==0 && year%100!=0 || year%400==0;
    if(yearday<=yearday+leap) {                             // if leap 365+1, if not 365+0
        for (i = 1; yearday > daytab[leap][i]; i++)
            yearday = yearday - daytab[leap][i];
        *pmonth = i;
        *pday = yearday;
    }
    else
        printf("invalid day of year");

}