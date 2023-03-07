include <iostream>
include <string>


int main()
{
	double nota1;
	double nota2;
	double nota3;
	double mediaEx;

	std::cout << "Informe a primeira nota: ";
	std::cin >> nota1;

	std::cout << "Informe a segunda nota: ";
	std::cin >> nota2;
	
	std::cout << "Informe a terceira nota: ";
	std::cin >> nota3;

	std::cout << "Informe a media dos exercicios: ";
	std::cin >> mediaEx;
	
	std::cout << "Nota 1: " << nota1 << std::endl <<
		"Nota 2: " << nota2 << std::endl <<
		"Nota 3: " << nota3 << std::endl << 
		"Media dos exercicios: " << mediaEx << std::endl;

	double media  = (nota1 + nota2*2 + nota3*3 + mediaEx)/7;
	char aproveitamento = 'X';

	if (media >= 9) aproveitamento = 'A';
	else if (media >= 7.5) aproveitamento = 'B';
	else if (media >= 6) aproveitamento = 'C';
	else if (media >= 4) aproveitamento = 'D';
	else aproveitamento = 'E';
	std::cout << "Media = [" << media << "]" << std::endl; 
	std::cout << "Aproveitamento = [" << aproveitamento << "]";
}
