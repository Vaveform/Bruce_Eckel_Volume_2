#include <iostream>
#include <vector>
#include <functional>

class Base
{
	public:
	virtual ~Base(){}
};

class Derived : public Base
{

};


template<typename T>
class MyTemplate
{
	//T sub_obj;
};

int main()
{
	using namespace std;
	vector<Base*> vec_b_ptr;
	vector<Base> vec_b;
	vector<Derived*> vec_d_ptr;
	vector<Derived> vec_d;
	cout << "vector<Base*> typeid: " << typeid(vec_b_ptr).name() << endl;
	cout << "vector<Base> typeid: " << typeid(vec_b).name() << endl;
	cout << "vector<Derived*> typeid: " << typeid(vec_d_ptr).name() << endl;
	cout << "vector<Derived> typeid: " << typeid(vec_d).name() << endl;

	vector<vector<Base*>> vec_vec_b_ptr;
	vector<vector<Base>> vec_vec_b;
	vector<vector<Derived*>> vec_vec_d_ptr;
	vector<vector<Derived>> vec_vec_d;
	cout << "vector<vector<Base*>> typeid: " << typeid(vec_vec_b_ptr).name() << endl;
	cout << "vector<vector<Base>> typeid: " << typeid(vec_vec_b).name() << endl;
	cout << "vector<vector<Derived*>> typeid: " << typeid(vec_vec_d_ptr).name() << endl;
	cout << "vector<vector<Derived>> typeid: " << typeid(vec_vec_d).name() << endl;


	vector<MyTemplate<Base*>> vec_my_template_b_ptr;
	vector<MyTemplate<Base>> vec_my_template_b;
	vector<MyTemplate<Derived*>> vec_my_template_d_ptr;
	vector<MyTemplate<Derived>> vec_my_template_d;
	cout << "vector<MyTemplate<Base*>> typeid: " << typeid(vec_my_template_b_ptr).name() << endl;
	cout << "vector<MyTemplate<Base>> typeid: " << typeid(vec_my_template_b).name() << endl;
	cout << "vector<MyTemplate<Derived*>> typeid: " << typeid(vec_my_template_d_ptr).name() << endl;
	cout << "vector<MyTemplate<Derived>> typeid: " << typeid(vec_my_template_d).name() << endl;

	MyTemplate<Base> my_template_b;
	MyTemplate<Base*> my_template_b_ptr;
	MyTemplate<Derived> my_template_d;
	MyTemplate<Derived*> my_template_d_ptr;
	cout << "MyTemplate<Base> typeid: " << typeid(my_template_b).name() << endl;
	cout << "MyTemplate<Base*> typeid: " << typeid(my_template_b_ptr).name() << endl;
	cout << "MyTemplate<Derived> typeid: " << typeid(my_template_d).name() << endl;
	cout << "MyTemplate<Derived*> typeid: " << typeid(my_template_d_ptr).name() << endl;
	
	
	MyTemplate<MyTemplate<Base>> my_template_template_b;
	MyTemplate<MyTemplate<Base*>> my_template_template_b_ptr;
	MyTemplate<MyTemplate<Derived>> my_template_template_d;
	MyTemplate<MyTemplate<Derived*>> my_template_template_d_ptr;
	cout << "MyTemplate<MyTemplate<Base>> typeid: " << typeid(my_template_template_b).name() << endl;
	cout << "MyTemplate<MyTemplate<Base*>> typeid: " << typeid(my_template_template_b_ptr).name() << endl;
	cout << "MyTemplate<MyTemplate<Derived>> typeid: " << typeid(my_template_template_d).name() << endl;
	cout << "MyTemplate<MyTemplate<Derived*>> typeid: " << typeid(my_template_template_d_ptr).name() << endl;

	MyTemplate<MyTemplate<MyTemplate<Base>>> my_template_template_template_b;
	MyTemplate<MyTemplate<MyTemplate<Base*>>> my_template_template_template_b_ptr;
	MyTemplate<MyTemplate<MyTemplate<Derived>>> my_template_template_template_d;
	MyTemplate<MyTemplate<MyTemplate<Derived*>>> my_template_template_template_d_ptr;
	cout << "MyTemplate<MyTemplate<MyTemplate<Base>>> typeid: " << typeid(my_template_template_template_b).name() << endl;
	cout << "MyTemplate<MyTemplate<MyTemplate<Base*>>> typeid: " << typeid(my_template_template_template_b_ptr).name() << endl;
	cout << "MyTemplate<MyTemplate<MyTemplate<Derived>>> typeid: " << typeid(my_template_template_template_d).name() << endl;
	cout << "MyTemplate<MyTemplate<MyTemplate<Derived*>>> typeid: " << typeid(my_template_template_template_d_ptr).name() << endl;

	MyTemplate<MyTemplate<vector<Base>>> my_template_template_vec_b;
	MyTemplate<MyTemplate<vector<Base*>>> my_template_template_vec_b_ptr;
	MyTemplate<MyTemplate<vector<Derived>>> my_template_template_vec_d;
	MyTemplate<MyTemplate<vector<Derived*>>> my_template_template_vec_d_ptr;
	cout << "MyTemplate<MyTemplate<vector<Base>>> typeid: " << typeid(my_template_template_vec_b).name() << endl;
	cout << "MyTemplate<MyTemplate<vector<Base*>>> typeid: " << typeid(my_template_template_vec_b_ptr).name() << endl;
	cout << "MyTemplate<MyTemplate<vector<Derived>>> typeid: " << typeid(my_template_template_vec_d).name() << endl;
	cout << "MyTemplate<MyTemplate<vector<Derived*>>> typeid: " << typeid(my_template_template_vec_d_ptr).name() << endl;



	vector<vector<vector<Base*>>> vec_vec_vec_b_ptr;
	vector<vector<vector<Base>>> vec_vec_vec_b;
	vector<vector<vector<Derived*>>> vec_vec_vec_d_ptr;
	vector<vector<vector<Derived>>> vec_vec_vec_d;
	cout << "vector<vector<vector<Base*>>> typeid: " << typeid(vec_vec_vec_b_ptr).name() << endl;
	cout << "vector<vector<vector<Base>>> typeid: " << typeid(vec_vec_vec_b).name() << endl;
	cout << "vector<vector<vector<Derived*>>> typeid: " << typeid(vec_vec_vec_d_ptr).name() << endl;
	cout << "vector<vector<vector<Derived>>> typeid: " << typeid(vec_vec_vec_d).name() << endl;
	return 0;
}
