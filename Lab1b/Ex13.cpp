
#include <iostream>
#include <string>


void ex4(std::string& str, char ch)
{
	int index = -1;
	int pos = -1;
	int count = 0;
	for (std::string::iterator i = str.begin(); i != str.end(); ++i)
	{
		if (*i == ch)
		{
			pos = count;
			break;
		}
		count++;
	}
	if (count == -1){
		std::cout << "caractere nao encontrado!";
		return;
	}
	for (int i = count; i <= str.size(); i++){
		if (i + 1 >= str.size()){
			str[i] = ' ';
		}
		else{
			str[i] = str[i+1];
		}
	}
}


int main()
{
	std::string str = "CAIO";
	std::cout << "Antes: " << str << std::endl;

	ex4(str, 'I');
	std::cout << "Depois: " << str << std::endl;
}
