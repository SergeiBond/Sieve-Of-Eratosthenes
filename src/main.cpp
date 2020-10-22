/*
* Program Name: Sieve of Eratosthenes
* Desription: A simple ancient algorithm for finding all prime numbers up to any given limit. My first c++ program.
* Author: Sergei Bondarenko
* Date: April 26th, 2018
* Modification History:
*/


#include <iostream>


using namespace std;



int main()
{

	const int ARRAY_SIZE = 10000;
	bool matrix[ARRAY_SIZE] = { 1, 1, };
	int size = 0;

	cout	<< "Please enter the number for the upper limit N." << endl
			<< "The prime numbers will be calculated for the sequence from 2 (the first prime number) to N" << endl
			<< "N is: ";

	cin >> size;

	while ((size <= 2) || (size > ARRAY_SIZE))
	{
		cout << endl << "Please enter a positive number greater than two and lesser than " << ARRAY_SIZE << " : ";
		cin >> size;
	}

	
	//Populate the matrix with ones (all numbers in range are considered prime for now)

	for (int i = 1; i < size; i++)
	{
		matrix[i] = 1;
	}

	//Populate the matrix with 0 for the composite numbers, thus eliminating them from the pool of numbers with prime status

	for (int i = 2; i < (size / 2); i++)
	{

		for (int n = 2; (n * i) <= size; n++)
		{

			matrix[i * n - 1] = 0;

		}

	}


	cout << "The prime numbers from 2 to " << size << " are:" << endl << endl;


	//Print all the numbers that are marked as primes


	for (int i = 1; i < size; i++)
	{
		if (matrix[i] == 1)
		{
			cout << (i + 1) << endl;
		}
	}



	system("Pause");

	return 0;

}
