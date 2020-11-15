#include <iostream>
#include <vector>

using namespace std;

template <class Comparable>
Comparable maxSubsequenceSum( const vector<Comparable> & a, int & seqStart, int & seqEnd )
{
	int n = a.size();
	Comparable maxSum = 0;

	for(int i=0; i<n; i++)
		for(int j=i; j<n; j++)
		{
			Comparable thisSum = 0;
			for(int k=0; k<=j; k++)
				thisSum += a[k];

			if(thisSum > maxSum )
			{
				maxSum = thisSum;
				seqStart = i;
				seqEnd = j;
			}
		}

	return maxSum;
}

int main()
{
  return 0;
}