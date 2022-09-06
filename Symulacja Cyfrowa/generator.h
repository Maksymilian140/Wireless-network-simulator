#ifndef RANDOM_GENERATOR_H_
#define RANDOM_GENERATOR_H_

#include <string>

class UniformGenerator
{
public:
    UniformGenerator(int kernel);
    virtual ~UniformGenerator();

    // Draws number between <0,1>
    double Rand();
    // Draws number with exponential distribution with a specified intensity
    double Exponential(double intensity);
    // Draws number between min_value and max_value with uniform distribution
    double RangeRand(double min_value, double max_value);

    int GetKernel() { return kernel_; };
private:
    int kernel_;
    const double kM_ = 2147483647.0;
    static const int kA_ = 16807;
    static const int kQ_ = 127773;
    static const int kR_ = 2836;
};


#endif /* RANDOM_GENERATOR_H_ */