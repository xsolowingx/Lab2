#include <iostream>
#include "../../include/questao1/Data.h"
#include "../../include/questao1/Funcionario.h"
#include "../../include/questao1/Empresa.h"
#include "../../include/questao1/instanciamento.h"

int main()
{
	std::cout << "Bem vindo ao GEF(Gerenciamento de Empresas e Funcionarios)!" << std::endl;
	std::vector<Empresa> empresas;
	std::cout << "Digite a data atual " << std::endl;
	Data::atribuiData_atual();
	std::cout << "Voce deseja criar uma empresa? digite 's' para sim ou 'n' para nao" << std::endl;
	
	std::string option_criar_empresa;

	while(std::getline(std::cin,option_criar_empresa))
	{
		
		if(option_criar_empresa == "n")
		{
			break;
		}

		if(option_criar_empresa == "s")
		{	
			criarEmpresa(empresas);
			
		}
		std::cout<<"opcao inválida, por favor digite 's' para criar uma empresa ou 'n' para sair. "<<std::endl;
	}

	if(empresas.empty())
	{
		std::cout << "Saindo..." << std::endl;
		return 1;
	}

	return 0;
}