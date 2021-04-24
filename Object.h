#pragma once
#include <vector>
#include <string>
#ifdef DOES_EXPORT
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif
using namespace std;
class EXPORT Object
{
public:
	Object();
	~Object();
	virtual string Name();
	vector<Object*> children;
	Object* parent;
};

