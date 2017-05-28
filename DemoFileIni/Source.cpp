#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <map>
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
using namespace std;
void ReadSectionTypeLine(wstring  nameSection);
int main(void)
{
	/*std::wstring a(L"[nguyen]a=2[nguyen]a=2[nguyen]a=2[nguyen]a=2");
	std::wofstream f(L"test.ini");
	f << a.c_str();
	f.close();*/
	
	
	wchar_t buffer[1024] = { 0 };
	int l = 0;
	GetPrivateProfileSectionNames(buffer, 1024, L"./test.ini");
	std::map<std::wstring,int> listSection;
	for (int i = 0; i < 1024; ++i)
	{
		if (buffer[i] == '\0')
		{
			if (i > l)
			{
				wstring s = &buffer[l];
				
				if (listSection[s] == 0)
					listSection[s] = l;
				else
					cout << "Duplicate";
			}
			else if (i == l)  // 2 zeros detected
				break;
			l = i + 1;
		}
	}
	//get section
	for (std::map<std::wstring, int>::iterator itr = listSection.begin(), itr_end = listSection.end(); itr != itr_end; ++itr) {
		wstring result= itr->first.c_str();
		wchar_t resultType[500];
		GetPrivateProfileString(result.c_str(), L"type", nullptr,resultType, 499, L"./test.ini");
		ReadSectionTypeLine(result.c_str());
	}
	


	wchar_t result[500];
	int len = GetPrivateProfileString(L"nguyen", L"a", nullptr, result, 499, L"./test.ini");
	char* p = (char*)buffer;
	size_t length = 0;
	int nCnt = 0;
	while (*p)
	{
		length = strlen(p);
		cout << "section " << nCnt << p << endl;
		nCnt++;
		p += length;
		p++;
	}
	return 0;
}

void check(unsigned int x1, unsigned int y2)
{
	if (x1 == 0)
		cout << "Error";
}
void ReadSectionTypeLine(wstring  nameSection)
{
	wchar_t result[500];
	int x1, x2, y1, y2=0;
	wstring bordercolor;
	int len = GetPrivateProfileString(nameSection.c_str(), L"x1", nullptr, result, 499, L"./test.ini");
	x1 = ::_wtoi(result);

	GetPrivateProfileString(nameSection.c_str(), L"y1", nullptr, result, 499, L"./test.ini");
	x1 = ::_wtoi(result);

	GetPrivateProfileString(nameSection.c_str(), L"x2", nullptr, result, 499, L"./test.ini");
	x1 = ::_wtoi(result);

	GetPrivateProfileString(nameSection.c_str(), L"y2", nullptr, result, 499, L"./test.ini");
	x1 = ::_wtoi(result);

	GetPrivateProfileString(nameSection.c_str(), L"bordercolor", nullptr, result, 499, L"./test.ini");
	bordercolor = result;
	check(x1, y2);
}