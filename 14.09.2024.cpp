#include <iostream>

#include <fstream>

#include <vector>

using namespace std;

// Функция для умножения матриц

void multiplyMatrices(const vector<vector<double>>& A, const vector<vector<double>>& B, vector<vector<double>>& C) {

    int rowsA = A.size();

    int colsA = A[0].size();

    int rowsB = B.size();

    int colsB = B[0].size();

    for (int i = 0; i < rowsA; ++i)

        for (int j = 0; j < colsB; ++j) {

            C[i][j] = 0; // Инициализация элемента

            for (int k = 0; k < colsA; ++k)

                C[i][j] += A[i][k] * B[k][j]; // Сложение произведений

        }

}

int main() {

    ifstream fileA("S4.txt"), fileB("SB.txt");

    ofstream fileC("Sc.txt");

    int colsA, colsB;

    fileA >> colsA; // Чтение количества столбцов матрицы A

    fileB >> colsB; // Чтение количества столбцов матрицы B

    vector<vector<double>> A; // Матрица A

    vector<vector<double>> B; // Матрица B

    // Чтение матрицы A

    while (!fileA.eof()) {

        vector<double> row(colsA);

        for (int j = 0; j < colsA; ++j)

            fileA >> row[j];

        A.push_back(row);

    }

    // Чтение матрицы B

    while (!fileB.eof()) {

        vector<double> row(colsB);

        for (int j = 0; j < colsB; ++j)

            fileB >> row[j];

        B.push_back(row);

    }

    // Проверка на возможность перемножения

    if (A[0].size() != B.size()) {

        // Если матрицы нельзя перемножать

        fileC.close();

        return 0;

    }

    vector<vector<double>> C(A.size(), vector<double>(colsB)); // Результирующая матрица

    multiplyMatrices(A, B, C); // Умножение матриц

    // Запись результата в файл

    for (const auto& row : C) {

        for (const auto& val : row)

            fileC << val << " "; // Запись элементов

        fileC << endl; // Переход на новую строку

    }

    fileA.close();

    fileB.close();

    fileC.close();

    return 0;

}

