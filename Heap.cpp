//#include<iostream>
//using namespace std;
//
//// Heap Implementation.
//// Hight of heap can be calculated thx to following equals.
//// Heap is impemanted in Array. It has tree structure.
//// Leaves (tree) can exist on last or before last level (row) of our tree. 
//// thx to it we get:
//// 2^(h-1) <= n <= 2^h
//// h-1 <= log(n) <= h
//// h = O(log(n))
//// Where: h - height of our Heap, n - numbers of elements in our Heap.
//template<typename T>
//class Heap
//{
//	T* elements;
//	int h; // index of last element!
//public:
//	//Constructor
//	Heap(int size) : h(0)
//	{
//		elements = new T[size];
//		if (!elements) return;
//	}
//	// Insert() - opperation allows us to add new item to Heap.
//	// We add item on the last index of our Array, and after we use Upheap().
//	void Upheap(int hl)
//	{
//		elements[0] = INT16_MAX; // our sentinel.
//		while (elements[hl] > elements[hl / 2])
//		{
//			swap(elements[hl], elements[hl / 2]);
//			hl /= 2;
//		}
//	}
//	void Insert(int x)
//	{
//		h++;
//		elements[h] = x;
//		Upheap(h); // Heap correction above added item.
//	}
//	void Max()
//	{
//		if (h >= 1)
//			return elements[1];
//		else
//			cout << "No elements in Heap\n";
//	}
//	void Downheap(int i, int hl)
//	{
//		int k = i * 2;
//
//		while (k <= hl)
//		{
//			if (k + 1 <= hl)
//				if (elements[k + 1] > elements[k])
//					k++;
//			if (elements[k] > elements[i])
//			{
//				swap(elements[i], elements[k]);
//				i = k;
//				k *= 2;
//			}
//			else
//				break;
//		}
//	}
//	void DeleteMax()
//	{
//		if (h == 0)
//		{
//			cout << "No elements in Heap\n";
//			return;
//		}
//		elements[1] = elements[h];
//		Downheap(1, --h);
//	}
//	void print()
//	{
//		for (int i = 1; i <= h; i++)
//		{
//			cout << elements[i] << " ";
//		}
//		cout << endl;
//	}
//	// ExtraMethods for Heap
//	template<typename T>
//	int Search(T val) // not effective for Heap O(n) must search every element
//	{
//		int i;
//		for (i = 1; i <= this->h; i++)
//		{
//			if (elements[i] == val) return i;
//		}
//		return -1; // -1 as a not found!
//	}
//	template<typename T>
//	void Replace(int i, T v) // function change value (v) of elements in i-th index.
//	{
//		if (i<1 || i>h)
//		{
//			cout << "Bad index!\n";
//		}
//		if (elements[i] > v)
//		{
//			elements[i] = v;
//			Downheap(i, this->h);
//		}
//		else
//		{
//			elements[i] = v;
//			Upheap(i);
//		}
//	}
//	void Replace1(int i, int j) // replace ith on jth and jth on ith element!
//	{
//		T x = elements[i];
//		Replace(i, elements[j]);
//		Replace(j, x);
//	}
//	void Delete(int i) // Function 
//	{
//		Replace(i, elements[h--]);
//	}
//};
//int main(int argc, char** argv)
//{
//	Heap<int> first(24);
//	srand(12);
//	for (int i = 0; i < 12; i++)
//	{
//		first.Insert(rand() % 20);
//	}
//	cout << "Heap:\n";
//	first.print();
//	first.DeleteMax();
//	cout << "Heap DeleteMax():\n";
//	first.print();
//	first.Replace(3, 8);
//	cout << "Heap Replace(3, 8):\n";
//	first.print();
//	first.Delete(8);
//	cout << "Heap Delete(8):\n";
//	first.print();
//	first.Replace1(2, 7);
//	cout << "Heap Replace1(2, 7):\n";
//	first.print();
//	return EXIT_SUCCESS;
//}
//
