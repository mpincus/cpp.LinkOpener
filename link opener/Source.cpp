#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <windows.h>

using namespace std;

template <typename InputIterator, typename T, typename Func>
void split(InputIterator i, InputIterator o, T&& e, Func&& f) {
	for (;;) {
		auto j = find(i, o, e);
		
		if (j == o) break;
		
		f(i, j);
		
		i = ++j;
	}
	
	if (i != o) {
		f(i, o);
	}
}

int main() {
	wstring input;
	getline(wcin, input);
	wstring website = L"https://www.google.com/#q=";
	wstring keyword = L"discography tpb";
	wstring temp;
	vector<wstring> parts;
	
	typedef wstring::iterator it_t;
	
	split(begin(input), end(input), ',', [&parts] (it_t a, it_t b) {
		parts.emplace_back(a, b);
	});
	
	for (auto& part : parts) {
		temp = website + part + keyword;
		ShellExecute (NULL, L"open", temp.c_str(), NULL, NULL, SW_SHOWNORMAL);
	}
}
