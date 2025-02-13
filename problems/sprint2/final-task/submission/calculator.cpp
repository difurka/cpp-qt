#include "calculator.h"

#include <cmath>

void Calculator::Set(Number n) {
    num_ = n;
}

Number Calculator::GetNumber() const {
    return num_;
}

void Calculator::Add(Number n) {
    num_+=n;
}

void Calculator::Sub(Number n) {
    num_-=n;
}

void Calculator::Div(Number n) {
    num_/=n;
}

void Calculator::Mul(Number n) {
    num_*=n;
}

void Calculator::Pow(Number n) {
    num_ = std::pow(num_, n);
}

void Calculator::Save() {
    memory_num_ = num_;
    has_memory_num_ = true;
}

void Calculator::Load() {
    num_ = memory_num_;
}

bool Calculator::HasMem() const {
    return has_memory_num_;
}

std::string Calculator::GetNumberRepr() const {
    return std::to_string(num_);
}
