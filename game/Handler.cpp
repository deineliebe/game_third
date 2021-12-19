#include "Handler.h"

Handler* AbstractHandler::setNext(Handler* handler) {
    this->_nextHandler = handler;
    return handler;
}

std::string AbstractHandler::handle(std::string request)
{
    if (this->_nextHandler) return this->_nextHandler->handle(request);
    return {};
}

std::string CheckFieldNumberHandler::handle(int number)
{
    if (number >= 3)
    {
        return " ";
    }
}