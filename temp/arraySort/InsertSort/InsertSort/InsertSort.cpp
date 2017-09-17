// InsertSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void sortArray(int intAry[50], int sz)
{
	cout << "begin sorting array..." << endl;
	for (auto i = 1; i < sz; ++i ) 
	{
		auto key = intAry[i];
		for (auto j = i; j > 0; --j ) 
		{
			if (intAry[j - 1] > key ) 
			{
				intAry[j] = intAry[j-1];
				intAry[j-1] = key;
			}
			else 
				break;
		}
	}
}

//!!!NOTE sizeof(intAry)/sizeof(int) cannot be recognized by the compiler, 
//so we never now the real size of the array just resorting to the divide experssion. 
//so the array length must be passed in explicitly. - Sept 14th, 2017
void dumpArray(int intAry[50], int sz) 
{
	//cout << "begin dumping array..." << endl;
	//int sz = sizeof(intAry)/sizeof(int);
	//cout << "size of array is " << sz << endl;
	for( auto i = 0; i < sz; ++i) {
		cout << i << " => " << intAry[i] << endl;
	}
	return;
}
void verifySortingResult(int intAry[], int sz)
{
	cout << "verify Sorting result..." << endl;
	for(auto i = 1; i < sz; ++i) 
	{
		if (intAry[i] < intAry[i-1]) 
		{
			cerr << "not sorted!!!" << endl;
			exit(0);
		}
	}
	cout << "the array is petty sorted !!" << endl;
	return;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int intArray[50] = {6098, 643, 7587, 4542, 708, //created with help of https://www.random.org/
						2445, 5679, 581, 7739, 197, 
						9649, 2170, 1365, 9425, 4964, 
						8013, 9175, 329, 1305, 5211, 
						8538, 6079, 8560, 1278, 9205, 
						8462, 5955, 7222, 7114, 1994, 
						8056, 9250, 5342, 9438, 662, 
						6215, 7649, 5153, 2719, 3742, 
						2480, 5069, 5181, 8063, 2092, 
						4479, 6088, 4032, 5787, 3912};

#define SIZE (sizeof(intArray)/sizeof(int))
#pragma message("the sizeof(intArray)/sizeof(int) is caculated by the compiler statically") 
	int sz = sizeof(intArray)/sizeof(int);
	cout << "size of array is " << sz << endl;
	cout << "SIZE is " << SIZE << endl;
	dumpArray(intArray, SIZE);
	sortArray(intArray, SIZE);
	verifySortingResult(intArray, SIZE);
	dumpArray(intArray, SIZE);
	return 0;
}

