#include "ArithmeticProgression.hpp"
#include <cstddef>

ArithmeticProgression::ArithmeticProgression(double first, double r, int n)
    : firstTerm(first), ratio(r), termsQuantity(n) {}

ArithmeticProgression::ArithmeticProgression(double *terms, int size) {
    firstTerm = terms[0];
    ratio = findRatioBySequencialTerms(terms);
    termsQuantity = size;
}

double ArithmeticProgression::getTerm(int n) const {
    if (n <= 0 || n > termsQuantity) {
        return -1;
    }
    return firstTerm + (n - 1) * ratio;
}

bool ArithmeticProgression::isArithmeticProgression(double *terms, int size) {
    if (size < 2) return false;
    double ratio = terms[1] - terms[0];
    for (int i = 1; i < size; ++i) {
        if (terms[i] - terms[i-1] != ratio) return false;
    }
    return true;
}

double ArithmeticProgression::findRatioByNotSequencialTwoTerms(double nFirstTerm, double firstTerm, double nSecondTerm, double secondTerm) {
    return (secondTerm - firstTerm) / (nSecondTerm - nFirstTerm);
}

double ArithmeticProgression::findFirstTermByRatioAndTerm(double ratio, double nTerm, double term) {
    return term - (nTerm - 1) * ratio;
}

double ArithmeticProgression::findRatioBySequencialTerms(double *terms) {
    return findRatioBySequencialTwoTerms(terms[0], terms[1]);
}

double ArithmeticProgression::findRatioBySequencialTwoTerms(double term1, double term2) {
    return term2 - term1;
}
