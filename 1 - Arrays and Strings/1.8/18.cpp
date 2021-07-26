#include <iostream>

void nullfirst(int matrix[100][100], int m, int n, int &col, int &row) {
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0)
            col = 1;
    }

    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0)
            row = 1;
    }
}

int main() {
    
    int m, n;
    std::cin >> m >> n;
    int matrix[100][100];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            std::cin >> matrix[i][j];

    int nulcol = 0, nulrow = 0;

    // verificam daca avem 0 pe linie sau coloana
    nullfirst(matrix, m, n, nulcol, nulrow);

    // cautam unde avem 0-uri si le salvam pe prima linie sau coloana
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }

    // nullify lines
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < n; j++)
                matrix[i][j] = 0;
        }
    }

    // nullify cols
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < m; i++)
                matrix[i][j] = 0;
        }
    }

    if (nulcol)
        for (int i = 0; i < m; i++)
            matrix[i][0] = 0;

    if (nulrow)
        for (int j = 0; j < n; j++)
            matrix[0][j] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}