// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class dog
{
public:
	std::string name;

};

class other
{
public:
	std::string name;

};

class myclass
{
public:
	myclass(){ std::cout << "hello\n"; }
	myclass(const myclass &other) { std::cout << "copy\n"; }
	int x;
	other y;
	std::shared_ptr<dog> d;
};


int main()
{


	std::vector<myclass> list;
	list.reserve(100);
	list.push_back(myclass());
	std::cout << "1\n";
	list.emplace_back(myclass());
	std::cout << "2\n";
	std::cout << "ok\n";
	list[0].y.name = "one";
	list[1].y.name = "two";
	list[0].d = std::shared_ptr<dog>(new dog());
	list[0].d = std::shared_ptr<dog>(new dog());
	list[0].d->name = "rover";
	list[1].d = std::make_shared<dog>();
	list[1].d = std::make_shared<dog>();
	list[1].d->name = "rex";
	std::vector<myclass> otherlist(list.size());
	std::copy(list.begin(), list.end(), otherlist.begin());
	list.clear();
	for (const auto & item : otherlist)
	{
		std::cout << item.y.name << " " << item.d->name << "\n";
	}

}
