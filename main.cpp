#include "ArithmeticProgression.hpp"
#include <iostream>
#include <vector>

void printMenu() {
    std::cout << "Arithmetic Progression Helper" << std::endl;
    std::cout << "1. Check if a sequence is an Arithmetic Progression" << std::endl;
    std::cout << "2. Calculate a specific term in the Arithmetic Progression" << std::endl;
    std::cout << "3. Calculate the first term using ratio and a specific term" << std::endl;
    std::cout << "4. Calculate the ratio with two non-sequential terms" << std::endl;
    std::cout << "5. Find the ratio using sequential terms" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int size;
                std::cout << "Enter the number of terms: ";
                std::cin >> size;

                std::vector<double> terms(size);
                for (int i = 0; i < size; ++i) {
					std::cout << "Enter the " << i+1 << " term: ";
					std::cin >> terms[i];
				}

                bool result = ArithmeticProgression::isArithmeticProgression(terms.data(), size);
                std::cout << "The sequence is " << (result ? "an Arithmetic Progression." : "not an Arithmetic Progression.") << std::endl;
                break;
            }
            case 2: {
                double firstTerm, ratio;
                int termsQuantity, termIndex;

                std::cout << "Enter the first term: ";
                std::cin >> firstTerm;
                std::cout << "Enter the ratio: ";
                std::cin >> ratio;
                std::cout << "Enter the total number of terms: ";
                std::cin >> termsQuantity;
                std::cout << "Enter the term index to find: ";
                std::cin >> termIndex;

                ArithmeticProgression ap(firstTerm, ratio, termsQuantity);
                double term = ap.getTerm(termIndex);
                if (term != -1) {
                    std::cout << "The term at index " << termIndex << " is: " << term << std::endl;
                } else {
                    std::cout << "Invalid term index." << std::endl;
                }
                break;
            }
            case 3: {
                double ratio, term;
                int nTerm;

                std::cout << "Enter the ratio: ";
                std::cin >> ratio;
                std::cout << "Enter the term index: ";
                std::cin >> nTerm;
                std::cout << "Enter the term value: ";
                std::cin >> term;

                double firstTerm = ArithmeticProgression::findFirstTermByRatioAndTerm(ratio, nTerm, term);
                std::cout << "The first term is: " << firstTerm << std::endl;
                break;
            }
            case 4: {
                double nFirstTerm, firstTerm, nSecondTerm, secondTerm;

                std::cout << "Enter the index of the first term: ";
                std::cin >> nFirstTerm;
                std::cout << "Enter the value of the first term: ";
                std::cin >> firstTerm;
                std::cout << "Enter the index of the second term: ";
                std::cin >> nSecondTerm;
                std::cout << "Enter the value of the second term: ";
                std::cin >> secondTerm;

                double ratio = ArithmeticProgression::findRatioByNotSequencialTwoTerms(nFirstTerm, firstTerm, nSecondTerm, secondTerm);
                std::cout << "The ratio is: " << ratio << std::endl;
                break;
            }
            case 5: {
                double term1, term2;

                std::cout << "Enter the first term: ";
                std::cin >> term1;
                std::cout << "Enter the second term: ";
                std::cin >> term2;

                double ratio = ArithmeticProgression::findRatioBySequencialTwoTerms(term1, term2);
                std::cout << "The ratio is: " << ratio << std::endl;
                break;
            }
            case 6:
                running = false;
                break;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
                break;
        }
    }

    return 0;
}
