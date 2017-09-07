#include "../../include/questao1/Empresa.h"

int Empresa::totalEmpresas= 0;

Empresa::Empresa()
{
	nome = "sem nome";
	CNPJ = "sem CNPJ";
	totalEmpresas++;
}

Empresa::Empresa(std::string n,std::string CP)
{
	nome = n;
	CNPJ = CP;
	totalEmpresas++;
}

Empresa::~Empresa()
{
	for(std::vector<Funcionario*>::iterator it = funcionarios.begin(); it != funcionarios.end() ; it++)
	{
		delete[] *it;
	}
}

void Empresa::addFuncionario(Funcionario* func)
{
	funcionarios.push_back(func);
}


void Empresa::setNome(std::string n)
{
	nome = n;
}

void Empresa::setCNPJ(std::string CP)
{
	CNPJ = CP;
}

std::string Empresa::getNome()
{
	return nome;
}

std::string Empresa::getCNPJ()
{
	return CNPJ;
}

void Empresa::listaFuncionarios()
{
	for(std::vector<Funcionario*>::iterator it = funcionarios.begin(); it != funcionarios.end() ; it++)
	{
		std::cout << *it ;
	}
}

void Empresa::listaFuncionario_em_experiencia()
{
	for(std::vector<Funcionario*>::iterator it = funcionarios.begin(); it != funcionarios.end() ; it++)
	{
		if( (*it)->getExperiencia() == novato )
		{	
			std::cout << *it ;
		}
	}
}

void Empresa::aumento(float aum)
{
	for(std::vector<Funcionario*>::iterator it = funcionarios.begin(); it != funcionarios.end(); it++)
	{
		float auxiliar_aumento,auxiliar_porcentagem;
		float salario_aumentado;
		auxiliar_aumento = (*it)->getSalario();
		auxiliar_porcentagem = aum / 100;
		auxiliar_porcentagem *= auxiliar_aumento; 
		salario_aumentado = auxiliar_porcentagem + auxiliar_aumento;
		(*it)->setSalario(salario_aumentado);
	}
}