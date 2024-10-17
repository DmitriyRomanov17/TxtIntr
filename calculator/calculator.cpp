#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>

// Функция для расчета суммы
double calculateSum(const std::vector<double>& numbers) {
    return std::accumulate(numbers.begin(), numbers.end(), 0.0);
}

// Функция для расчета среднего арифметического
double calculateAverage(const std::vector<double>& numbers) {
    return calculateSum(numbers) / numbers.size();
}

// Функция для расчета медианы
double calculateMedian(std::vector<double> numbers) {
    std::sort(numbers.begin(), numbers.end());
    size_t n = numbers.size();
    if (n % 2 == 0) {
        return (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
    } else {
        return numbers[n / 2];
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv << " -o <operation> <numbers>\n";
        std::cerr << "Operation can be: sum, average, median\n";
        return 1;
    }

    std::string operation;
    std::vector<double> numbers;

    // Обработка именованных параметров
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-o" || std::string(argv[i]) == "--operation") {
            if (i + 1 < argc) {
                operation = argv[i + 1];
                i++; // Пропустить следующий аргумент, поскольку он уже обработан
            } else {
                std::cerr << "Missing operation argument\n";
                return 1;
            }
        } else {
            try {
                numbers.push_back(std::stod(argv[i]));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid number: " << argv[i] << "\n";
                return 1;
            }
        }
    }

    if (numbers.size() < 7 || numbers.size() > 9) {
        std::cerr << "The number of operands must be between 7 and 9.\n";
        return 1;
    }

    double result;
    if (operation == "sum") {
        result = calculateSum(numbers);
    } else if (operation == "average") {
        result = calculateAverage(numbers);
    } else if (operation == "median") {
        result = calculateMedian(numbers);
    } else {
        std::cerr << "Invalid operation: " << operation << "\n";
        return 1;
    }

    std::cout << "The result of the operation '" << operation << "' is: " << result << "\n";
    return 0;
}
