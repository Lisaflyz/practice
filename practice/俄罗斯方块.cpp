#include<iostream>
using namespace std;

int main(){
	//a��������4��
	int a[20][11], b[5][5], startIndex = 0;
	for (int i = 1; i <= 15; i++)
		for (int j = 1; j <= 10; j++)
			cin >> a[i][j];
	for (int i = 16; i <= 19; i++)
		for (int j = 1; j <= 10; j++)
			a[i][j] = 1;

	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			cin >> b[i][j];
	cin >> startIndex;
	bool stop = false;
	
	int line = 1;
	for (; line <= 16 && stop == false; line++){
		for (int i = line, rowb = 1; i < line + 4 && stop == false; i++, rowb++){
		
			if (rowb > 4)
				rowb = 1;
		

			//���ĳһ���е�������
			for (int j = startIndex,colb = 1; j < startIndex + 4 && stop == false; j++, colb++){
				if (a[i][j] == 1 && b[rowb][colb] == 1){
				stop = true;
				}
			}
		}

	}

	//���ص���
	if (stop == true){
		line = line - 2;
		//��ԭͼ�е��ӿ�Ƭ���޸�ԭͼ
		for (int i = line, rowb = 1; i < line + 4; i++, rowb++)
			for (int j = startIndex, colb = 1; j < startIndex + 4; j++, colb++){
				if (a[i][j] == 0 && b[rowb][colb] == 1)
					a[i][j] = 1;
			}

	}

	for (int i = 1; i <= 15; i++){
		for (int j = 1; j <= 10; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
		
}