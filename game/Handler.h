#include <string>;

//Class for pattern "Chain of responsibility"
class Handler
{
public:
	virtual Handler* setNext(Handler* handler) = 0;
	virtual std::string handle(std::string request) = 0;
	virtual std::string handle(int number) = 0;
};

class AbstractHandler : public Handler
{
private:
	Handler* _nextHandler;
public:
	AbstractHandler() :_nextHandler(nullptr) {};
	Handler* setNext(Handler* handler) override;
	std::string handle(std::string request);
	std::string handle(int number);
};

class CheckFieldNumberHandler: public AbstractHandler
{
public:
	std::string handle(int number);
};