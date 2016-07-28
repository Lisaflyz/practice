#include<iostream>
#include<vector>
using namespace std;

int main2(){
	int n, temp, count = 0;
	vector<int> a;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> temp;
		a.push_back(temp);
	}

	for (int i = 1; i <= n - 2; i++){
		if ((a[i] < a[i - 1] && a[i] < a[i + 1]) || (a[i] > a[i - 1] && a[i] > a[i + 1]))
			count++;
	}

	cout << count;

	return 0;
}




