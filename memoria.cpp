#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char table[4][3];
char xtable[4][3];
char resultsTable[4][3];
int cardNumbers[12];

int totalScore = 0;

void randomNumberGenerator() {
	for (int i = 0; i != 12 / 2; ++i)
	{
		cardNumbers[i] = i + 1;
		cardNumbers[12 / 2 + i] = i + 1;
	}

	size_t i;
	for (i = 0; i < 12 - 1; i++)
	{
		size_t j = i + rand() / (RAND_MAX / (12 - i) + 1);
		int t = cardNumbers[j];
		cardNumbers[j] = cardNumbers[i];
		cardNumbers[i] = t;
	}
}

void generateResultsTable() 
{
	int i, j = 0;
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 3; i++)
		{
			resultsTable[j][i] = table[j][i];
		}
	}
}

void generateTable()
{
	int i, j, k = 0;

	
	for (j = 0; j < 4; j++)
	{

		for (i = 0; i < 3; i++)
		{
			int randomNumber = cardNumbers[k];
			table[j][i] = randomNumber+'0';
			k++;
			printf("  %c    ", table[j][i]);
		}
		printf("\n\n");
	}

	Sleep(2000);
	system("cls");
}

void xTable()
{
	int i, j = 0;

	for (j = 0; j < 4; j++)
	{

		for (i = 0; i < 3; i++)
		{

			xtable[j][i] = 'x';
			printf("  %c    ", xtable[j][i]);
		}
		printf("\n\n");
	}
}

void renderXTable()
{
	int i, j = 0;

	for (j = 0; j < 4; j++)
	{

		for (i = 0; i < 3; i++)
		{
			printf("  %c    ", xtable[j][i]);
		}
		printf("\n\n");
	}
}

void showResults(int x, int y, int w, int z)
{
	char card1 = table[x][y];
	char card2 = table[w][z];

	if (card1 == card2)
	{
		xtable[x][y] = 'J';
		xtable[w][z] = 'J';
		resultsTable[x][y] = 'J';
		resultsTable[w][z] = 'J';
		totalScore++;
		renderXTable();
	}

	if (card1 != card2)
	{
		if (resultsTable[x][y] != 'J')
			xtable[x][y] = 'x';
		else if (resultsTable[x][y] == 'J')
			xtable[x][y] = 'J';

		if (resultsTable[w][z] != 'J')
			xtable[w][z] = 'x';
		else if (resultsTable[w][z] == 'J')
			xtable[w][z] = 'J';

		renderXTable();
		printf("\n\nErrou!");
	}

	if (totalScore == 6)
	{
		printf("\nFim de jogo!");
		return;
	}
}

void selectCard()
{
	int x, y;
	int w, z;

	printf("\n\nDigite a coordenada (x, y):\n");
	scanf("%d", &x);
	scanf("%d", &y);

	xtable[x][y] = table[x][y];

	printf("\nDigite a coordenada (x, y):\n");

	scanf("%d", &w);
	scanf("%d", &z);

	xtable[w][z] = table[w][z];

	system("cls");

	renderXTable();

	Sleep(2000);

	system("cls");

	showResults(x, y, w, z);
}

void play()
{
	srand(time(NULL));

	randomNumberGenerator();
	generateTable();
	generateResultsTable();
	xTable();

	while (totalScore < 6)
	{
		selectCard();
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");

	play();
}
