#pragma once

#include "../DNX.Utils/EnumUtils.h"
#include <string>
#include <ctime>

// ReSharper disable CppInconsistentNaming
// ReSharper disable CppClangTidyClangDiagnosticHeaderHygiene

using namespace std;
using namespace DNX::Utils;
using namespace DNX::Utils::EnumUtils;

namespace Stopwatch
{
    enum class TimerStateType : uint8_t
    {
        RUNNING,
        PAUSED,
    };

    class TimerStateTypeText : public EnumTextResolver<TimerStateType>
    {
    public:
        TimerStateTypeText()
        {
            SetText(TimerStateType::RUNNING, "Running");
            SetText(TimerStateType::PAUSED, "Paused");
        }
    };

    class Timer
    {
        string m_Name;
        time_t m_Start;
        TimerStateType m_State;
        double m_TotalElapsed;

    public:
        Timer() = default;
        explicit Timer(const string& name);

        [[nodiscard]] string GetName() const;
        [[nodiscard]] time_t GetStart() const;
        [[nodiscard]] TimerStateType GetState() const;
        [[nodiscard]] double GetTotalElapsed() const;

        [[nodiscard]] double GetCurrentElapsed() const;
        [[nodiscard]] double GetAccumulatedElapsed() const;
        tm GetStartDateTime() const;

        void Start();
        void Stop();

        [[nodiscard]] bool IsEmpty() const;

        static Timer Create(const string& definition);

        [[nodiscard]] string ToDefinition() const;
        void FromDefinition(const string& definition);
    };
}
