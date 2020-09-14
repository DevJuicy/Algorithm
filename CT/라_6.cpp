#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

class Company
{
public:
	char name;
	map<char, int> priorityPreference;
	int maxCount;

public:
	Company(string name, string preference, int maxCount)
	{
		this->name = name[0];
		this->maxCount = maxCount;

		for (int i = 0; i < preference.size(); i++)
		{
			priorityPreference[preference[i]] = i;
		}
	}
};

class Applicant
{
public:
	char name;
	queue<char> preference;
	int count;
	bool applyCompany = false;

public:
	Applicant(string name, string preferenceStr, int maxCount)
	{
		this->name = name[0];
		this->count = maxCount;

		for (int i = 0; i < preferenceStr.size(); i++)
		{
			preference.push(preferenceStr[i]);
		}
	}
};

vector<string> Tokenize(string ids)
{
	vector<string> tokenizeList;
	string token;
	stringstream ss(ids);
	while (ss >> token)
	{
		tokenizeList.push_back(token);
	}

	return tokenizeList;
}

vector<string> solution(vector<string> companies, vector<string> applicants)
{
	vector<string> answer;
	vector<Company> companiesVec;
	vector<Applicant> applicantsVec;
	map<char, int> m; // �̸� char ���� ������ ���° �ε��� ȸ��or���������� �˼��ֵ���

	for (int i = 0; i < companies.size(); i++)
	{
		vector<string> temp = Tokenize(companies[i]);
		Company company(temp[0], temp[1], stoi(temp[2]));
		companiesVec.push_back(company);
		m[companiesVec[i].name] = i;
	}

	for (int i = 0; i < applicants.size(); i++)
	{
		vector<string> temp = Tokenize(applicants[i]);
		Applicant applicant(temp[0], temp[1], stoi(temp[2]));
		applicantsVec.push_back(applicant);
		m[applicantsVec[i].name] = i;
	}


	vector<vector<char>> rounds;
	rounds.resize(companiesVec.size());

	while (true)
	{
		// 1. ȸ�� �����ϱ�
		for (int i = 0; i < applicantsVec.size(); i++)
		{
			Applicant currentApplicant = applicantsVec[i];

			if (currentApplicant.preference.empty() || currentApplicant.count == 0 || currentApplicant.applyCompany)
				continue;

			currentApplicant.count--;
			currentApplicant.applyCompany = true;
			char prefCompanyName = currentApplicant.preference.front();
			currentApplicant.preference.pop();
			rounds[m[prefCompanyName]].push_back(currentApplicant.name);
		}

		int rejectedCount = 0;
		// 2. ȸ�� �ʰ��ο��� Ż�� ��
		for (int i = 0; i < companiesVec.size(); i++)
		{
			Company currentCompany = companiesVec[i];
			vector<char>& currentRound = rounds[m[currentCompany.name]]; // ���۷���

			// �������� �̴��ΰ�� �Ѿ
			if (currentCompany.maxCount >= currentRound.size())
				continue;

			vector<int> priorityApplicant;
			for (int j = 0; j < currentRound.size(); j++)
			{
				// �� ȸ�纰 �������� ������ int�� �Էµ�
				int priority = currentCompany.priorityPreference[currentRound[j]];
				priorityApplicant.push_back(priority);
			}
			// ������������ �����ű��
			sort(priorityApplicant.begin(), priorityApplicant.end());

			// Ż��
			for (int j = currentCompany.maxCount; j < priorityApplicant.size(); j++)
			{
				// �ش� element�� ���� 
				rejectedCount++;
				currentRound.erase(remove(currentRound.begin(), currentRound.end(), currentRound[j]));
				applicantsVec[m[currentRound[j]]].applyCompany = false;
			}
		}
		if (rejectedCount == 0)
			break;
	}

	return answer;
}

int main()
{
	solution({ "A fabdec 2", "B cebdfa 2","C ecfadb 2" },
		{ "a BAC 1", "b BAC 3", "c BCA 2", "d ABC 3", "e BCA 3", "f ABC 2" });
}