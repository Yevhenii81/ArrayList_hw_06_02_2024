#include <iostream>
#include <vector> // стандартный одномерный безразмерный динамический массив
#include <ctime>
using namespace std;

class ArrayList // Vector
{
	unsigned int size = 0; // количество действительно присутствующих элементов в контейнере
	unsigned int capacity = 10; // ёмкость (вместительность, запас памяти)
	int* data = nullptr; // указатель на динамический массив целых чисел

public:
	ArrayList() : ArrayList(10)
	{
		// cout << "C-TOR WITHOUT PARAMS!\n";
	}

	ArrayList(unsigned int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		data = new int[capacity];
		// cout << "C-TOR WITH PARAMS!\n";
	}

	~ArrayList()
	{
		// cout << "DESTRUCTOR!\n";
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	void PushBack(int value)
	{
		// EnsureCapacity(); // проверка, хватит ли места для нового элемента
		data[size] = value;
		size++;
	}

	void PushFront(int value)
	{
		EnsureCapacity();
		for (int i = size; i > 0; i--) // i = 1
		{
			data[i] = data[i - 1]; // data[1] = data[0]
		}
		data[0] = value;
		size++;
	}

	void EnsureCapacity()
	{
		if (size < capacity)return;

		int* temp = new int[size * 2];
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		delete[]data;
		data = temp;

		capacity *= 2;
	}

	void Clear()
	{
		size = 0;
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	void Print() const
	{
		if (IsEmpty())
		{
			cout << "Vector is empty.\n";
			return;
		}

		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << "\n";
	}

	// ...остальные методы...

	//геттеры для size и capacity. Сеттера для size не должно быть! 
	void SetCapacity(unsigned int capacity)
	{
		this->capacity = capacity;
	}

	unsigned int GetCapacity()
	{
		return capacity;
	}

	unsigned int GetSize()
	{
		return size;
	}

	//вставка одного элемента в массив по указанному индексу, с проверкой на выход за пределы массива
	void Insert(int index, int value)
	{
		if (index < 0 || index > size)
		{
			cout << "Wrong index\n";
			return;
		}

		EnsureCapacity();
		
		for (int i = size; i > index; i--)
		{
			data[i] = data[i - 1];
		}
		data[index] = value;
		size++;
	}

	//удаление первого элемента из массива
	void PopFront()
	{
		if (size == 0)
		{
			cout << "Vector is empty\n";
			return;
		}

		for (int i = 0; i < size; i++)
		{
			data[i] = data[i + 1];
		}
		size--;
	}

	//удаление последнего элемента из массива
	void PopBack()
	{
		if (size == 0)
		{
			cout << "Vector is empty\n";
			return;
		}

		size--;
	}

	//изменение порядка следования элементов в массиве на противоположный
	void Reverse()
	{
		int start = 0;
		int end = size - 1;

		if (size == 0)
		{
			cout << "Vector is empty\n";
			return;
		}

		while (start < end)
		{
			int temp = data[start];
			data[start] = data[end];
			data[end] = temp;

			start++;
			end--;
		}
	}

	//заполнение массива случайными значениями
	void RandomFill()
	{
		EnsureCapacity();

		for (int i = 0; i < size; i++)
		{
			data[i] = rand() % 15;
		}
		this->size = size;
	}
};

//перегрузка >>
istream& operator >> (istream& is, ArrayList& arr)
{
	cout << "Enter array: ";
	int answear;
	cin >> answear;
	arr.PushFront(answear);
	return cin;
}

//перегрузка <<
ostream& operator << (const ostream& i, ArrayList& d)
{
	d.Print();
	return cout;
}

int main()
{
	srand(time(NULL));

	ArrayList ar;
	//ar.Print();


	ar.PushFront(1);
	ar.PushFront(2);
	ar.PushFront(3);
	ar.PushFront(4);
	ar.PushFront(5);
	ar.PushFront(6);
	ar.PushFront(7);
	ar.PushFront(8);
	ar.PushFront(9);
	ar.PushFront(10);
	ar.PushFront(11);
	ar.PushFront(12);
	ar.PushFront(13);
	ar.PushFront(14);
	ar.PushFront(15);
	//ar.RandomFill(15);
	//ar.Insert(5, 16);
	//ar.PopBack();
	ar.PopFront();
	//ar.Reverse();
	ar.Print();
	

	/*ar.Print();
	cin >> ar;
	cout << ar;*/
}