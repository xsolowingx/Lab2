#include "../../include/questao1/Funcionario.h"
#include "../../include/questao1/Data.h"
#include <cstdlib>
#include <string>

int Funcionario::totalFuncionarios =0;

int Funcionario::getTotalFuncionarios()
{
	return totalFuncionarios;
}



Funcionario::Funcionario(std::string n,float sal,std::string r, Data dataADM)
{
	nome = n;
	salario = sal;
	rg = r;
	data_de_admissao = dataADM;
	totalFuncionarios++;
}

Funcionario::Funcionario()
{
	nome = "sem nome";
	salario = 0;
	rg = "0";
	experiencia = novato;
	Data data_padrao("2","2","2");
	data_de_admissao = data_padrao;
	totalFuncionarios++;
}

Funcionario::Funcionario(Funcionario& funcionariop)
{
	nome = funcionariop.getNome();
	salario = funcionariop.getSalario();
	rg = funcionariop.getRg();
	experiencia = funcionariop.getExperiencia();
	data_de_admissao = funcionariop.data_de_admissao;
	totalFuncionarios++;
}

void Funcionario::setNome(std::string n)
{
	nome = n;
}

void Funcionario::setSalario(float sal)
{
	salario = sal;
}

void Funcionario::setRg(std::string R)
{
	rg = R;
}

void Funcionario::defineExperiencia(){
	int auxiliar_dataADM_MES,auxiliar_dataAtual_MES;
	int auxiliar_dataADM_ANO,auxiliar_dataAtual_ANO;
	
	auxiliar_dataADM_ANO = stoi(data_de_admissao.getAno());
	auxiliar_dataAtual_ANO = stoi(Data::data_atual.getAno());

	auxiliar_dataADM_MES = stoi(data_de_admissao.getMes());
	auxiliar_dataAtual_MES = stoi(Data::data_atual.getMes());
	
	if(data_de_admissao.getAno() == Data::data_atual.getAno())
	{
		auxiliar_dataADM_MES *= 30;
		auxiliar_dataAtual_MES *= 30;
		
		if( (auxiliar_dataAtual_MES - auxiliar_dataADM_MES) >= 90)
		{
			experiencia = veterano;
			return ;
		}		
		else
		{
			experiencia = novato;
			return ;
		}
	}

	else if( (auxiliar_dataAtual_ANO - auxiliar_dataADM_ANO ) > 1 )
	{
		experiencia = veterano;
		return ;
	}

	else if( (auxiliar_dataAtual_ANO - auxiliar_dataADM_ANO ) == 1 )
	{
		auxiliar_dataADM_MES *= 30;
		auxiliar_dataAtual_MES *= 30;
		auxiliar_dataAtual_MES += 360;

		if( (auxiliar_dataAtual_MES - auxiliar_dataADM_MES) >= 90)
		{
			experiencia = veterano;
			return ;
		}	
		
		else
		{
			experiencia = novato;
			return ;
		}
	}	

}


void Funcionario::setData_de_admissao(Data dataADM)
{
	data_de_admissao = dataADM;
}

void Funcionario::pegaData()
{
	std::string line,dia,mes,ano;
	int d,m,a;

	std::cout << "Por favor digite o dia: " << std::endl;

	while(std::getline(std::cin, line) )
	{
		
		std::stringstream ss(line);
		
		if(ss >> d && ss.eof())
		{

			if( ( d < 1 || d > 30) )
			{
				std::cout << "Dia invalido, os dias vao de 1 a 30. " << std::endl;
			}
			break;
		}
		std::cout << "Dia invalido, os dias sao numeros inteiros que variam de 1  a 30. " << std::endl;
	}

	dia = line;

	std::cout << "Por favor digite o mes: " << std::endl;

	while(std::getline(std::cin, line) )
	{
		
		std::stringstream ss(line);
		
		if(ss >> m && ss.eof())
		{
			if(m < 1 || m > 12)
			{
				std::cout << "Mes invalido, o mes varia de 1 a 12. " << std::endl;
			}
			break;
		}
		std::cout << "Mes invalido, o mes e um inteiro que varia de 1 a 12. " << std::endl;
	}
	
	mes = line;

	std::cout << "Por favor digite o ano: " << std::endl;

	while(std::getline(std::cin, line) )
	{
		
		std::stringstream ss(line);
		
		if(ss >> a && ss.eof())
		{
			if(a < 0 ){
				std::cout << "ano invalido, ano varia de 0 ate o ano atual. " << std::endl;
			}
			break;
		}
		std::cout << "Ano invalido, ano e um inteiro que varia de 0 ate o ano atual. " << std::endl;
	}

	ano = line;

	data_de_admissao.setDia(dia);
	data_de_admissao.setMes(mes);
	data_de_admissao.setAno(ano);
	
}

std::string Funcionario::getNome()
{
	return nome;
}

float Funcionario::getSalario()
{
	return salario;
}

std::string Funcionario::getRg()
{
	return rg;
}

tipoExperiencia Funcionario::getExperiencia()
{
	return experiencia;
}

Data Funcionario::getData_de_admissao()
{
	return data_de_admissao;
}

std::ostream& operator<< (std::ostream& o, Data d)
{
	o << d.getDia() << "/" << d.getMes() << "/" << d.getAno();
	return o;
}

std::ostream& operator<< (std::ostream &o,Funcionario* f)
{
	o << "Nome: " << f->getNome() << std::endl << "RG: " << f->getRg() << std::endl
	<< "Data de adimissao: " << f->getData_de_admissao() << std::endl
	<< "Salario: " << f->getSalario() << std::endl << std::endl;
	return o;
}

Funcionario& Funcionario::operator=(Funcionario& f)
{
	nome = f.getNome();
	salario = f.getSalario();
	rg = f.getRg();
	experiencia = f.getExperiencia();
	data_de_admissao = f.data_de_admissao;
	return *this;
}

bool Funcionario::operator==(Funcionario func)
{
	if(rg == func.getRg())
	{
		return true;
	}
	else
		return false;
}