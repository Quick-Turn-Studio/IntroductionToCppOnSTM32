#include "FunctionExamples.h"

#include <iostream>

#include <messageSender.h>

void declaredFunction();

void internalFunction()
{
    messageSender::send(__PRETTY_FUNCTION__);
}

void foo(int)
{
	messageSender::send(__PRETTY_FUNCTION__);
	messageSender::send("We call");
    declaredFunction();
    messageSender::send("We call");
    internalFunction();
}

int sum(int a, int b)
{
	messageSender::send(__PRETTY_FUNCTION__);
    return a + b;
}

int sum(int a, int b, int c)
{
    messageSender::send(__PRETTY_FUNCTION__);
    return a + b + c;
}

float sum(float a, float b)
{
	messageSender::send(__PRETTY_FUNCTION__);
    return a + b;
}

void declaredFunction()
{
	messageSender::send(__PRETTY_FUNCTION__);
}
