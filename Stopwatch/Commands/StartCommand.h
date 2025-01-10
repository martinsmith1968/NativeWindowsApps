#pragma once

#include "../stdafx.h"
#include "BaseCommand.h"
#include <string>
#include <iostream>

// ReSharper disable CppInconsistentNaming
// ReSharper disable CppClangTidyModernizeUseEqualsDefault
// ReSharper disable CppClangTidyClangDiagnosticHeaderHygiene
// ReSharper disable CppClangTidyPerformanceAvoidEndl
// ReSharper disable CppClangTidyCppcoreguidelinesAvoidConstOrRefDataMembers

using namespace std;

namespace Stopwatch
{
    class StartArguments final : public BaseArguments
    {

    public:
        StartArguments()
        {
            AddParameterStopwatchName();
            AddSwitchVerboseOutput(true);
        }
    };

    class StartCommand final : public BaseCommand
    {
        const string START_TIME_DISPLAY_FORMAT = "%H:%M:%S";

        StartArguments m_arguments;

    public:
        StartCommand()
            : BaseCommand(&m_arguments, CommandType::START, "Start a named Stopwatch", 20)
        { }

        void Execute() override
        {
            const auto stopwatch_name = m_arguments.GetStopwatchName();
            auto repository = TimerRepository(m_arguments.GetDataFileName());

            auto timer = repository.GetByName(stopwatch_name);
            if (!timer.IsEmpty())
                AbortAlreadyExists(stopwatch_name);

            timer = Timer(stopwatch_name);
            timer.Start();

            if (m_arguments.GetVerboseOutput())
                cout << GetTimerStatusDisplayText(timer, "started at " + TimerDisplayBuilder::GetFormattedStartTime(timer.GetStartDateTime(), START_TIME_DISPLAY_FORMAT)) << endl;

            repository.Add(timer);
        }
    };
}
