#include <iostream>
#include "ErrorManager.h"

ErrorManager::ErrorManager() :
    encounteredErrors(), errorsSourcesNames(),
    errorsMessage(), encounteredErrorsTrace("")
{
	std::cout << "ErrorManager creation" << std::endl; // TODO remove
    errorsMessage.insert(std::make_pair(UNKNOWN_LVALUE_SYMBOL, "Error: use of unknown symbol "));
    errorsMessage.insert(std::make_pair(UNKNOWN_FUNCTION_SYMBOL, "Error: use of unknown symbol "));
    errorsMessage.insert(std::make_pair(SYMBOL_REDECLARATION, "Error : redeclaration of symbol "));
    errorsMessage.insert(std::make_pair(INAPPROPRIATE_ARGUMENTS_NUMBER, "Error : inappropriate number of arguments for function call "));
}

ErrorManager::~ErrorManager()
{
	std::cout << "ErrorManager destruction" << std::endl;
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
	encounteredErrorsTrace += std::to_string(static_cast<int>(encounteredError));
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