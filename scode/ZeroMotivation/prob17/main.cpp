#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



int main() {
	string s,s1;
	cin >> s;
	int nb = 0;
	

	size_t pos1 = s.find("tt");
	size_t pos2 = s.find("vv");
	if ((pos1 == std::string::npos) && (pos2 == std::string::npos))
		cout << -1;
	else
	{
		while (s != "")
		{
			s1 = s;
			size_t pos1 = s.find("tt");
			size_t pos2 = s.find("vv");
			while ((s1.find("tt") != std::string::npos) || (s.find("vv") != ::string::npos))
			{
				if (s1.find("tt") != std::string::npos)
				{
					s1[s1.find("tt")] = 'v';
					s1.erase(std::remove(s1.begin(), s1.end(), s1[pos1 + 1]), s1.end());
					nb++;
				}
				if (s.find("vv") != std::string::npos)
				{
					s1[s.find("vv")] = 't';
					s1.erase(std::remove(s1.begin(), s1.end(), s1[pos2 + 1]), s1.end());
					nb++;
				}
			}
			s = s.substr(pos1 + 2, s.length() - pos1 - 1);

		}
	}
	cout << nb;
}