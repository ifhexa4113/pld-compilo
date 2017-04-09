#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H

#include<vector>
#include<string>
#include<map>

class ErrorManager
{
public:
    // Error enum
	enum Error {
		UNKNOWN_LVALUE_SYMBOL,
		UNKNOWN_FUNCTION_SYMBOL,
		SYMBOL_REDECLARATION,
		INAPPROPRIATE_ARGUMENTS_NUMBER,
		INAPPROPRIATE_VOID_TYPE,
		INAPPROPRIATE_RETURN_TYPE,
		RETURN_MISSING
	};

    // Singleton pattern
	static ErrorManager& getInstance();
    ErrorManager& operator= (const ErrorManager&)   = delete;
    ErrorManager(const ErrorManager&)               = delete;

    // Getters
    std::string getErrorsTrace();
    std::vector<Error> getEncounteredErrors();

    // Others
	bool checkEncouteredError();
	void addEncounteredError(Error encounteredError, std::string errorSourceName);
	void printEncounteredErrorsNumber();
	void printEncounteredErrors();

private:
	ErrorManager();
	~ErrorManager();

	std::vector<Error> encounteredErrors;
	std::vector<std::string> errorsSourcesNames;
	std::map<Error, std::string> errorsMessage;
	std::string encounteredErrorsTrace;
};

#endif //ERROR_MANAGER_H
