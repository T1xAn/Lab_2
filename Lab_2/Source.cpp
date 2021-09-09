#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int a[200][200], b[200][200], c[200][200], elem_c;

int main(void)
{
	setlocale(LC_ALL, "Russian");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	time_t begin_clock, end_clock;
	clock_t start, end; // объявляем переменные для определения времени выполнения

	int i = 0, j = 0, r;
	

	

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < 200)
	{
		while (j < 200)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < 200)
	{
		while (j < 200)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	 start = clock();
	for (i = 0; i < 200; i++)
	{
		for (j = 0; j < 200; j++)
		{
			elem_c = 0;
			for (r = 0; r < 200; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	end = clock();
	double time = difftime(end, start) / CLOCKS_PER_SEC;
	 printf(" Время премножения жвух массивов составило - %f секунд", time);
	/*std::cout << "Вам понадобилось  "
		<< difftime(end, start)
		<< " секунд для ввода своего имени.n";*/

	return(0);
}
