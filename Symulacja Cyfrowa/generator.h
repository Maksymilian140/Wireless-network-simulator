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
    double Range_rand(double min_value, double max_value);

    int get_kernel() { return kernel_; };
private:
    int kernel_;
    const double kM = 2147483647.0;
    static const int kA = 16807;
    static const int kQ = 127773;
    static const int kR = 2836;
};


#endif /* RANDOM_GENERATOR_H_ */