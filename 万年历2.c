#include <stdio.h>
#include <stdlib.h>
typedef struct date{
	int year;
	int month;
	int day;
}dt;
int main(void)
{
	dt date;
	printf("Calendar\n");
	int placeholder, day, i, sum = 0, sum1 = 0, n, m, d, j, w, s = 0, a, k, e, f, q = 1, r = 1, c, g;
	char* week[] = {"Sun", "Mon", "Tue", "Wen", "Thu", "Fri", "Sat"};
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
	int month1[11] = {28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	printf("Please input the digit for the function you want to use: \n1.look up whole year's carlendar.\n2.look up certain month within a year\n3.day look up.\n\ninput: ");
	scanf("%d", &placeholder);
	while(placeholder > 3 || placeholder < 0)
	{
		printf("invalid input\ntry again: ");
		scanf("%d", &placeholder);
	}
	
	printf("Please input year, month, day: ");
	scanf("%d%d%d", &date.year, &date.month, &date.day);
	if(date.month > 12 || date.month < 1 || date.day < 1 || date.day > 31)
	{
		printf("invalid month or day.\n month again: ");
		scanf("%d", &date.month);
		printf("\nday again: ");
		scanf("%d", &date.day);
	}
	for(i=1;i<date.year;i++)
	{
		if((date.year % 4 == 0 && date.year % 100 != 0)|| date.year % 400 == 0)
			s += 1;
		s += 365;
	}
	w = (s+1) % 7;
	if(date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0)
	{
		month[1] += 1;
		month1[0] += 1;
	}
	switch(placeholder)
	{
		case 1:		
			printf("%10c------------------------------------------Calendar of %d----------------------------------------------\n", '-', date.year);
			for(k=0;k<12;k++)
			{	
				if(k % 2 == 0)
				{
					printf("%10c----------------------%d---------------------------", '-', k+1);
					printf("  --------------------------%d------------------------\n", k+2);
					printf("%10c", ' ');
					printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat    Sun\tMon\tTue\tWed\tThu\tFri\tSat\n", ' ', k + 1);
					printf("\n%10c", ' ');
					for(j=0;j<w;j++)
					{
						printf(" \t");
					}
					if(k == 0)
						f = (w + month1[k] + month[k]) % 7;
					else 
						f = (f + month1[k-1] + month[k-1]) % 7;
					for(i=q;i<=month[k];i++)
					{
						printf("%d\t", i);
						if((i+w) % 7 == 0)
						{
							q = i;
							if(i+w == 7)
							{
								for(j=0;j<f;j++)
								{
									printf(" \t");
								}
								if(f==7)
									printf("\n");
							}
							for(c=r;c<=month1[k];c++)
							{
								printf("%d\t", c);
								if((f + c) % 7 == 0)
								{
									r = c + 1;
									printf("\n");
									break;
								}
								if(c == month1[k])
									printf("\n\n");
							}
						}
						if((w + i) % 7 == 0)
							printf("\n%10c", ' ');
						if(i == month[k])
						{
							if(w + month[k] < 35)
								g = 35 - w - month[k];
							else
								g = 42 - w - month[k];
							for(e=0;e<g;e++)
							{
								printf(" \t");
							}
							for(j=c+1;j<month1[k];j++)
							{
								printf("%d\t", j);
							}
							printf("\n\n");
						}
					}
					q = 1, r = 1;
				}
				w = (w + month[k]) % 7;
			}
		break;
		case 2:
			printf("---------------------%d. %d-----------------------\n", date.year, date.month);
			for(i=0;i<7;i++)
			{
				printf("%s\t", week[i]);
			}
			printf("\n");
			for(j=0;j<w;j++)
			{
				printf(" \t");
			}
			for(i=1;i<=month[date.month-1];i++)
			{
				printf("%d\t", i);
				if((w + i) % 7 == 0)
					printf("\n");
			}
		break;
		case 3:
			printf("Please input the date you want to look up: ");
			do
			{
				scanf("%d%d", &m, &d);
				if(m > 12 || m < 1 || d < 1 || d > 31)
					printf("invalid number.\ninput again: ");
			}while (m > 12 || m < 1 || d < 1 || d > 31);
			for(i=0;i<date.month;i++)
			{
				sum += month[i];
			}
			for(j=0;j<m;j++)
			{
				sum1 += month[j];
			}
			n = (sum1 + d) - (sum + date.day);
			if(n > 0)
				printf("%d days after.", n);
			else if(n == 0)
				printf("exact the day.");
			else if(n < 0)
				printf("%d days passed.", n * (-1));
		break;
	}
}
