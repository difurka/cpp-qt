
#pragma once

#include <string>
#include <optional>
#include <cmath>
#include "rational.h"
#include "pow.h"


using Error = std::string;

// Реализация шаблонного калькулятора.
#pragma once
#include <string>

// using Number = double;

template <typename Number>
class Calculator {
private:
    Number num_=0;
    std::optional<Number> memory_num_ = {};
    // bool has_memory_num_ = false;
public:
    void Set(Number n){
        num_ = n;
    }
    Number GetNumber() const {
        return num_;
    }

    std::optional<Error> Add(Number n) {
        num_+=n;
    }
    std::optional<Error> Sub(Number n) {
        num_-=n;
    }
    std::optional<Error> Div(Number n) {
        num_/=n;
    }
    std::optional<Error> Mul(Number n) {
        num_*=n;
    }
    std::optional<Error> Pow(Number n) {

        num_ = std::pow(num_, n);
    }

    void Save() {
        memory_num_ = num_;
        // has_memory_num_ = true;
    }
    void Load() {
        num_ = memory_num_;
    }
    bool HasMem() const {
        return memory_num_.has_value();
    }
    std::string GetNumberRepr() const {
        return std::to_string(num_);
    }
};
