#pragma once

#include "pch.h"
#include "../DNX.App/Arguments.h"
#include "../DNX.App/Commands.h"
#include "../DNX.Utils/StringUtils.h"

// ReSharper disable CppInconsistentNaming
// ReSharper disable CppClangTidyModernizeUseEqualsDefault
// ReSharper disable StringLiteralTypo

using namespace std;
using namespace DNX::App;

class AppArgumentsC1 final : public Arguments
{
public:
    AppArgumentsC1()
    {
        AddParameter(ValueType::STRING, 1, "item-name", "", "The name of the item", true);
        AddSwitch("v", "vflag", StringUtils::BoolToString(false), "v flag", false, 0);
    }

    string GetItemName() { return GetArgumentValue("item-name"); }
    bool GetFlagV() { return GetSwitchValue("vflag"); }
};

class AppArgumentsC2 final : public Arguments
{
public:
    AppArgumentsC2()
    {
        AddSwitch("w", "wflag", StringUtils::BoolToString(false), "w flag", false, 0);
    }

    bool GetFlagW() { return GetSwitchValue("wflag"); }
};

class AppArgumentsC3 final : public Arguments
{
public:
    AppArgumentsC3()
    {
        AddSwitch("x", "xflag", StringUtils::BoolToString(false), "x flag", false, 0);
    }

    bool GetFlagX() { return GetSwitchValue("xflag"); }
};

class AppCommandC1 final : public Command
{
    AppArgumentsC1 m_arguments;
public:
    AppCommandC1() : Command(&m_arguments, "c1", "Command 1") {}
    void Execute() override {}
};

class AppCommandC2 final : public Command
{
    AppArgumentsC2 m_arguments;
public:
    AppCommandC2() : Command(&m_arguments, "c2", "Command 2") {}
    void Execute() override {}
};

class AppCommandC3 final : public Command
{
    AppArgumentsC3 m_arguments;
public:
    AppCommandC3() : Command(&m_arguments, "c3", "Command 3") {}
    void Execute() override {}
};

class Commands1 final : public Commands
{
    AppCommandC1 _command_c1;
    AppCommandC2 _command_c2;
    AppCommandC3 _command_c3;

public:
    Commands1()
    {
        AddCommand(_command_c1);
        AddCommand(_command_c2);
        AddCommand(_command_c3);
    }
};
