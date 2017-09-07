#include "../../include/questao1/Data.h"

Data Data::data_atual;

void Data::atribuiData_atual()
{
	
	std::string line_d;
	int d,m,a;

	std::cout << std::endl << "Por favor digite o dia: " << std::endl;

	while(std::getline(std::cin, line_d) )
	{
		
		std::stringstream ss(line_d);
		
		if(ss >> d && ss.eof())
		{
			if(d < 1 || d > 30)
			{
				std::cout<< "Dia invalido, os dias variam de 1 a 30. " << std::endl;
				std::cout << std::endl << "Por favor digite o dia: " << std::endl;
				continue;
			}
			else
				break;
		}
		std::cout << std::endl << "Dia invalido, os dias sao numeros inteiros que variam de 1  a 30. " << std::endl;
	}
	
	//dia = line_d;

	std::cout << std::endl << "Por favor digite o mes: " << std::endl;

	std::string line_m;

	while(std::getline(std::cin, line_m) )
	{
		
		std::stringstream ss(line_m);
		
		if(ss >> m && ss.eof())
		{
			if(m < 1 || m > 12)
			{
				std::cout << "Mes invalido, o mes varia de 1 a 12. " << std::endl;
				std::cout << std::endl << "Por favor digite o mes: " << std::endl;
				continue;
			}
			else
				break;
		}
		std::cout << std::endl << "Mes invalido, o mes e um inteiro que varia de 1 a 12. " << std::endl;
	}

	//mes = line;

	std::cout << std::endl << "Por favor digite o ano: " << std::endl;

	std::string line_a;

	while(std::getline(std::cin, line_a) )
	{
		
		std::stringstream ss(line_a);
		
		if(ss >> a && ss.eof())
		{
			if(a < 0){
				std::cout << "ano invalido, ano varia de 0 ate o ano atual. " << std::endl;
				std::cout << std::endl << "Por favor digite o ano: " << std::endl;
				continue;
			}
			else 
				break;
		}
		
		std::cout << std::endl << "ano invalido, ano e um inteiro que varia de 0 ate o ano atual. " << std::endl;
	}

	//ano = line;

	Data data_auxiliar(line_d,line_m,line_a);
	data_atual = data_auxiliar;

}

Data Data::getData_atual()
{
	return data_atual;
}

Data::Data(std::string d,std::string m, std::string a)
{
	dia = d;
	mes = m;
	ano = a;
}

Data::Data()
{
	dia = "1";
	mes = "1";
	ano = "1";
}

void Data::setDia(std::string d)
{
	dia = d;
}

void Data::setMes(std::string m)
{
	mes = m;
}

void Data::setAno(std::string a)
{
	ano = a;
}

std::string Data::getDia()
{
	return dia;
}

std::string Data::getMes(){
	return mes;
}

std::string Data::getAno(){
	return ano;
}

std::ostream& operator<< (std::ostream &o,Data& data)
{
	o << data.getDia() << "/" << data.getMes() << "/" << data.getAno() << std::endl;
	return o;
}

Data& Data::operator=(Data& data_parametro)
{
	dia = data_parametro.getDia();
	mes = data_parametro.getMes();
	ano = data_parametro.getAno();
	return *this;
}
