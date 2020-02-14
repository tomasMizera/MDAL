#include "mdal_logger.hpp"

void _standardStdout( MDAL_LogPriority prio, const char* mssg )
{
  switch ( prio )
  {
    case WARN:
      std::cout << "WARNING: " << mssg << std::endl;
    case ERR:
      std::cerr << "ERROR: " << mssg << std::endl;
  }
}

void MDAL::Logger::setCallback( MDALLoggerCallback loggerCallback )
{
  mLoggerCallback = loggerCallback;
}

void MDAL::Logger::warn( std::string mssg )
{
  log( MDAL_LogPriority::WARN, mssg );
}

void MDAL::Logger::error( std::string mssg )
{
  log( MDAL_LogPriority::ERR, mssg );
}

MDAL::Logger::Logger()
{
  setCallback( &_standardStdout );
}

void MDAL::Logger::log(MDAL_LogPriority priority, std::string mssg)
{
  mLoggerCallback( priority, mssg.c_str() );
}
