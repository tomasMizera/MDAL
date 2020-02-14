#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <vector>


namespace MDAL {

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

    void log(std::string stuff);
    const char **getLastLogs();
    void clearLogs();

  private:
    Logger(){}
    std::vector< std::string > lastLogs;
  };
}

#endif // LOGGER_HPP
