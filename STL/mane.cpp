#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<forward_list>
#include<list>
//using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

#define STL_ARRAY
#define STL_VECTOR
#define STL_DEQUE
#define FORWARD_LIST


template<typename T>void print(const std::vector<T>& vec)
{
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	std::array<int, 5>arr = { 3,5,8,13,21 };
	for(int i = 0; i < arr.size();i++ )
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY


#ifdef STL_VECTOR
	//vector- ??? ???????????????? ?????????? ??????? ?????? ?????? ? ???? ????????????? ???????
	std::vector<int> vec = {0,1,1,2,3,5,8,13,21,34,55,89,144,232};
	cout << "Size:      " << vec.size() << endl;
	cout << "Capacity:  " << vec.capacity() << endl;//???? ?????? ? ???????
	cout << "MaxSize:   " << vec.max_size() << endl;
	cout << sizeof(vec) << endl;

	int* data = vec.data();
	vec.push_back(55);
	data = vec.data();
	vec.push_back(89);
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
			//cout << *(data + i) << tab;
		}
		cout << endl;
		//subscript - ??????????????
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	cout << "Size:      " << vec.size() << endl;
	cout << "Capacity:  " << vec.capacity() << endl;//???? ?????? ? ???????
	cout << "MaxSize:   " << vec.max_size() << endl;
	cout << sizeof(vec) << endl;


	int index;
	int value;
	int count;
	cout << "??????? ?????? ???????????? ????????: "; cin >> index;
	cout << "??????? ?????????? ??????????: "; cin >> count; 
	cout << "??????? ???????? ???????????? ????????: "; cin >> value;
	//insert(position, count, value)
	if (index < vec.size())vec.insert(vec.begin() + index, count, value);
	else cout << "ERROR 404" << endl;
	print(vec);

	std::vector<int> powers = { 1024, 2048, 4096, 8192, 16384 };

	/*vec.insert(vec.begin() + 4, powers.begin(), powers.end());*/
	vec.insert(vec.begin() + 8, { 256,384,512,768 });
	for (int i : vec)cout << i << tab; cout << endl;
	//vec.insert(vec.begin() + 4, vec.begin()+15, vec.begin()+16);
	//for (int i : vec)cout << i << tab; cout << endl;

	cout << "??????? ?????? ?????????? ????????: "; cin >> index;
	cout << "??????? ?????????? ????????: "; cin >> count;
	vec.erase(vec.begin() + index, vec.begin()+index+count);
	print(vec);


	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	vec.swap(powers);
	print(vec);
	print(powers);
#endif // STL_VECTOR

#ifdef STL_DEQUE
	std::deque<int> deque = { 3,5,8,13,21 };
	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(89);

	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);
	for (int i = 0; i < deque.size(); i++)
	{
		cout << deque[i] << tab;
	}
	cout<<endl;

	std::deque<int> d_powers = { 256,512,768 };
#endif // STL_DEQUE

#ifdef FORWARD_LIST
	std::forward_list<int> list = { 3,5,8,13,21 };
	list.push_front(123);
	/*list.push_after(list.end(),1024);*/
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	list.reverse();
	list.push_front(1024);
	list.reverse();
	for (int i : list)cout << i << tab; cout << endl;
	std::list<int> list2;
	cout << "Forwardlist max size: " << list.max_size() << endl;
	cout << "List max size: " << list2.max_size() << endl;
#endif // FORWARD_LIST

}