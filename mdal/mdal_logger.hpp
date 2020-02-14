#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <vector>

#include "mdal.h"

#define FirstLog true

#define LOGGING MDAL::Logger::instance().clearLogs();

// Questions:
// - move enum MDAL_Status here or leave it in mdal.h?
// - do we need log levels?
// - how to catch new API call? -|
//                               |
//                              \ /
//                               V

/**
 * Options for logger:
 * 1 - wrap C api functions with macro,
 *  so macro would look like:
 *    a) #define LOGGING MDAL::Logger::instance().clearLogs();
 *        -> this would needed to be written in every function if one wants to use logger
 *    b) https://stackoverflow.com/questions/20639632/how-to-wrap-printf-into-a-function-or-macro
 *        https://stackoverflow.com/questions/617554/override-a-function-call-in-c/618059#618059
 *        -> LD_PRELOAD?
 * 2 - create first log with FirstLog = true
 * 3 - callbacks
 * 4 - wrap functions to try/catch blocks
 */



// driver nappise warning ked nedokaze nacitat a potom error ze nejde otvorit ziaden
// pridat nazov suboru do warningu

namespace MDAL {

  struct LogEntry {
    LogEntry( MDAL_Status s, std::string m, std::string d ) : status( s ), message( m ), driverName( d ) {}

    MDAL_Status status;
    std::string message;
    std::string driverName;
  };

  class Logger
  {

  public:
    static Logger& instance()
    {
      static Logger instance;
      return instance;
    }

    Logger( const Logger & ) = delete;
    Logger operator=( const Logger & ) = delete;

    // how to decide whether this is a first function call?
    void log( MDAL_Status status, std::string message, std::string driverName, bool firstLog = false );

    const char **getLastLogs();
    void clearLogs();

  private:
    Logger(){}
    std::vector< MDAL::LogEntry > lastLogs;
  };
}

#endif // LOGGER_HPP
