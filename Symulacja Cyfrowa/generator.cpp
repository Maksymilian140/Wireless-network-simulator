#include "generator.h"
#include <cmath>

UniformGenerator::UniformGenerator(int kernel) : kernel_(kernel)
{
    // empty
}

UniformGenerator::~UniformGenerator()
{

}

double UniformGenerator::Rand()
{
    int h = kernel_ / kQ_;
    kernel_ = kA_ * (kernel_ - kQ_ * h) - kR_ * h;
    if (kernel_ < 0)
        kernel_ = kernel_ + static_cast<int>(kM_);
    return kernel_ / kM_;
}

double UniformGenerator::RangeRand(double min_value, double max_value)
{
    return (Rand() * (max_value - min_value)) + min_value;
}

double UniformGenerator::Exponential(double intensity)
{
    return -log(Rand()) / intensity;
}