#include <iostream>
#include <sstream>
#include "ErrorManager.h"

ErrorManager::ErrorManager() :
    encounteredErrors(), errorsSourcesNames(),
    errorsMessage(), encounteredErrorsTrace("")
{
    errorsMessage.insert(std::make_pair(UNKNOWN_LVALUE_SYMBOL, "Error: use of unknown symbol "));
    errorsMessage.insert(std::make_pair(UNKNOWN_FUNCTION_SYMBOL, "Error: use of unknown symbol "));
    errorsMessage.insert(std::make_pair(SYMBOL_REDECLARATION, "Error : redeclaration of symbol "));
    errorsMessage.insert(std::make_pair(INAPPROPRIATE_ARGUMENTS_NUMBER, "Error : inappropriate number of arguments for function call "));
	errorsMessage.insert(std::make_pair(INAPPROPRIATE_VOID_TYPE, "Error : inappropriate type used (void)"));
	errorsMessage.insert(std::make_pair(INAPPROPRIATE_RETURN_TYPE, "Error : inappropriate return type"));
	errorsMessage.insert(std::make_pair(RETURN_MISSING, "Error : return missing"));
}

ErrorManager::~ErrorManager()
{

}

ErrorManager& ErrorManager::getInstance()
{
	static ErrorManager instance;
	return instance;
}

void ErrorManager::addEncounteredError(Error encounteredError, std::string errorSourceName)
{
	encounteredErrors.push_back(encounteredError);
	errorsSourcesNames.push_back(errorSourceName);
    std::stringstream ss;
    ss << encounteredErrorsTrace << static_cast<int>(encounteredError);
	encounteredErrorsTrace = ss.str();
}

void ErrorManager::printEncounteredErrorsNumber()
{
	std::cerr << encounteredErrors.size() << " errors encountered." << std::endl;
}

void ErrorManager::printEncounteredErrors()
{
	Error encounteredError;
	for (unsigned int i = 0; i < encounteredErrors.size(); i++) {
		encounteredError = encounteredErrors[i];
		std::cerr << errorsMessage.find(encounteredError)->second << errorsSourcesNames[i] << "." << std::endl;
	}
}

std::string ErrorManager::getErrorsTrace()
{
	return encounteredErrorsTrace;
}

std::vector<ErrorManager::Error> ErrorManager::getEncounteredErrors()
{
    return encounteredErrors;
}