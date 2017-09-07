#include "../../include/questao1/instanciamento.h"
#include <sstream>

void criarEmpresa(std::vector<Empresa>& empresas)
{
	Empresa empresa_criada;
	tipoEstado auxiliar_nome;

	std::cout << "Por favor digite o nome da empresa. " << std::endl;
	std::string nome_empresa;
	int inteiro;

	while(std::getline( std::cin,nome_empresa) )
	{
		std::stringstream ss_nome(nome_empresa);

		if(ss_nome >> inteiro)
		{
			std::cout << "Nome de empresa invalida, por favor digite so letras no nome." << std::endl;
			continue;
		}

		for(std::vector<Empresa>::iterator it = empresas.begin(); it != empresas.end() ; it++)
		{
			if(nome_empresa == it->getNome() )
			{
				std::cout << "Nome de empresa repitida, por favor digite um nome diferente e que contenha so letras: " << std::endl;
				auxiliar_nome = errado;
				break;
			}
		}

		if(auxiliar_nome == errado)
		{
			continue;
		}

		else
		{
			break;
		}

	}

	std::cout << "Por favor digite o CPNJ da empresa: " << std::endl;

	std::string CNPJ_empresa;
	tipoEstado auxiliar_CNPJ;

	while(std::getline( std::cin, CNPJ_empresa) )
	{
		std::stringstream ss_CNPJ(CNPJ_empresa);

		if( ss_CNPJ >> inteiro && ss_CNPJ.eof() )
		{
			for(std::vector<Empresa>::iterator it = empresas.begin(); it != empresas.end() ; it++)
			{
				if(CNPJ_empresa == it->getCNPJ() )
				{
					std::cout << "CNPJ de empresa repitida, por favor digite um CNPJ diferente " << std::endl;
					auxiliar_CNPJ = errado;
					break;
				}
			}

			if(auxiliar_CNPJ == errado)
			{
				std::cout << "O CPNJ de uma empresa e um numero inteiro e unico." << std::endl;
				std::cout << "Por favor digite o CNPJ da empresa" << std::endl << std::endl;
				continue;
			}

			else
			{
				empresa_criada.setNome(nome_empresa);
				empresa_criada.setCNPJ(CNPJ_empresa);
			}
		}

		std::cout << std::endl << "[ERRO] entrada invalida! " << std::endl << std::endl;
	    std::cout << "Por favor digite um numero inteiro: "<< std::endl << std::endl;
	}


}