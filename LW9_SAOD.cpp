#include "PBTstruct.h"
#include <iostream>

//Построение и обход идеально сбалансированных двоичных деревьев.
//9 и 11 лр

void enteringNumber(int rangeStart, int rangeStop, int& value) {
    while (true) {
        std::cout << "Введите число от " << rangeStart << " до " << rangeStop << " >> ";
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. ";
        }
        else if (value >= rangeStart && value <= rangeStop) {
            return;
        }
        else {
            std::cout << "Некорректное число. ";
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    srand(static_cast<unsigned int>(time(0)));
    int operation{ 0 }, countNode{ 0 };

    while (true) {
        std::cout << "1. Создать ИСД и вывести его тремя способами. " << std::endl
            << "0. Завершить программу. " << std::endl;
        enteringNumber(0, 1, operation);
        if (operation == 0) {
            return 0;
        }
        else {
            std::cout << "Сколько вершин содержится в дереве >> ";
            enteringNumber(1, 100, countNode);
            RootPBT = createTree(RootPBT, countNode);
            std::cout << std::endl;
            std::cout << "ИСД в проямом порядке (9 лр) " << std::endl;
            printForward(RootPBT, 0);
            std::cout << std::endl;
            std::cout << "ИСД в симметричном порядке" << std::endl;
            std::cout << "рекурсивный выыод (9 лр)" << std::endl;
            printSymmetrical(RootPBT, 0);
            std::cout << std::endl;
            std::cout << "нерекурсивный вывод (10 лр)" << std::endl;
            printNonRecursiveSymmetrical();
            std::cout << std::endl;
            std::cout << "ИСД в обрано-симметричном порядке (9 лр)" << std::endl;
            printInverselySymmetrical(RootPBT, 0);
            std::cout << std::endl;
            deletePBT(RootPBT);
        }
    }
}

