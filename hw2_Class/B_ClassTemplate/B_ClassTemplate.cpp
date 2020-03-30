#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

template <typename T>
class MyArray
{
public:
	MyArray()
	{
		arr = NULL;
		arr_size = -1;
	}
	~MyArray()
	{
		if (arr != NULL)
			delete[] arr;
		arr_size = -1;
	}

	// you can use this like nomal array operator []
	// eg: MyArray<int> m; m[i] = 3;
	T& operator [](int pos) { return arr[pos]; }

	int get_size() const { return arr_size; }

	// allocate a array, size is n
	void new_arr(int n);
	// move the elements bettween  start(i) and end(j) to the behind of pos(k)
	void segment_move(int start, int end, int pos);
	// reverse the elements bettween start(i) and end(j)
	void segment_reverse(int start, int end);
	// print all elements
	void print();

private:
	// private variable only used by public function
	// means, a.arr is illegal operation, a is MyArray
	T* arr;
	int arr_size;
};


template <typename T>
void MyArray<T>::new_arr(int n)
{
	if (arr != NULL)
		delete arr;
	arr_size = n;
	arr = new T[n];
}

template <typename T>
void MyArray<T>::segment_move(int start, int end, int pos)
{
	T* tmp_arr = new T[arr_size];
	int j = 0;
	for (int i = 0; i < start; i++, j++)
		tmp_arr[j] = arr[i];
	for (int i = end + 1; i <= pos; i++, j++)
		tmp_arr[j] = arr[i];
	for (int i = start; i <= end; i++, j++)
		tmp_arr[j] = arr[i];
	for (int i = pos + 1; i < arr_size; i++, j++)
		tmp_arr[j] = arr[i];

	delete[]arr;
	arr = tmp_arr;
}

template <typename T>
void MyArray<T>::segment_reverse(int start, int end)
{
	T temp;
	for (int i = 0; i < (end - start + 1) / 2; i++)
	{
		temp = arr[start + i];
		arr[start + i] = arr[end - i];
		arr[end - i] = temp;
	}
}

template <typename T>
void process(MyArray<T>& m_arr, // 引用类型，不是取地址运算
	int m)
{
	int i, j, k;
	char str[10];
	while (m--)
	{
		cin >> str;
		if (str[0] == 'm')
		{
			cin >> i >> j >> k;
			m_arr.segment_move(i, j, k);
		}
		else 
		{
			cin >> i >> j;
			m_arr.segment_reverse(i, j);
		}
	}
	m_arr.print();
}

template <typename T>
void MyArray<T>::print()
{
	cout << setprecision(2) << setiosflags(ios::fixed) << arr[0];
	for (int i = 1; i < arr_size; i++)
		cout << " " << setprecision(2) << setiosflags(ios::fixed) << arr[i];
	cout << endl;
}

int main()
{
	int t;
	int n, m;
	int i, j, k;
	char type[10];
	cin >> t;
	while (t--)
	{
		cin >> type >> n >> m;
		// interger
		if (0 == strcmp(type, "interger"))
		{
			MyArray<int> m_arr;
			m_arr.new_arr(n);
			for (int i = 0; i < n; i++)
				cin >> m_arr[i];
			process(m_arr, m);
		}
		// double
		else if (0 == strcmp(type, "double"))
		{
			MyArray<double> m_arr;
			m_arr.new_arr(n);
			for (int i = 0; i < n; i++)
				cin >> m_arr[i];
			process(m_arr, m);
		}
		// string
		else if (0 == strcmp(type, "string"))
		{
			MyArray<string> m_arr;
			m_arr.new_arr(n);
			for (int i = 0; i < n; i++)
				cin >> m_arr[i];
			process(m_arr, m);
			system("pause");
		}
	}
	return 0;
}

