/*
1������ϵͳ�ṹ
2����������
3�����ݹ�������
*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Node{
	int pos;
	string content;
	Node* parent;
	vector<Node*> children;

};

Node files[10];
int main(){
	int p;
	string currentIndex;
	vector<string> needProcess;
	cin >> p;
	getchar();
	cin >> currentIndex;

	string temp;
	for (int i = 0; i < p; i++){
		cin >> temp;
		needProcess.push_back(temp);
	}


	//����ϵͳ�ṹ
	files[0].content = "/";
	files[0].parent = NULL;
	files[0].children.push_back(&files[1]);
	files[0].children.push_back(&files[2]);
	files[1].content = "d1";
	files[1].parent = &files[0];
	files[1].children.push_back(&files[3]);
	files[1].children.push_back(&files[4]);
	files[2].content = "d2";
	files[2].parent = &files[0];
	files[2].children.push_back(&files[5]);
	files[2].children.push_back(&files[6]);
	files[2].children.push_back(&files[7]);
	files[3].content = "f1";
	files[3].parent = &files[1];
	files[3].children.empty();
	files[4].content = "f2";
	files[4].parent = &files[1];
	files[4].children.empty();
	files[5].content = "d3";
	files[5].parent = &files[2];
	files[5].children.push_back(&files[8]);
	files[6].content = "d4";
	files[6].parent = &files[2];
	files[6].children.push_back(&files[9]);
	files[7].content = "f4";
	files[7].parent = &files[2];
	files[7].children.empty();
	files[8].content = "f3";
	files[8].parent = &files[5];
	files[8].children.empty();
	files[9].content = "f1";
	files[9].parent = &files[6];
	files[9].children.empty();
	for (int i = 0; i < 10; i++)
		files[i].pos = i;
	string a;
	vector<string> section[11];
	for (int i = 0; i <= p; i++){
		if (i < p)
			a = needProcess[i];
		else
			a = currentIndex;

		int pos1 = 0;
		int pos2 = 0;
		if (a == "")
			section[i].push_back("null");
		bool isAllSlash = true;
		for (int g = 0; g < a.size(); g++){
			if (a[g] != '/'){
				isAllSlash = false;
				break;
			}
		}

		if (isAllSlash == true)
			section[i].push_back("root");//section[i]��һ���յ�vector

		if (a != "" && isAllSlash == false)
		{
			int start = 0, end = 0, size = a.size();
			for (end = 0; end < size; ++end){
				if (a[end] == '/'){
					if (end > start){
						string newStr = a.substr(start, end - start);
						section[i].push_back(newStr);
					}
					start = end + 1;
				}
			}

			if (end > start){
				string newStr = a.substr(start, end - start);
				section[i].push_back(newStr);
			}

		}
	}

	/*for (int i = 0; i < p; i++)
	for (int j = 0; j < section[i].size(); j++){
	cout << section[i][j];
	}

	cout << endl;
	cout << "------" << "�õ���������";*/

	for (int i = 0; i < p; i++){
		if (section[i][0] == "root"){//Ϊ��Ŀ¼
			cout << "/" << endl;
			continue;
		}
		if (section[i][0] == "null"){//·��Ϊ���ַ���
			cout << currentIndex << endl;
			continue;
		
		}

		//�ж��ַ������Ƿ���ǰ��
		bool isTwoDot = false;
		for (int j = 0; j < section[i].size(); j++)
			if (section[i][j] == "..")
				isTwoDot = true;


		int position = 0;
		vector<string> curPathSpar;
		bool isAbsPath = true;
		if (needProcess[i][0] == '/'){//����·��
			position = 0;
			isAbsPath = true;
		}
		else{//���·��
			isAbsPath = false;
			curPathSpar = section[p];//��ǰ·������,��ǰ·������Ϊ���ڵ�
			int num = section[p].size();
			string last = section[p][num - 1];
			if (last == "root")
				position = 0;
			else{
				
				for (int p = 0; p < 10; p++){
					if (last == files[p].content){
						position = p;
						break;
					}
				}

				if (last == "f1" && section[p][num - 2] == "d1")
					position = 3;
				if (last == "f1" && section[p][num - 2] == "d4")
					position = 9;
			}

		}



		if (isAbsPath == false && isTwoDot == false){//���·����ǰ�ݣ����������ǰĿ¼
			for (int h = 0; h < curPathSpar.size(); h++)
				if (position!=0)
				cout << "/" << curPathSpar[h];
		}

		for (int j = 0; j < section[i].size(); j++){
			if (section[i][j] != "." && isTwoDot == false)//��ǰ��ֱ���������Ľڵ�
				cout << "/" << section[i][j];
			
			if (isTwoDot == true){//��ǰ�ݣ����ҵ�����Ŀ¼���±�λ��
				string cur = section[i][j];
				if (cur != ".."){
					//cout << "------" << section[i][j] << endl;
					for (int k = 0; k < 10; k++)
						if (files[k].content == cur){

							if (position == files[k].parent->pos){
								position = k;
								//cout << "�ڲ�position = " << position << endl;
								break;
							}
						}
				}
				else if (cur == ".."){
					//cout << "........" << section[i][j] << endl;
					if (position != 0){
						position = files[position].parent->pos;
						//cout << "�ڲ�..position = " << position << endl;
					}
					else
						position = 0;
				}

			}
		}

		if (isTwoDot == false)
			cout << endl;

		//cout << "����position�� " << position << endl;
		vector<string> result;
		if (isTwoDot == true){
			while (position != 0){
				result.push_back(files[position].content);
				position = files[position].parent->pos;
			}
			for (int n = result.size() - 1; n >= 0; n--)
				cout << "/" << result[n];
			cout << endl;
		}


	}

	return 0;

}