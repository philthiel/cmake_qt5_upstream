#include "mylib.h"


using namespace MYLIB;


MyLIB::MyLIB()
{}

MyLIB::~MyLIB()
{}

std::string MyLIB::get_string()
{
	return s_.toStdString();
}

void MyLIB::set_string(std::string s)
{
	s_ = QString::fromStdString(s);
}
