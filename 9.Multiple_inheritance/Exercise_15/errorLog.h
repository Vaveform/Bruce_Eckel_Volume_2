#ifndef ERROR_LOG_H
#define ERROR_LOG_H

#include <fstream>
#include <iostream>

class ErrorLog
{
	private:
		static std::ofstream error_log_file;
		static int users_number;
	protected:
		ErrorLog();
		ErrorLog(const ErrorLog&);
		// For object if used move-semantics
		//ErrorLog(ErrorLog&&);
	public:
		virtual ~ErrorLog();

		template<typename T>
		ErrorLog& toErrorLog(const T& object);
};


template<typename T>
ErrorLog& ErrorLog::toErrorLog(const T& object)
{
	//std::cout << "Writing to log" << std::endl;
	error_log_file << object;
	return *this;
}


#endif
