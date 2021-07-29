//============================================================================
// Name        : LOG.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "test_runner.h"
#include <sstream>
#include <string>
using namespace std;

class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file= value; }

  bool getLogLine(){return log_line;}
  bool getLogFile(){return log_file;}

  void Log(const string& message){os << message;}

private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
};

#define LOG(logger, message){			\
		ostringstream os;				\
		if(logger.getLogFile()){		\
		os << __FILE__;					\
			if(logger.getLogLine()){	\
				os << ':' << __LINE__;	\
			}							\
		}								\
		else if(logger.getLogLine()){	\
			os << "Line " << __LINE__;	\
		}								\
	if (!os.str().empty()) os << " ";   \
		os << message << "\n";			\
		logger.Log(os.str());           \
}

