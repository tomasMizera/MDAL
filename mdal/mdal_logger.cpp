#include <iostream>

#include "mdal_logger.hpp"

void MDAL::Logger::log(MDAL_Status status, std::string message, std::string driverName, bool firstLog)
{
  if (firstLog) clearLogs();

  lastLogs.push_back(MDAL::LogEntry(status, message, driverName));
  std::cout << "Logged message: " << message << std::endl;
}

const char** MDAL::Logger::getLastLogs()
{
  // build return message from inner vector
  {}

  // clear logs array
  clearLogs();

  return nullptr;
}

void MDAL::Logger::clearLogs()
{
  lastLogs.clear();
}
