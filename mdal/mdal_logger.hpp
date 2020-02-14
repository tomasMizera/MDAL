#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

#include "mdal.h"

/**
 * Options for logger:
 */


// driver napise warning ked nedokaze nacitat a potom error ze nejde otvorit ziaden
// pridat nazov suboru do warningu

namespace MDAL {

//  struct LogEntry {
//    LogEntry( MDAL_Status s, std::string m, std::string d ) : status( s ), message( m ), driverName( d ) {}

//    MDAL_Status status;
//    std::string message;
//    std::string driverName;
//  };

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

    void setCallback( MDALLoggerCallback loggerCallback );
    void warn( std::string );
    void error( std::string );

  private:
    Logger();
    void log( MDAL_LogPriority priority, std::string message );

    MDALLoggerCallback mLoggerCallback = nullptr;
  };
}

#endif // LOGGER_HPP
