#pragma once
#include <vector>
using namespace std;
class Object
{
public:
	Object();
	~Object();
	vector<Object*> children;
	Object* parent;
};

