#include <stdio.h>
#define TW 12
#define TE 10
typedef struct athlete{
	int score[TE];
	float avg;
	int n;
}athletes;

typedef struct judge{
	int aths[TW];
	int frequency;
	int c;
}judges;

int main(void)
{
	athletes ath[TW];
	athletes temp;
	judges jud[TE];
	judges temp1;
	int i, j, k, max, min, sum;
	printf("Score counting: \n");
	for(i=0;i<TW;i++)
	{
		printf("--------%dth athlete--------\n", i+1);
		for(j=0;j<TE;j++)
		{
			printf("counting %dth athlete's mark: ", j+1);
			scanf("%d", &ath[i].score[j]);
			printf("\n");
			if(ath[i].score[j] > 10 || ath[i].score[j] < 0)
			{
				printf("invalid number\n");
				j = j - 1;
			}
			else 
			{
				jud[j].aths[i] = ath[i].score[j];
				jud[j].c = j + 1;
			}
		}
		ath[i].n = i + 1; 
	}
	
	for(i=0;i<TW;i++)
	{
		jud[i].frequency = 0;
	}
	int c;
	printf("\nJudge Mode\n1. basic\n2. advanced\ninput: ");
	scanf("%d", &c);
	switch(c)
	{
		case 1:
			for(i=0;i<TW;i++)
			{
				sum = 0;
				max = ath[i].score[0];
				min = ath[i].score[0];
				for(j=0;j<TE;j++)
				{
					if(ath[i].score[j] > max)
						max = ath[i].score[j];
					else if(ath[i].score[j] < min)
						min = ath[i].score[j];
					sum += ath[i].score[j];
				}
				ath[i].avg = (sum - max - min) / (TE - 2.0);
			}
			j=1;
			for(i=TW-1;i>=0;i--)
			{
				printf("%dth athlete's average mark is %.2f\n", j, ath[i].avg);
				j++;
			}
			
			printf("RANK: \n-----\n");
			
			for(i=0;i<TW;i++)
			{
				for(j=i;j<TW;j++)
				{
					if(ath[i].avg > ath[j].avg)
					{
						temp = ath[i];
						ath[i] = ath[j];
						ath[j] = temp;
					}
				}
			}
			j = 1;
			for(i=TW-1;i>=0;i--)
			{
				printf("%drd is %dth athlete, average score is %.2f\n", j, ath[i].n, ath[i].avg);
				j++;
			}
		break;
		case 2:
			for(i=0;i<TW;i++)
			{
				max = ath[i].score[0];
				min = ath[i].score[0];
				for(j=0;j<TE;j++)
				{
					if(ath[i].score[j] > max)
						max = ath[i].score[j];
					else if(ath[i].score[j] < min)
						min = ath[i].score[j];
					if(j == TE - 1)
					{
						for(k=TE-1;k>=0;k--)
						{
							if(ath[i].score[k] == max)
								jud[k].frequency++;
							else if(ath[i].score[k] == min)
								jud[k].frequency++;
						}
					}
				}
			}
			
			for(i=0;i<TE;i++)
			{
				for(j=i;j<TE;j++)
				{
					if(jud[i].frequency > jud[j].frequency)
					{
						temp1 = jud[i];
						jud[i] = jud[j];
						jud[j] = temp1;
					}
				}
			}
			
			printf("erased %d, %d, %d \nfrequencies are %d, %d, %d\n", jud[TE-1].c, jud[TE-2].c, jud[TE-3].c, jud[TE-1].frequency, jud[TE-2].frequency, jud[TE-3].frequency);
			
			for(i=0;i<TW;i++)
			{
				sum = 0.0;
				for(j=0;j<TE;j++)
				{
					if(jud[j].c == 10 || jud[j].c == 5 || jud[j].c == 8)
						continue;
					sum += jud[j].aths[i];
				}
				ath[i].avg = sum / (TE-3.0);
			}
			
			for(i=0;i<TW;i++)
			{
				for(j=i;j<TW;j++)
				{
					if(ath[i].avg > ath[j].avg)
					{
						temp = ath[i];
						ath[i] = ath[j];
						ath[j] = temp;
					}
				}
			}
			j=1;
			for(i=TW-1;i>=0;i--)
			{
				printf("%drd is %dth athlete, average score is %.2f\n", j, ath[i].n, ath[i].avg);
				j++;
			}
		break;
	}
	return 0;
}
