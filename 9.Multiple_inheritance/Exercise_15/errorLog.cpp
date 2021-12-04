#include "errorLog.h"


std::ofstream ErrorLog::error_log_file = std::ofstream();

int ErrorLog::users_number = 0;

ErrorLog::ErrorLog(const ErrorLog&)
{
	// ErrorLog in code was created, so ErrorLog was opened
	// I no need to open and check user_number 
	++users_number;
}


ErrorLog::ErrorLog()
{

	//std::cout << "Before increment in ctr: " << users_number << std::endl;
	//users_number++;
	//std::cout << "After increment in ctr: " << users_number << std::endl;
	//std::cout << "Current users_number in ctr call: " << users_number << std::endl;
	if(users_number == 0)
	{
		error_log_file.open("ErrorLog.txt", std::ios_base::app);
		std::cout << "Opening ErrorLog.txt in ctr because users_number = " << users_number << std::endl;
	}
	++users_number;
}

ErrorLog::~ErrorLog()
{
	//std::cout << "Before decrement in dctr: " << users_number << std::endl;
	//users_number--;
	//std::cout << "After decrement in dctr: " << users_number << std::endl;
	//std::cout << "Current users_number in dctr call: " << users_number << std::endl;
	if(--users_number == 0){
		error_log_file.close();
		std::cout << "Closing ErrorLog.txt because users_number = " << users_number << std::endl;
	}
}
