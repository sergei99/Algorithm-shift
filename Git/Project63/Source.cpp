#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;


int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int size;
	fin >> size;
	char* arr1 = new char[size];
	char* arr2 = new char[2*size];

	for (int i = 0; i < size; i++)
	{
		fin >> arr1[i];
	}
	int COUNT = 0;
	for (int i = 0; i < size; i++)
	{
		fin >> arr2[i];
	}
	for (int i = size; i < 2 * size; i++)
	{
		arr2[i] = arr2[COUNT];
		COUNT++;
	}
	int* mass = new int[size];
	mass[0] = 0;
	int k = 0;
	int l = 1;
	while(l != size)
	{
		if (arr1[k] == arr1[l])
		{
			mass[l] = k + 1;
			l++;
			k++;
		}
		else if (k == 0)
		{
			mass[l] = 0;
			l++;
		}
		else
		{
			k = mass[k - 1];
		}

	}
	int k1 = 0;
	int l1 = 0;
	int l1_res = 0;
	while (k1 != 2*size)
	{
		if (k1 == 2 * size)
		{
			//fout << "bbbbb";
			fout << -1;
			break;
		}
		if (arr2[k1] == arr1[l1])
		{
			k1++;
			l1++;
			
		}
		else if (l1 == 0)
		{
			k1++;
			l1_res++;
		}
		else if (l1 == size)
		{
			//fout << k1 << endl;
			//fout << "aaaa";
			if (k1 > size )
			{
				//fout << abs(k1 - (2 * size));
				fout << k1 - size + 1;
			}
			if (k1 == size)
			{
				fout << 0;
			}
			/*if (k1 > size  && l1_res == 0)
			{
				fout << k1 - size + 1;
			}*/
			break;
		}
		else
		{
			
			l1 = mass[l1 - 1];
			l1_res += l1;
		}
		
		
	}
	//fout << l1_res + 1;
	/*for(int i = 0; i < size; i++)
	{
		fout << mass[i] << " ";
	}*/

	//fout << size;

	return 0;
}