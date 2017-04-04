#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H

#include<vector>
#include<string>
#include<map>

class ErrorManager
{
public:
	enum Error {
		UNKNOWN_LVALUE_SYMBOL,
		UNKNOWN_FUNCTION_SYMBOL,
		SYMBOL_REDECLARATION,
		INAPPROPRIATE_ARGUMENTS_NUMBER,
		INAPPROPRIATE_VOID_TYPE,
		INAPPROPRIATE_RETURN_TYPE,
		RETURN_MISSING
	};

	static ErrorManager& getInstance();

	void addEncounteredError(Error encounteredError, std::string errorSourceName);

	void printEncounteredErrorsNumber();

	void printEncounteredErrors();

	std::string getErrorsTrace();

    ErrorManager& operator= (const ErrorManager&)   = delete;
    ErrorManager(const ErrorManager&)               = delete;

private:
	ErrorManager();
	~ErrorManager();

	std::vector<Error> encounteredErrors;
	std::vector<std::string> errorsSourcesNames;
	std::map<Error, std::string> errorsMessage;
	std::string encounteredErrorsTrace;
};

#endif //ERROR_MANAGER_H
