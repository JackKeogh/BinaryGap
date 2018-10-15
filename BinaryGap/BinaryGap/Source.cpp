#include <iostream>

using namespace std;

int solution(int N) {
	const int size = sizeof(N) * 8;
	int mask = 1;
	int max = 0;
	int LastIndex = -1;

	for (int i = 0; i < size; i++)
	{
		if (mask > N)
		{
			return max;
		}

		if ((N & mask) > 0)
		{
			if (LastIndex == -1)
			{
				LastIndex = i;
			}
			else
			{
				int gap = (i - LastIndex) - 1;
				if (gap > max)
				{
					max = gap;
				}
				LastIndex = i;
			}
		}

		mask <<= 1;
	}

	return max;
}

int main()
{
	bool running = true;
	int value;

	while (running)
	{
		cout << "Please input a number to check the binary gap..." << endl;

		cin >> value;

		cout << "The binary gap is : " << solution(value) << endl << endl;
	}

	return 0;
}