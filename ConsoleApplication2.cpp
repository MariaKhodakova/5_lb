#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stack>
#include <queue>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

using namespace std;
queue <int> Q; //очередь
int i, j, N, st, m;
int** graph; // матрица смежности
bool* visited = new bool[m]; // посещенные вершины = выделение памяти под массив

void BFS(int st) //алгоритм обхода в ширину
{
	Q.push(st); //заносим вершину в очередь
	visited[st] = true; //помечаем вершину как пройденную
	while (!Q.empty())
	{
		st = Q.front(); //перемещаем в начало очереди
		Q.pop(); //выносим из очереди
		printf("%d ", st + 1);
		for (j = 0; j < N; j++)
		{
			if ((graph[st][j] == 1) && (!visited[j]))
			{
				visited[j] = true; //помечаем вершину, удовлетворяющую условию, как пройденную
				Q.push(j); //заносим ее в очередь

			}
		}
	}

}

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Ведите размер матрицы ");
	scanf_s("%d", &N);
	srand(time(NULL));
	graph = new int* [N]; // выделяем память под граф

	for (int i = 0; i < N; i++) {
		graph[i] = new int[N];
	}

	for (i = 0; i < N; ++i)
	{
		for (j = i; j < N; ++j)
		{
			graph[i][j] = graph[j][i] = rand() % 2;
			graph[i][i] = graph[j][j] = 0; // чтобы петля(узел) не создавалась
		}

	}
	printf(" ");
	for (j = 0; j < N; j++)
	{
		printf("%4d ", j + 1); //горизонтальный порядок чисел сверху матрицы
	}
	printf("\n\n");
	for (i = 0; i < N; i++) {

		printf(" %d ", i + 1); // вертикальный порядок фиссел слева матрицы

		for (j = 0; j < N; j++)
		{
			printf("%4d ", graph[i][j]);
		}
		printf("\n\n");
	}

	printf("\nВведите вершину: ");
	scanf_s("%d", &st);
	while (st > N) {
		printf("\nТакая вершина не существует!\n");
		printf("\nВведи вершину: ");
		scanf_s("%d", &st);
	}
	for (i = 0; i < N; i++)
	{
		visited[i] = false; //помечаем все элементы как не пройденный
	}

	printf("\n Результат обхода матрицы смежности графа в ширину:");
	BFS(st - 1);
	printf("\n\n");

	system("pause");

}