//
// Created by aheyeant on 11.03.19.
//

#ifndef ROUTING_BIGINTEGER_H
#define ROUTING_BIGINTEGER_H

#define BASE_ZERO 3

#include <vector>
#include <ostream>
#include <math.h>
#include <iomanip>

class BigInteger {
public:
    /**
     * Constructor from int.
     * @param number
     */
    explicit BigInteger(int number = 0);

    /**
     * Copy constructor.
     * @param integer
     */
    BigInteger(const BigInteger & integer, bool changeMinus = false);

    /**
     * Calculate binomial coefficient.
     * @param A
     * @param B
     * @return (A + B)! / (A! * B!)
     */
    static const BigInteger calculateC(int A, int B);

    static const BigInteger abs(const BigInteger & integer);

    BigInteger & operator=(const BigInteger & right);

    BigInteger & operator+=(const BigInteger & right);

    BigInteger & operator-=(const BigInteger & right);

    BigInteger & operator*=(const BigInteger & right);

    BigInteger & operator/=(const BigInteger & right);

    friend const BigInteger operator+(const BigInteger & integer);

    friend const BigInteger operator-(const BigInteger & integer);

    friend const BigInteger operator+(const BigInteger & left, const BigInteger & right);

    friend const BigInteger operator-(const BigInteger & left, const BigInteger & right);

    friend const BigInteger operator*(const BigInteger & left, const BigInteger & right);

    friend const BigInteger operator/(const BigInteger & left, const BigInteger & right);

    friend const bool operator< (const BigInteger & left, const BigInteger & right);

    friend const bool operator<=(const BigInteger & left, const BigInteger & right);

    friend const bool operator> (const BigInteger & left, const BigInteger & right);

    friend const bool operator>=(const BigInteger & left, const BigInteger & right);

    friend const bool operator!=(const BigInteger & left, const BigInteger & right);

    friend const bool operator==(const BigInteger & left, const BigInteger & right);

    friend std::ostream & operator<<(std::ostream & os, const BigInteger & integer);

private:
    /**
     * Digits in vector: low digit in vector[0], high digit in vector[end].
     */
    std::vector<int> _digits;
    const int base = static_cast<int>(pow(10, BASE_ZERO));
    bool _isMinus;

    void removeForwardZeros();

    bool absLess(const BigInteger & left, const BigInteger & right) const;

    bool absEquals(const BigInteger & left, const BigInteger & right) const;
};


#endif //ROUTING_BIGINTEGER_H
