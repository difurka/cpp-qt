#pragma once

#include <string>
#include <optional>
#include <cmath>
#include "rational.h"
#include "pow.h"

using Error = std::string;

template <typename Number>
class Calculator {
 private:
    Number num_=0;
    std::optional<Number> memory_num_ = {};
 public:
    void Set(Number n){
        num_ = n;
    }

    Number GetNumber() const {
        return num_;
    }

    std::optional<Error> Add(Number n) {
        num_+=n;
        return std::nullopt;
    }

    std::optional<Error> Sub(Number n) {
        num_-=n;
        return std::nullopt;
    }

    std::optional<Error> Div(Number n) {
        if  constexpr (std::is_same_v<Number, Rational>
                      || std::is_integral_v<Number>) {
            if (n == 0) {
                return "Division by zero";
            }
        }
        num_/=n;
        return std::nullopt;
    }

    std::optional<Error> Mul(Number n) {
        num_*=n;
        return std::nullopt;
    }


    std::optional<Error> Pow(Number n) {
        if  constexpr (std::is_same_v<Number, Rational>
                      || std::is_integral_v<Number>) {
            if (n == 0 && num_ == 0) {
                return "Zero power to zero";
            }
        }

        if  constexpr (std::is_same_v<Number, Rational>) {
            if (n.GetDenominator() != 1) {
                return "Fractional power is not supported";
            }
        }

        if  constexpr (std::is_integral_v<Number>) {
            if (n < 0) {
                return "Integer negative power";
            }
        }

        if  constexpr (std::is_same_v<Number, Rational>) {
            num_ = ::Pow(num_, n);
        } if  constexpr (std::is_integral_v<Number>) {
            num_ = IntegerPow<Number>(num_ , n);
        } else if constexpr (!std::is_integral_v<Number> && !std::is_same_v<Number, Rational>){
            num_ = std::pow(num_, n);
        }
        return std::nullopt;
    }

    void Save() {
        memory_num_ = num_;
    }

    void Load() {
        num_ = memory_num_.value();
    }

    bool HasMem() const {
        return memory_num_.has_value();
    }

    std::optional<Number> GetHasMem() const {
        return memory_num_;
    }

    std::string GetNumberRepr() const {
        return std::to_string(num_);
    }
};
