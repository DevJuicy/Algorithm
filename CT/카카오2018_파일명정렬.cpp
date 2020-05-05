#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class File
{
public:
	string head;
	int realNumber;
	File(string head, int realNumber)
	{
		this->head = head;
		this->realNumber = realNumber;
	}
};

bool Compare(pair<File, int> a, pair<File, int> b) // sort�� �Ųٷ� ����
{
	if (a.first.head.compare(b.first.head) == 0) // ��尡 �������
	{
		if (a.first.realNumber == b.first.realNumber) // �ѹ��� �������
			return false; // �ٲ��� ����
		else
		{
			if (a.first.realNumber < b.first.realNumber) // �������Ǽ��ڰ� �տ�����ں��� �������
				return true; // �ٲ���
			return false;
		}
	}
	else
	{
		if (a.first.head.compare(b.first.head) > 0) // �������� �Ӹ��� ���ǳ��� �Ӹ����� ū���
			return false;
		return true;
	}
}

bool IsNumber(char c)
{
	return c >= '0' && c <= '9';
}

File DivideFileName(string fileName)
{
	int index = 0;
	string head = "";
	for (int i = 0; i < fileName.size(); i++)
	{
		if (IsNumber(fileName[i]))
			break;
		else
		{
			head += fileName[i];
			index++;
		}
	}

	string number = "";
	for (int i = index; i < fileName.size(); i++)
	{
		if (!IsNumber(fileName[i]) || number.size() == 5)
			break;
		else
		{
			number += fileName[i];
			index++;
		}
	}
	int realNumber = stoi(number);

	File file(head, realNumber);
	return file;
}

vector<string> solution(vector<string> files)
{
	vector<string> answer;
	answer.resize(files.size());
	vector<pair<File, int>> fileIndex;

	// ���
	for (int i = 0; i < files.size(); i++)
	{
		string tempFileName = files[i];
		for (int j = 0; j < files[i].size(); j++)
			tempFileName[j] = toupper(files[i][j]);
		fileIndex.push_back({ DivideFileName(tempFileName),i });
	}

	sort(fileIndex.begin(), fileIndex.end(), Compare);

	for (int i = 0; i < fileIndex.size(); i++)
		answer[i] = files[fileIndex[i].second];

	return answer;
}

int main()
{
	//solution({ "img12", "img10", "img02"
	//		  , "img1", "IMG01", "img2" });
	//solution({ "muzi1.txt","MUZI1.txt","muzi001.txt","muzi1.TXT" });
	//solution({ "F13.png", "F14", "f013", "F014", "F013.TXT" });
	solution({ "a000011","a00001" });
	solution({ "a0001","a0001","a0000001" });
	solution({ "F-15","f15","F15.png" });
}