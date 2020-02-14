#include <iostream>

#include "mdal_logger.hpp"

void MDAL::Logger::log( std::string test )
{
    lastLogs.push_back( test );
    std::cout << "Logged message: " << test << std::endl;
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
