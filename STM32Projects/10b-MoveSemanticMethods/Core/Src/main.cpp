#include <init.h>
#include <messageSender.h>

#include <sstream>
#include <vector>

void printRValue(int&& val)
{
	std::stringstream stream;
	stream << val << std::endl;
	messageSender::send(stream.str());
}

int sum(int a, int b)
{
    return a + b;
}

int& getElement(std::vector<int>& v, size_t index)
{
    return v[index];
}

int getFirst(std::vector<int>& v)
{
    return v[0];
}

std::vector<int> createVector()
{
    return {1, 4, 7, 2};
}

struct Construction
{

};

struct Builder
{
    Builder addSubmodule(const std::string& name)& = delete;
    Builder addSubmodule(const std::string& name)&& {
        return *this;
    }
    Construction build()&& {
        return Construction();
    }
};

int main()
{
	init();

	messageSender::send("Running 10b-MoveSemanticMethods project");

	std::vector<int>&& vec = createVector();  // r-value can be assign to l-value

	int value = getFirst(vec);

//    int&& rElement = getElement(vec, 4);    // getElement returns reference, won't compile

	getElement(vec, 4) = 2;                 // we can put it on left side

//    std::vector<int>&& rVector = vec;     // won't compile, vec is l-value

	std::vector<int>&& newVector = createVector();
//    std::vector<int>&& second = newVector;  // won't compile, newVector is r-value reference, not r-value

	int&& secondValue = getFirst(vec) + 4;  // compiles, r-value on left side
	secondValue += 5;                       // r-value reference extends life time, so we can do this


	Construction product = Builder().addSubmodule("module1").addSubmodule("module2").build();

	Builder builder;
	//product = builder.addSubmodule("module3");  // won't compile
	//product = builder.build();                  // won't compile

	return 0;
}
