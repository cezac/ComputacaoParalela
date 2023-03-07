include <iostream>
include <string>

int ex3(char ch, std::string str)
{
	int index = -1;
	int count = 0;
	for (std::string::iterator i = str.begin(); i != str.end(); ++i)
	{
		if (*i == ch)
		{
			index = count;
			return index;
		}
		count++;
	}
	return index;
}


int main()
{
	std::cout << "Posicao do E em teste: " << ex3('O', "CAIO");
}
