#include <iostream>
using namespace std;
class dynamicfloats
{
	float *p;
	int s;
public:
	dynamicfloats() {
		p = NULL;
		s = 0;
	}
	~dynamicfloats()
	{
		if (p != NULL)
		{
			delete[] p;
		}
	}
	void setsize(int news) {
		if (s == 0)
		{
			s = news;
			p = new float[s];
			return;
		}
		int m = s;
		if (news<s)
		{
			m = news;
		}
		float *t;
		t = new float[news];
		for (int i = 0; i < m; i++)
		{
			t[i] = p[i];
		}
		delete[]p;
		p = t;
		s = news;
	}
	int getsize() {
		return s;
	}
	void setel(int i, float f) {
		if (i < s) {
			p[i] = f;
			return;
		}
	}
	void addel(float f) {
		setsize(s + 1);
		p[s - 1] = f;
	}
	void removeel(int j) {
		if (j == s - 1)
		{
			setsize(s - 1);
			return;
		}
		for (int i = j; i <s - 1; i++)
		{
			p[i] = p[i + 1];
		}
		setsize(s - 1);
		return;
	}
	void removedupl() {
		for (int i = 0; i < s - 1; i++)
		{
			for (int j = i + 1; j <= s - 1; j++)
			{
				if (p[i] == p[j])
				{
					removeel(j);
					j--;
				}
			}
		}
	}
	void concate(float f[], int sizef) {
		setsize(s + sizef);
		int t = 0;
		for (int i = s - sizef; i < s; i++)
		{
			p[i] = f[t];
			t++;
		}
	}
	void print() {
		for (int i = 0; i < s; i++)
		{
			cout << p[i] << " ";

		}
	}
	void sort() {
		for (int i = 0; i < s - 1; i++)
		{
			for (int j = i + 1; j < s; j++)
			{
				float t;
				if (p[i]>p[j])
				{
					t = p[i];
					p[i] = p[j];
					p[j] = t;

				}
			}

		}
	}
	void reverse() {
		for (int i = 0; i < s / 2.0; i++)
		{
			float t;
			t = p[i];
			p[i] = p[s - i - 1];
			p[s - i - 1] = t;
		}
	}
	void insert(int t, float f) {
		setsize(s + 1);
		for (int i = s - 1; i >= t; i--)
		{
			if (i == t)
			{
				p[i] = f;
				return;
			}
			p[i] = p[i - 1];
		}
	}
	int find(float f) {
		for (int i = 0; i <= s; i++)
		{
			if (i == s)
			{
				return -1;

			}
			if (p[i] == f)
			{
				return i;
			}
		}
	}
	float getel(int t) {
		if (t < s)
		{
			return p[t];
		}
		return -1;
	}
	float getmax() {
		float t;
		int i = 0;
		for (int j = i + 1; j < s; j++)
		{
			t = p[i];
			if (p[i] < p[j]) {
				t = p[j];
				i = j;
			}
		}
		return t;
	}
	float getmin() {
		float t;
		int i = 0;
		for (int j = i + 1; j < s; j++)
		{
			t = p[i];
			if (p[i] > p[j]) {
				t = p[j];
				i = j;
			}
		}
		return t;
	}
	void cinarr(float x)
	{
		for (int i = 0; i >= 0; i++)
		{
			float t;
			cin >> t;
			addel(t);
			if (t == x)
			{
				break;
			}
		}
	}
};
void fun(dynamicfloats v)
{
	v.removedupl();
}


int main() {
	/*dynamicfloats a;
	a.cinarr(-1);
	a.removedupl();
	a.sort();
	a.print();
	cout << endl << "the number of element is : " << a.getsize()<<endl<< "max is : "<<a.getmax()<<endl;
	a.reverse();
	a.print();
	cout <<endl;*/
	dynamicfloats x;
	x.cinarr(99); x.removedupl();
	x.sort();
	x.print();
	system("pause");
}