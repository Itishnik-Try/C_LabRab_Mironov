#include <iostream>
#include <ctime>
#include <vector>

class Matrix {
private:
    int** data;
    int row;
    int col;

    void fill() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                data[i][j] = rand() % 101 - 50;
            }
        }
    }

public:
    Matrix(int m, int n) : row(m), col(n) {
        data = new int*[row];
        for (int i = 0; i < row; i++) {
            data[i] = new int[col];
        }
        srand(time(0));
        fill();
    }

    ~Matrix() {
        for (int i = 0; i < row; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void findNeg(int sum) {
        std::vector<std::pair<int, int>> result;
        int count = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (data[i][j] < 0 && (i + j) == sum) {
                    count++;
                    result.push_back({i, j});
                }
            }
        }

        std::cout << "Найдено: " << count << "\n";
        for (auto& pos : result) {
            std::cout << "[" << pos.first << "][" << pos.second << "] = " 
                      << data[pos.first][pos.second] << "\n";
        }
    }

    void print() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                std::cout << data[i][j] << "\t";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    int m, n, s;

    std::cout << "Строки: ";
    std::cin >> m;
    std::cout << "Столбцы: ";
    std::cin >> n;

    Matrix mat(m, n);
    mat.print();

    std::cout << "Сумма индексов: ";
    std::cin >> s;

    mat.findNeg(s);

    return 0;
}