#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

#include "mdal.h"

// driver napise warning ked nedokaze nacitat a potom error ze nejde otvorit ziaden
// pridat nazov suboru do warningu

namespace MDAL {

/*  struct MDAL_Error {
    MDAL_Error( MDAL_Status st, std::string mssg ): errCode( st ), errMessage( mssg ) {}

    MDAL_Status errCode;
    std::string errMessage;
  };*/

  namespace Logge {
    //set last status
    //set callback


    // Idealne: nechat API tak ako bolo + pridat callback
    // podla env variable bud vypisovat alebo nie

    void _handleLog( MDAL_LogPriority prio, MDAL_Status statusCode, std::string mssg )
    {
      switch ( prio ) {
        case ERR:
          MDAL::Logger::instance().error( statusCode, mssg );
          sLastStatus = statusCode;
          break;

        case WARN:
          MDAL::Logger::instance().warn( mssg );
          break;
      }
    }

  }
  class Logger
  {

  public:
    static Logger& instance()
    {
      static Logger instance;
//      if ( clearLastError ) instance.sLastError = MDAL_Error( MDAL_Status::None, "" );
      return instance;
    }

    Logger( const Logger & ) = delete;
    Logger operator=( const Logger & ) = delete;

    void setCallback( MDALLoggerCallback loggerCallback );
    void warn( std::string mssg );
    void error( MDAL_Status status, std::string mssg );


  private:
    Logger();
    void log( MDAL_LogPriority priority, std::string message );
//    MDAL_Error sLastError;

    MDALLoggerCallback mLoggerCallback = nullptr;
  };
}

#endif // LOGGER_HPP
