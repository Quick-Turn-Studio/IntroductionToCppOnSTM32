#include <init.h>
#include <messageSender.h>

#include <sstream>

class A
{
public:
    int aMember = 0;
};

class B : private A
{
public:
    int bMember = 3;
};

class X
{
public:
    virtual ~X()
    {
    	messageSender::send(__PRETTY_FUNCTION__);
    }
    virtual void virtualFunction()
    {
        messageSender::send(__PRETTY_FUNCTION__);
    }
    void nonVirtualFunction()
    {
        messageSender::send(__PRETTY_FUNCTION__);
    }
};

class Y : public X
{
public:
    ~Y() override
    {
        messageSender::send(__PRETTY_FUNCTION__);
    }
    void virtualFunction() override
    {
        messageSender::send(__PRETTY_FUNCTION__);
    }
    void nonVirtualFunction()
    {
        messageSender::send(__PRETTY_FUNCTION__);
    }
};

int main()
{
	init();

	messageSender::send("Running 12-Polymorphism project");

    //    auto objB = new B;
    //    objB->aMember = 10; // won't compile, aMember is private in B context
    //    auto objA = static_cast<A*>(objB); // won't compile, inheritance is private

    Y* y = new Y;
    y->nonVirtualFunction();
    y->virtualFunction();

    X* x = y;
    x->nonVirtualFunction();
    x->virtualFunction();

    delete x;

	return 0;
}
