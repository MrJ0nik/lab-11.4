#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <Windows.h>

using namespace std;


double calculateArithmeticMean(const double numbers[], int size) {
    if (size == 0) return 0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum / size;
}


double calculateGeometricMean(const double numbers[], int size) {
    if (size == 0) return 0;
    double product = 1;
    for (int i = 0; i < size; i++) {
        if (numbers[i] <= 0) return 0; 
        product *= numbers[i];
    }
    return pow(product, 1.0 / size);
}


int extractNumbers(const string& line, double numbers[], int maxSize) {
    int count = 0;
    size_t pos = 0;
    while (pos < line.size() && count < maxSize) {
        while (pos < line.size() && !isdigit(line[pos]) && line[pos] != '-' && line[pos] != '.') {
            pos++;
        }
        if (pos >= line.size()) break;

        size_t endPos = pos;
        while (endPos < line.size() && (isdigit(line[endPos]) || line[endPos] == '.' || line[endPos] == '-')) {
            endPos++;
        }

        string numberStr = line.substr(pos, endPos - pos);
        try {
            numbers[count++] = stod(numberStr);
        }
        catch (...) {
            
        }
        pos = endPos;
    }
    return count;
}


void processFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }

    string line;
    const int maxNumbers = 100;
    double numbers[maxNumbers];

    while (getline(inputFile, line)) {
        int count = extractNumbers(line, numbers, maxNumbers);

        double arithmeticMean = calculateArithmeticMean(numbers, count);
        double geometricMean = calculateGeometricMean(numbers, count);


        outputFile << "Числа: ";
        for (int i = 0; i < count; i++) {
            outputFile << numbers[i] << " ";
        }
        outputFile << "| Середнє арифметичне: " << arithmeticMean
            << " | Середнє геометричне: " << geometricMean << endl;
    }

    inputFile.close();
    outputFile.close();
    cout << "Обробка завершена. Результати записані у файл " << outputFileName << endl;
}


void menu() {
    string inputFileName, outputFileName;
    cout << "Введіть ім'я вхідного файлу: ";
    cin >> inputFileName;
    cout << "Введіть ім'я вихідного файлу: ";
    cin >> outputFileName;

    processFile(inputFileName, outputFileName);
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        int choice;
        cout << "\n--- Меню ---\n";
        cout << "1. Обробити файли\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            menu();
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }

    return 0;
}
