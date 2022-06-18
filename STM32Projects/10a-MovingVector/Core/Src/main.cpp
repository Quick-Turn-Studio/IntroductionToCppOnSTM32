
#include <vector>

#include <init.h>
#include <messageSender.h>

#include <sstream>

class NumberParser
{
public:
    explicit NumberParser(const std::vector<int> vec)
            : numbers(vec)
    {

    }

    explicit NumberParser(std::vector<int>&& vec)
            : numbers(std::move(vec))
    {

    }

    int getSum();
    int getAverage();
private:
    std::vector<int> numbers;
};

void printVector(const std::vector<int>& v)  // better const reference
{                                            // we avoid copy
    for (int i = 0; i < v.size(); ++i) {
    	std::stringstream stream;
    	stream << v[i] << std::endl;
    	messageSender::send(stream.str());
    }
}

//void printVector(std::vector<int> v)
//{
//    for(int i = 0; i < v.size(); ++i)
//    {
//        std::stringstream stream;
//        stream << v[i] << std::endl;
//        messageSender::send(stream.str());
//    }
//}

class VectorInts
{
public:
    VectorInts() = default;

//    VectorInts(const VectorInts& vec);  // copy constructor
//
//    VectorInts(VectorInts&& vec);  // move constructor
//
//    VectorInts& operator = (const VectorInts& vec);  // assign operator
//    VectorInts& operator = (VectorInts&& vec);   // move operator

    VectorInts(const VectorInts& copyFrom)  // copy constructor
            : size{copyFrom.size}               // we save 'size' value
              , capacity{copyFrom.capacity}       // we save 'capacity' value
    {
        values = new int[capacity];         // why we cannot copy 'values'?
        for (int i = 0; i < size; ++i)       // we copy every element
        {
            values[i] = copyFrom.values[i];
        }
        messageSender::send(__PRETTY_FUNCTION__);
    }

    VectorInts(VectorInts&& moveFromm)  // move constructor
        : size{moveFromm.size}          // like in copy
        , capacity{moveFromm.capacity}  // like in copy
    {
        values = moveFromm.values;      // we copy raw pointer!

        moveFromm.size = 0;             // we invalidate moveFrom
        moveFromm.capacity = 0;
        moveFromm.values = nullptr;
        messageSender::send(__PRETTY_FUNCTION__);
    }

    VectorInts& operator = (const VectorInts& vec)
    {
        messageSender::send(__PRETTY_FUNCTION__);
        return *this;
    }
    VectorInts& operator = (VectorInts&& vec)
    {
        messageSender::send(__PRETTY_FUNCTION__);
        return *this;
    }

private:
    size_t size = 0;
    size_t capacity = 0;
    int* values = nullptr;
};

int main()
{
	init();

	messageSender::send("Running 10-MovingVector project");

    std::vector<int> numberVec = {5, 23, 654, 2, 78};

    printVector(numberVec);

    std::vector<int> numberVector = {5, 23, 654, 2, 78};

//    NumberParser parser(std::move(numberVector));

    //NumberParser parser01(std::vector<int>(10, 0));

    VectorInts vec0;  // default constructor
    VectorInts vec1 = vec0; // copy constructor
    VectorInts vec2 = std::move(vec1); // move constructor
    vec0 = vec2;  // assign operator
    vec2 = std::move(vec0); // move operator
    VectorInts vec3{vec2};  // copy constructor
    VectorInts vec4{VectorInts()}; // move constructor
    vec0 = VectorInts{}; // move operator
    VectorInts vec5{std::move(vec4)}; // move constructor

	return 0;
}
