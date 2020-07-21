#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include <memory>
#include <vector>
class Object;
class ObjectFactory {
public:
	virtual std::unique_ptr<Object> create(std::vector<std::unique_ptr<Object>>& objects) = 0;
};

#endif