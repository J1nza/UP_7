#include <iostream>
#include "Registry.hpp"
#include <string>


//Default path in registry
static const std::wstring& DefaultPath = L"Software\\MyCompany\\MyApplication";

bool IsKeyExists(const std::wstring& name);
void SaveBoolVariable(const std::wstring& VariableName, const bool VariableValue);
bool GetBoolVariable(const std::wstring& VariableName);
void SaveInt32Variable(const std::wstring& VariableName, const int VariableValue);
int GetInt32Variable(const std::wstring& VariableName);

int main()
{
    //Saving bool variable, uncomment and change bool param for test
    //SaveBoolVariable(L"BoolVariable",true);
    bool Variable = GetBoolVariable(L"BoolVariable");
    std::cout<<"Is BoolVariable exsist - " << (IsKeyExists(L"BoolVariable")? "true":"false") << "  " << (Variable ? "true" : "false")<<std::endl;

    //Saving int32 variable, unbcomment and change int32 param for test
    //SaveInt32Variable(L"Int32Variable",-100);
    long Variable1 = GetInt32Variable(L"Int32Variable");
    std::cout<<"Is Int32Variable exsisit" << (IsKeyExists(L"Int32Variable") ? "true" : "false") << " "<< Variable1<<std::endl;
}


/// <summary>
/// this function finds out if there is a variable in the registry
/// </summary>
/// <param name="name">variable name</param>
/// <returns>is variable in the registry</returns>
bool IsKeyExists(const std::wstring& name)
{
    try
    {
        auto key = Falokut::Registry::CurrentUser->Create(DefaultPath);
        return key->HasValue(name);
    }
    catch (const std::exception&)
    {
        return false;
    }
}

/// <summary>
/// Save bool variable by name
/// </summary>
/// <param name="VariableName">The name of the variable we want to save</param>
/// <param name="VariableValue">The value of the variable we want to save</param>
void SaveBoolVariable(const std::wstring& VariableName, const bool VariableValue)
{
    auto access = Falokut::Registry::DesiredAccess::Read | Falokut::Registry::DesiredAccess::Write;
    auto key = Falokut::Registry::CurrentUser->Create(DefaultPath,access);
    key->SetBoolean(VariableName, VariableValue);
}

/// <summary>
///  Return variable value from registry by name
/// </summary>
/// <param name="VariableName">The name of the variable</param>
/// <returns>Variable value if value exists otherwise false</returns>
bool GetBoolVariable(const std::wstring& VariableName)
{
    if(!IsKeyExists(VariableName))
    {
        SaveBoolVariable(VariableName, false);
        return false;
    }
    try
    {
    auto key = Falokut::Registry::CurrentUser->Create(DefaultPath);
    return key->GetBoolean(VariableName);
    }
    catch (const std::exception&)
    {
        return false;
    }
}

/// <summary>
/// Save int32 variable by name
/// </summary>
/// <param name="VariableName">The name of the variable we want to save</param>
/// <param name="VariableValue">The value of the variable we want to save</param>
void SaveInt32Variable(const std::wstring& VariableName, const int VariableValue)
{
    auto access = Falokut::Registry::DesiredAccess::Read | Falokut::Registry::DesiredAccess::Write;
    auto key = Falokut::Registry::CurrentUser->Create(DefaultPath, access);
    key->SetInt32(VariableName, VariableValue);
}
/// <summary>
///   Return variable value from registry by name, if variable doesn't excist, we create it
/// </summary>
/// <param name="VariableName"></param>
/// <returns>Variable value if value exists otherwise int()</returns>
int GetInt32Variable(const std::wstring& VariableName)
{
    if (!IsKeyExists(VariableName))
    {
        SaveInt32Variable(VariableName, int());
        return int();
    }

    try
    {
        auto key = Falokut::Registry::CurrentUser->Create(DefaultPath);
        return key->GetInt32(VariableName);
    }
    catch (const std::exception&)
    {
        return int();
    }
}
