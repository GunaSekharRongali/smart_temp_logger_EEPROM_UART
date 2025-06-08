#ifndef LOGGER_HPP
#define LOGGER_HPP
class Logger {
private:
    unsigned int logAddress;
public:
    Logger() : logAddress(0) {}
    void printTemp();
    void logTemp();
    void readLogs();
    void clearLogs();
};
#endif