﻿#include <iostream>
#include <locale>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int count = 2;
    cout << "Введите размер матрицы: ";
    cin >> count;
    cout << "Процедура для матрицы смежности:" << endl;

    clock_t start, end;

    int** arr1 = new int* [count];


    for (int i = 0; i < count; i++) {
        arr1[i] = new int[count];
        for (int j = 0; j < count; j++) {
            arr1[i][j] = 0;
        }
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {

            int p = rand() % 101;

            if (i == j) {
                arr1[i][j] = 0;
                continue;
            }

            if (p > 70) {
                int weight = rand() % 10;
                arr1[i][j] = 1;
                arr1[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            cout << arr1[i][j] << ' ';
        }
        cout << endl;
    }
    /*
   Для графа представленного матрицей мы нашли расстояния между вершинами.
    */

    queue<int> Queue;
    int* visited = new int[count];
    cout << endl << endl;


    for (int h = 0; h != count; h++) {
        start = clock();

        for (int i = 0; i != count; i++) visited[i] = -1;
        cout << "Вершина " << h << endl;
        Queue.push(h);
        visited[h] = 0;

        while (!Queue.empty()) {

            int node = Queue.front();
            Queue.pop();

            for (int i = 0; i != count; i++) {
                if (arr1[node][i] == 1 && visited[i] == -1) {
                    Queue.push(i);
                    visited[i] = visited[node] + 1;
                }
            }
        }

        for (int i = 0; i != count; i++) cout << visited[i] << ' ';
        cout << endl;
        double time = 0.0;
        end = clock();
        time += (double)(end - start) / CLOCKS_PER_SEC;
        printf("Время работы: %lf сек.\n", time);
    }

    /*
    Для графа представленного списками смежности мы нашли расстояния между вершинами.
    */
    cout << endl << endl << "Процедура для списка смежности:" << endl;

    vector< vector< int> > arr2;
    arr2.resize(count);

    for (int i = 0; i != count; i++) {
        for (int j = 0; j != count; j++) {
            if (arr1[i][j] != 0) {
                arr2[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < arr2.size(); i++) {
        for (int j = 0; j < arr2[i].size(); j++) {
            cout << arr2[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl << endl;


    for (int h = 0; h < count; h++) {

        for (int i = 0; i != count; i++) visited[i] = -1;

        cout << "Вершина " << h << endl;
        Queue.push(h);
        visited[h] = 0;

        while (!Queue.empty()) {

            int node = Queue.front();
            Queue.pop();

            for (int i = 0; i != arr2[node].size(); i++) {

                if (visited[arr2[node][i]] == -1) {
                    Queue.push(arr2[node][i]);
                    visited[arr2[node][i]] = visited[node] + 1;
                }
            }
        }
        for (int i = 0; i != count; i++) cout << visited[i] << ' ';
        cout << endl;
    }


    /*
  Реализовли на основе обхода в глубину.
    */
    cout << endl << endl << "Процедура для матрицы смежности через обход в глубину:" << endl << endl;

    stack<int> Stack;
    int* top = new int[count];

    for (int h = 0; h != count; h++) {
        start = clock();

        cout << "Вершина " << h << endl;

        for (int q = 0; q != count; q++) {

            if (h == q) continue;

            for (int i = 0; i != count; i++) {
                top[i] = 1000;
            }

            Stack.push(h);
            top[h] = 0;

            while (!Stack.empty()) {

                int node = Stack.top();
                Stack.pop();

                if (node == q) continue;

                for (int i = 0; i != count; i++) {
                    if (arr1[node][i] == 1 && top[i] > top[node]) {
                        Stack.push(i);
                        top[i] = top[node] + 1;
                    }
                }
            }
            cout << top[q] << ' ';
        }
        cout << endl;
        double time = 0.0;
        end = clock();
        time += (double)(end - start) / CLOCKS_PER_SEC;
        printf("Время работы: %lf сек.\n", time);
    }


    /*
    Для графа представленного списками на основе обхода в глубину мы нашли расстояния между вершинами.
    */
    cout << endl << endl << "Процедура для списка смежности через обход в глубину:" << endl << endl;

    for (int h = 0; h != count; h++) {

        cout << "Вершина " << h << endl;

        for (int q = 0; q != count; q++) {

            if (h == q) continue;

            for (int i = 0; i != count; i++) {
                top[i] = 1000;
            }

            Stack.push(h);
            top[h] = 0;

            while (!Stack.empty()) {

                int node = Stack.top();
                Stack.pop();

                if (node == q) continue;

                for (int i = 0; i != arr2[node].size(); i++) {
                    if (top[arr2[node][i]] > top[node]) {
                        Stack.push(arr2[node][i]);
                        top[arr2[node][i]] = top[node] + 1;
                    }
                }
            }
            cout << top[q] << ' ';
        }
        cout << endl;
    }
    return 0;
}
