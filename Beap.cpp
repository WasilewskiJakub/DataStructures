#include<iostream>
#include<math.h>
using namespace std;

// Beap Implementation
// biparental heap - beap
// Hight of Beao can be calculated thx to following equals.
// Heap is impemanted in Array. It has tree structure.
// Leaves (tree) can exist on last or before last level (row) of our tree. 
// thx to it we get:
// h*(h-1) < n <= h*(h+1)
// (h-1)^2 < 2n < (h+1)^2
// sqrt(2n)-1 < h < sqrt(2n)+1
// floor(sqrt(2n)) <= h <= ceil(sqrt(2n))
// h = O(sqrt(n)) > O(log(n)) // beap is higher than heap, but search function is more effective
// Where: h - height of our Heap, n - numbers of elements in our Heap.

// Beap and Heap are not so good for dynamic data structures!
// Good to implement in Array!.
template<typename T>
class Beap
{
	T* elements;
	int h; // index of last element!
public:
	//Constructor
	Beap(int size) : h(0)
	{
		elements = new T[size];
		if (!elements) return;
	}
	
	pair<int, int> k2ij(int k)
	{
		int i = int(ceil(0.5 * (-1 + sqrt(1.0 + 8 * k))));
		int j = int(k - 0.5 * i * (i - 1));
		return pair<int,int>(i,j);
	}
	
	int ij2k(int i, int j)
	{
		return i * (i - 1) / 2 + j;
	}
	void Upbeap(int k)
	{
		int v = elements[k];
		pair<int, int> x = k2ij(k);
		int k1 = k;
		int i = x.first;
		int j = x.second;
		while (i > 1)
		{
			if (j == 1)
				k = k - i + 1;
			else if (i == j)
			{
				k -= i; j--;
			}
			else
			{
				k -= i;
				j--;
				if (elements[k + 1] < elements[k])
				{
					k += 1; j += 1;
				}
			}
			if (elements[k] < v)
			{
				elements[k1] = elements[k];
				k1 = k;
				i--;
			}
			else
				break;
		}
		elements[k1] = v;
	}
	void DownBeap(int k, int n)
	{
		pair<int, int> x = k2ij(k);
		int i = x.first;
		int j = x.second;
		int v = elements[k];
		int k1 = k;
		k += i;
		while (k <= n)
		{
			if (k + 1 <= n)
				if (elements[k + 1] > elements[k])
				{
					k++;
				}
			if (elements[k] > v)
			{
				elements[k1] = elements[k];
				k1 = k;
				x = k2ij(k);
				i = x.first;
				j = x.second;
				k += i;
			}
			else break;
		}
		elements[k1] = v;
	}
	int Search(int val) //O(sqrt(n))
	{
		// this is the only one advantage of BEAP, Search function is O(sqrt(n))
		if (elements[h] == val) return h;
		pair<int, int> x = k2ij(h);
		int i = x.first;
		int j = x.second;
		// Searching starts from last elemnt, in the last full row.
		if (i != j)
		{
			i--; j = i;
		}
		int k = ij2k(i, j);
		while (j > 0 && elements[k] != val)
		{
			if (val > elements[k])
			{
				k -= i; j--; i--;
			}
			else
			{
				if (k + i > h)
				{
					k--; j--;
				}
				else
				{
					k += i; i++;
				}
			}
		}
		return elements[k]==val? k : -1;
	} 
	void Insert(int x)
	{
		h++;
		elements[h] = x;
		Upbeap(h);
	}
	void DeleteMax()
	{
		elements[1] = elements[h];
		DownBeap(1, --h);
	}
	void print()
	{
		for (int i = 1; i <= h; i++)
		{
			cout << elements[i] << " ";
		}
		cout << endl;
	}
};
int main(int argc, char** argv)
{
	Beap<int> first(25);
	srand(1);
	for (int i = 1; i < 12; i++)
	{
		first.Insert(rand() % 20);
	}
	cout << "Beap:\n";
	first.print();
	first.DeleteMax();
	cout << "Beap DeleteMax():\n";
	first.print();
	cout << "Search(2): k= " << first.Search(13)<<endl;
	return EXIT_SUCCESS;
}
