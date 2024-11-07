#pragma once
#include <cstdint>
#include <vector>
#include <numbers>
#include <cassert>
<<<<<<< HEAD
#include <algorithm>
#include <cmath>
=======
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))

enum class SignalType {
    kSin,
    kCos,
    kMeander
};

struct SignalData {
    SignalType signal_type; // Тип сигнала.
    int samples;            // Длина сигнала.
    int wave_length;        // Длина волны.
    int16_t amplitude;      // Максимальное значение.
    double cycle;           // Скважность меандра.
};

inline void ReplicateSignal(std::vector<int16_t>& signal, size_t desired_length) {
    assert(signal.size() > 0);
    // Код этой функции можете взять из урока.
<<<<<<< HEAD
    size_t wave_length = signal.size();
    while (signal.size() < desired_length) {
        size_t max_insert = desired_length - signal.size();
        size_t to_insert = std::min(wave_length, max_insert);

        // В цикле будем добавлять по 200 элементов.
        std::copy_n(signal.begin(), to_insert, std::back_inserter(signal));
    }
}

inline std::vector<int16_t> GenerateSignal(SignalData data) {
    std::vector<int16_t> signal;
    signal.reserve(data.samples);
    switch (data.signal_type) {
    case (SignalType::kSin) : {
        auto generator = [=, i = 0]() mutable  {
            return data.amplitude * std::sin(i++ * 2 * std::numbers::pi / data.wave_length);
        };
        std::generate_n(std::back_inserter(signal), data.wave_length, generator);
        break;
    }
    case (SignalType::kCos) : {
        auto generator = [=, i = 0]() mutable  {
            return data.amplitude * cos(i++ * 2 * std::numbers::pi / data.wave_length);
        };
        std::generate_n(std::back_inserter(signal), data.wave_length, generator);
        break;
    }
    case (SignalType::kMeander) : {
        int impuls = data.cycle * data.wave_length;
        std::fill_n(std::back_inserter(signal), impuls, data.amplitude);
        std::fill_n(std::back_inserter(signal),data.wave_length - impuls, -data.amplitude);
        break;
    }

    }
    ReplicateSignal(signal, data.samples);
    return signal;


=======
}

inline std::vector<int16_t> GenerateSignal(SignalData data) {
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))
    // Создайте сигнал, имеющий нужные параметры.
    // Формула синусоидального сигнала: 
    // data.amplitude * sin(i * 2 * std::numbers::pi / data.wave_length).
    //
    // Формула косинусоидального сигнала: 
    // data.amplitude * cos(i * 2 * std::numbers::pi / data.wave_length).
    //
    // Меандр создайте через std::fill_n.
    // Количество положительных отсчётов для меандра можно вычислть как
    // static_cast<int>(data.cycle * data.wave_length).
}

inline void ApplyDecayAndAttack(std::vector<int16_t>& signal, 
                                size_t max_length) {
<<<<<<< HEAD
    // Примените затухание и атаку сигнала.
=======
    // Примените атаку и затухание сигнала.
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))
    // Используйте принцип, данный в уроке.
    // Затухание применяется к концу сигнала, а 
    // атака симметрично - к началу.
    // Используйте алгоритм transform.
<<<<<<< HEAD

    size_t decay_length = std::min(signal.size(), max_length);

    auto transformer_dec = [=, i = decay_length](int16_t source) mutable {
        double factor = double(i--) / decay_length;
        return static_cast<int16_t>(source * factor);
    };

    auto start_pos = signal.end() - decay_length;
    std::transform(start_pos, signal.end(), start_pos, transformer_dec);

    auto transformer_att = [=, i = 0](int16_t source) mutable {
        double factor = double(i++) / decay_length;
        return static_cast<int16_t>(source * factor);
    };

    auto finish_pos = signal.begin() + decay_length;
    std::transform(signal.begin(), finish_pos, signal.begin(), transformer_att);

=======
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))
}
