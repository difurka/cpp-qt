<<<<<<< HEAD
#pragma once
#include <string>

using Number = double;


class Calculator {
private:
    Number num_=0;
    Number memory_num_;
    bool has_memory_num_ = false;
public:
    void Set(Number n);
    Number GetNumber() const;
    void Add(Number n);
    void Sub(Number n);
    void Div(Number n);
    void Mul(Number n);
    void Pow(Number n);
    void Save();
    void Load();
    bool HasMem() const;
    std::string GetNumberRepr() const;
};
=======
// Ваше решение задачи о калькуляторе с классом.
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
