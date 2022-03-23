#include "Logger.h"
#include <iostream>
#include <ctime>
#include <vector>

std::vector<LogEntry> Logger::messages;

std::string timeToString() {
	time_t t;
	time(&t);
	std::string timeString = ctime(&t);
	timeString.pop_back(); /* Remove trailing newline */
	return timeString;
}

void colorOutputGreen(const std::string &input) {
	std::cout << "\x1B[32m" << input << "\033[0m" << std::endl;
}

void colorOutputRed(const std::string &input) {
	std::cout << "\x1B[91m" << input << "\033[0m" << std::endl;
}

void Logger::Log(const std::string &message) {
	LogEntry logEntry; /* Creating a new LogEntry*/
	logEntry.type = LOG_INFO; /* Populating type field */
	logEntry.message = "LOG: [" + timeToString() + "] -" + message; /* Populating message field */
	colorOutputGreen(message); /* Outputting */
	messages.push_back(logEntry); /* Saving message entry on vector */
}

void Logger::Err(const std::string &message) {
	LogEntry logEntry;
	logEntry.type = LOG_ERROR;
	logEntry.message = "ERROR: [" + timeToString() + "] -" + message;
	colorOutputRed(message);
	messages.push_back(logEntry);
}
