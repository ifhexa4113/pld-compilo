#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H

#include<vector>


class ErrorManager
{
public:
	enum Error {
		UNKNOWN_LVALUE_SYMBOL,
		UNKNOWN_FUNCTION_SYMBOL,
		SYMBOL_REDECLARATION,
		INAPPROPRIATE_ARGUMENTS_NUMBER
	};

	static ErrorManager& getInstance();

	void addEncounteredError(Error encounteredError, std::string errorSourceName);

	void printEncounteredErrorsNumber();

	void printEncounteredErrors();

	string getErrorsTrace();

private:
	ErrorManager();
	~ErrorManager();

	ErrorManager& operator= (const ErrorManager&) {}
	ErrorManager(const ErrorManager&) {}

	std::vector<Error> encounteredErrors;
	std::vector<std::string> errorsSourcesNames;
	std::map<Error, std::string> errorsMessage;
	std::string encounteredErrorsTrace;
};

#endif //ERROR_MANAGER_H
