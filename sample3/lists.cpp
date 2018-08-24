// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <map>

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
	myclass(){ std::cout << "default constructor\n"; }
	myclass(const myclass &other) { std::cout << "copy constructor\n"; }
	int x;
	other y;
	std::shared_ptr<dog> d;
};


int main()
{

	std::map<char, std::string> mymap;
    mymap.insert(std::pair<char, std::string>('a', "entry for a"));
    mymap.insert(std::pair<char, std::string>('b', "entry for b"));

    std::vector<char> myvector(mymap.size());

    for(const auto & item : mymap)
    {
        std::cout << item.second << std::endl;
    }

    std::transform(mymap.begin(), mymap.end(), myvector.begin(), [](const auto& it) -> char { return static_cast<char>(it.first); });

    for(const auto & item : myvector)
    {
        std::cout<<item<<std::endl;
    }

	std::vector<myclass> list;
	list.reserve(100);
	list.push_back(myclass());
	list.emplace_back(myclass());

	list[0].y.name = "one";
	list[1].y.name = "two";
	list[0].d = std::shared_ptr<dog>(new dog());
	list[0].d->name = "rover";

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
