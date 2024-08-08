#ifndef ARITHMETIC_PROGRESSION_HPP
#define ARITHMETIC_PROGRESSION_HPP

class ArithmeticProgression {
private:
    double firstTerm;
    double ratio;
    int termsQuantity;

public:
    ArithmeticProgression(double first, double r, int n);
    ArithmeticProgression(double *terms, int size);
    double getTerm(int n) const;

    static bool isArithmeticProgression(double *terms, int size);
    static double findRatioByNotSequencialTwoTerms(double nFirstTerm, double firstTerm, double nSecondTerm, double secondTerm);
    static double findFirstTermByRatioAndTerm(double ratio, double nTerm, double term);
    static double findRatioBySequencialTerms(double *terms);
    static double findRatioBySequencialTwoTerms(double term1, double term2);
};

#endif // ARITHMETIC_PROGRESSION_HPP
