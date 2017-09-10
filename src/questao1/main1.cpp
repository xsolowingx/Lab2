/**
 * @date 09/09/2017
 * @file main1.cpp
 * @brief arquivo principal do programa.
 * @details nesse arquivo, é onde são executadas as opções que o usuário seleciona do "menu". 
 * @since 31/08/2017
 * @author Matheus de Jesus Leandro de Medeiros.
 */
#include <iostream>
#include "../../include/questao1/Data.h"
#include "../../include/questao1/Funcionario.h"
#include "../../include/questao1/Empresa.h"

int main()
{
	std::cout << "Bem vindo ao GEF(Gerenciamento de Empresas e Funcionarios)!" << std::endl;
	std::vector<Empresa*> empresas;
	std::cout << "Digite a data atual " << std::endl;
	Data::atribuiData_atual();
	std::cout << "O que você deseja fazer?" << std::endl<< std::endl;
	Empresa::listOptions();
		
	std::string opcao_do_usuario_auxiliar;
	int opcao_do_usuario;
	
	int TotalFuncionarios = Funcionario::getTotalFuncionarios();
	int TotalEmpresas = Empresa::getTotalEmpresas();
	int media_funcionarios_por_empresa;

	while(std::getline(std::cin , opcao_do_usuario_auxiliar))
	{
		opcao_do_usuario = stoi(opcao_do_usuario_auxiliar);

		switch (opcao_do_usuario)
		{
			case 0:
			{
				/*sai do programa.*/
				std::cout << "Saindo..." << std::endl;
				return 1;
			}

			case 1:
			{
				/*cria uma empresa*/
				tipoEstado auxiliar_nome;
				std::cout << "Por favor digite o nome da empresa contendo so letras " << std::endl;
				std::string nome_empresa;
				long int nome_auxiliar ;
				/*atribuição do nome da empresa.*/
				while(std::getline( std::cin,nome_empresa) )
				{
					std::stringstream ss_nome(nome_empresa);

					auxiliar_nome = certo;

					if(ss_nome >> nome_auxiliar )
					{
						std::cout << "Nome de empresa invalida, por favor digite so letras no nome." << std::endl;
						continue;
					}

					for(std::vector<Empresa*>::iterator it = empresas.begin(); it != empresas.end() ; it++)
					{
						if(nome_empresa == (*it)->getNome() )
						{
							std::cout << "Nome de empresa repitida, por favor digite um nome diferente: " << std::endl;
							auxiliar_nome = errado;
							break;
						}
					}

					if(auxiliar_nome == errado)
					{
						continue;
					}

					if(auxiliar_nome != errado)
					{
						break;
					}

				}
				/*atribuição do CNPJ da empresa.*/
				std::cout << "Por favor digite o CNPJ da empresa contendo so numeros: " << std::endl;
				long int CNPJ_auxiliar;
				std::string CNPJ_empresa;
				tipoEstado auxiliar_CNPJ;

				while(std::getline( std::cin, CNPJ_empresa) )
				{
					std::stringstream ss_CNPJ(CNPJ_empresa);

					auxiliar_CNPJ = certo;

					if( ss_CNPJ >> CNPJ_auxiliar && ss_CNPJ.eof() )
					{
						for(std::vector<Empresa*>::iterator it = empresas.begin(); it != empresas.end() ; it++)
						{
							if(CNPJ_empresa == (*it)->getCNPJ() )
							{
								std::cout << "ERRO!"<< std::endl << "esse CNPJ ja pertence a outra empresa " << std::endl;
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

						if(auxiliar_CNPJ != errado)
						{
							empresas.push_back(new Empresa(nome_empresa,CNPJ_empresa));
							std::cout << std::endl << std::endl;
							break;
						}
					}

					std::cout << std::endl << "[ERRO] entrada invalida! " << std::endl << std::endl;
				    std::cout << "Por favor digite um numero inteiro: "<< std::endl << std::endl;
				}	
				
				std::cout << "O que você deseja fazer agora?" << std::endl<< std::endl;
				Empresa::listOptions();

				break;
			}

			case 2:
			{
				/*Atribui funcionarios a alguma empresa.*/
				if(empresas.empty())
				{
					std::cout << "Voce nao criou uma empresa ainda " << std::endl<< std::endl;
					std::cout << "Essas sao as opcoes: " << std::endl << std::endl; 
					Empresa::listOptions();
					break;
				}
				/*procura a empresa que o usuário quer atribuir funcionários.*/
				std::cout << "Por favor digite o nome da empresa que voce deseja atribuir os funcionarios: " << std::endl;
				std::string nome_empresa_atribuir_funcionarios;
				tipoEstado auxiliar_nome_empresa_atribuir_funcionarios;

				while(std::getline(std::cin , nome_empresa_atribuir_funcionarios))
				{
					for(std::vector<Empresa*>::iterator it = empresas.begin(); it != empresas.end(); it++)
					{
						if(nome_empresa_atribuir_funcionarios == (*it)->getNome() )
						{
							std::cout << "Empresa encontrada " << (*it)->getNome() << std::endl;
							
							(*it)->addFuncionario(empresas);

							auxiliar_nome_empresa_atribuir_funcionarios = certo;
							break;
						}
					}
				
					if(auxiliar_nome_empresa_atribuir_funcionarios == certo)
					{
						break;
					}
					
					if(auxiliar_nome_empresa_atribuir_funcionarios != certo)
					{
						std::cout << "Empresa nao encontrada " << std::endl << std::endl;
						std::cout << "Por favor digite o nome da empresa que voce deseja atribuir os funcionarios: " << std::endl;
						continue;
					}
				}

				std::cout << "O que você deseja fazer agora?" << std::endl<< std::endl;
				Empresa::listOptions();

				break;
			}
			
			case 3:
			{
				/*lista todos os funcionarios de alguma empresa.*/
				if(empresas.empty())
				{
					std::cout << "Voce nao criou uma empresa ainda " << std::endl<< std::endl;
					std::cout << "Essas sao as opcoes: " << std::endl << std::endl;
					Empresa::listOptions();
					break;
				}

				std::cout << "Por favor digite o nome da empresa que voce deseja ver os funcionarios: " << std::endl;
				std::string nome_empresa_list_normal;
				tipoEstado auxiliar_list_normal;	
				/*procura a empresa que o usuário deseja listar os funcionários.*/
				while(std::getline(std::cin , nome_empresa_list_normal))
				{
					auxiliar_list_normal = errado;

					for(std::vector<Empresa*>::iterator it = empresas.begin(); it != empresas.end(); it++)
					{
						if(nome_empresa_list_normal == (*it)->getNome() )
						{
							std::cout << "Empresa encontrada " << (*it)->getNome() << std::endl;
							std::cout << **it;
							auxiliar_list_normal = certo;
							break ;
						}
					}
					
					if(auxiliar_list_normal == certo)
					{
						break;
					}
					
					if(auxiliar_list_normal != certo)
					{
						std::cout << "Empresa nao encontrada " << std::endl << std::endl;
						std::cout << "Por favor digite o nome da empresa que voce deseja ver os funcionarios: " << std::endl;
						continue;
					}
				}	
					
				std::cout << "O que você deseja fazer agora?" << std::endl<< std::endl;
				Empresa::listOptions();

				break;
			}

			case 4:
			{
				/*lista todos os dados dos funcionarios em período de experiência de alguma empresa.*/
				if(empresas.empty())
				{
					std::cout << "Voce nao criou uma empresa ainda " << std::endl << std::endl;
					std::cout << "Essas sao as opcoes: " << std::endl << std::endl;
					Empresa::listOptions();
					break;
				}	
				
				std::cout << "Por favor digite o nome da empresa para verificar os"
				<< " funcionarios em periodo de experiência: " << std::endl;
				
				std::string nome_empresa_list_periodo_experiencia;
				tipoEstado auxiliar_list__periodo_experiencia;
				/*procura a empresa que o usuário deseja listar os funcionários em período de experiência.*/
				while(std::getline(std::cin , nome_empresa_list_periodo_experiencia))
				{
					for(std::vector<Empresa*>::iterator it = empresas.begin(); it != empresas.end(); it++)
					{
						if(nome_empresa_list_periodo_experiencia == (*it)->getNome() )
						{
							std::cout << "Empresa encontrada " << (*it)->getNome() << std::endl;
							(*it)->listaFuncionarios_em_experiencia();
							auxiliar_list__periodo_experiencia = certo;
							break;
						}
					}

					if(auxiliar_list__periodo_experiencia == certo)
					{
						break;
					}

					if(auxiliar_list__periodo_experiencia != certo)
					{
						std::cout << "Empresa nao encontrada " << std::endl << std::endl;
						std::cout << "Por favor digite o nome da empresa que voce deseja ver"
						<<" os funcionarios em periodo de experiência: " << std::endl;
						continue;
					}
				}	
				std::cout << "O que você deseja fazer agora?" << std::endl<< std::endl;
				Empresa::listOptions();
				break;
			}
				
			case 5:
			{
				/*da um aumento para todos os funcionarios de alguma empresa.*/
				if(empresas.empty())
				{
					std::cout << "Voce nao criou uma empresa ainda " << std::endl << std::endl;
					std::cout << "Essas sao as opcoes: " << std::endl << std::endl;
					Empresa::listOptions();
					break;
				}

				std::cout << "Por favor digite o nome da empresa que voce deseja efetuar um aumento: " << std::endl;
				
				std::string nome_empresa_aumento;
				std::string auxiliar_aumento;
				tipoEstado auxiliar_aumento_estado;
				float aumento;
				/*procura a empresa que o usuário deseja dar um aumento aos seus funcionários.*/
				while(std::getline(std::cin , nome_empresa_aumento))
				{
					for(std::vector<Empresa*>::iterator it = empresas.begin(); it != empresas.end(); it++)
					{
						if(nome_empresa_aumento == (*it)->getNome() )
						{
								
							std::cout << "Empresa encontrada " << (*it)->getNome() << std::endl;
							std::cout << "Por favor digite a porcentagem do aumento que voce deseja da. " << std::endl;

							while(std::getline(std::cin , auxiliar_aumento))
							{
								std::stringstream ss_aumento(auxiliar_aumento);
									
								if(ss_aumento >> aumento && ss_aumento.eof())
								{
									(*it)->aumentarSalario(aumento);
									auxiliar_aumento_estado = certo;
									break;
								}
									
								std::cout << "entrada invalida!" << std::endl;
								std::cout << "O aumento e efetuado em cima de um numero real." << std::endl;
							}
						
							if(auxiliar_aumento_estado == certo)
							{
								break;		
							}
						}
					}

					if(auxiliar_aumento_estado == certo)
					{
						break;
					}

					if(auxiliar_aumento_estado != certo)
					{
						std::cout << "Empresa nao encontrada " << std::endl;
						std::cout << "Por favor digite o nome da empresa que voce deseja efetuar um aumento: " << std::endl;
						continue;
					}
				}
				std::cout << "O que você deseja fazer agora?" << std::endl<< std::endl;
				Empresa::listOptions();

				break;
			}

			case 6:
			{
				/*exibe a média de funcionários por empresa.*/

				if(empresas.empty())
				{
					std::cout << "Voce nao criou uma empresa ainda " << std::endl<< std::endl;
					std::cout << "Essas sao as opcoes: " << std::endl << std::endl;
					Empresa::listOptions();
					break;
				}
				/*garante que não irá fazer um divisão por zero.*/
				if(Funcionario::getTotalFuncionarios() > 0)
				{
					TotalFuncionarios = Funcionario::getTotalFuncionarios();
					TotalEmpresas = Empresa::getTotalEmpresas();
					media_funcionarios_por_empresa = TotalFuncionarios / TotalEmpresas;
				}
				
				std::cout << std::endl << "A media de funcionarios por empresa e de: " << media_funcionarios_por_empresa << std::endl;

				std::cout << "O que você deseja fazer agora?" << std::endl << std::endl;
				Empresa::listOptions();
				
				break;
			}

			default:
			{	
				/*opção padrão, caso o usuário não digite um número entre (0 e 6).*/
				std::cout << "Opcao invalida " << std::endl<< std::endl;
				std::cout << "Essas sao as opcoes: " << std::endl << std::endl;
				Empresa::listOptions();
					
				break;
			}
		} 
	}
}
