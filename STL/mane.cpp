#include<iostream>
#include<array>
#include<vector>
using namespace std;

#define tab "\t"

//#define STL_ARRAY
#define STL_VECTOR

template<typename T>void print(const vector<T>& vec)
{
	for (typename vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	array<int, 5>arr = { 3,5,8,13,21 };
	for(int i = 0; i < arr.size();i++ )
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY


#ifdef STL_VECTOR
	//vector- это последовательный контейнерб который хранит данные в виде динамического массива
	vector<int> vec = {0,1,1,2,3,5,8,13,21,34,55,89,144,232};
	cout << "Size:      " << vec.size() << endl;
	cout << "Capacity:  " << vec.capacity() << endl;//есть только у вектора
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
		//subscript - индексирование
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}

	cout << "Size:      " << vec.size() << endl;
	cout << "Capacity:  " << vec.capacity() << endl;//есть только у вектора
	cout << "MaxSize:   " << vec.max_size() << endl;
	cout << sizeof(vec) << endl;


	int index;
	int value;
	int count;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	cout << "¬ведите количество добавлений: "; cin >> count; 
	cout << "¬ведите значение добавл€емого элемента: "; cin >> value;
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

	cout << "¬ведите индекс удал€емого элемента: "; cin >> index;
	cout << "¬ведите количество удаление: "; cin >> count;
	vec.erase(vec.begin() + index, vec.begin()+index+count);
	print(vec);


	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	vec.swap(powers);
	print(vec);
	print(powers);
#endif // STL_VECTOR


}