#include <iostream>
#include "ErrorManager.h"


ErrorManager::ErrorManager()
{
	std::cout << "ErrorManager creation" << std::endl;
	errorsMessage.insert(UNKNOWN_LVALUE_SYMBOL, "Error: use of unknown symbol ");
	errorsMessage.insert(UNKNOWN_FUNCTION_SYMBOL, "Error: use of unknown symbol ");
	errorsMessage.insert(SYMBOL_REDECLARATION, "Error : redeclaration of symbol ");
	errorsMessage.insert(INAPPROPRIATE_ARGUMENTS_NUMBER, "Error : inappropriate number of arguments for function call ");
	encounteredErrorsTrace = "";
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
	encounteredErrorsTrace += static_cast<int>(encounteredError);
}

void ErrorManager::printEncounteredErrorsNumber()
{
	std::cerr << encounteredErrors.size() << " errors encountered." << std::endl;
}

void ErrorManager::printEncounteredErrors()
{
	Error encounteredError;
	for (int i = 0; i < encounteredErrors.size(); i++) {
		encounteredError = encounteredErrors[i];
		std::cerr << errorsMessage.find(encounteredError) << errorsSourcesNames[i] << "." << std::endl;
	}
}

string ErrorManager::getErrorsTrace()
{
	return encounteredErrorsTrace;
}