#pragma once
#include <vector>
#include <string>
using namespace std;
class Object
{
public:
	Object();
	~Object();
	string Name();
	vector<Object*> children;
	Object* parent;
};

