/** @since 31/08/2017
 * 
 * @date 02/09/2017
 */
#include "empresa.h"


void criarempresa(std::vector<*empresa>& empresas,int& valor_de_retorno2,std::vector<*empresa>::iterator& ite,int& i,data& dataAtual,int& valor_de_retorno3){
	
	if(i > 0){
		empresas.push_back(new empresa());
	}

	tipo tipos = certo;

	std::cout << "Por favor digite o nome da empresa. " << std::endl;
	std::string nick;
	int cp;
	
	while(std::getline( std::cin, nick) ){/*!< Garante que o nome da empresa não terá números e
	                                       * verifica se já existe outra empresa com esse nome.*/

		std::stringstream ss(nick);
		
		if(ss >> cp){
			std::cout << "Nome de empresa invalida, por favor digite somente letras no nome." << std::endl;
			continue;
		}
		
		for(std::vector<*empresa>::iterator it = empresas.begin(); it != empresas.end(); it++){
			if( nick == (**it->getNome()) ){
				std::cout << "Nome de empresa repitida, por favor digite um nome diferente e que contenha so letras: " << std::endl;
				tipos = errado;
				break;
			}
			if( (it + 1 ) == empresas.end()){
				tipos = certo;
				std::cout << "Por favor digite o CPNJ da empresa: " << std::endl;
			}
		}
		
		if(tipos == errado){
			continue;
		}

		if(tipos == certo){
			break;
		}
	
	}

	std::string line;

	while(std::getline( std::cin , line) ){/*!< garante que o cpnj só será atribuido pelo usuário,
	                                        *se ele digitar um número inteiro.*/
		std::stringstream ss1(line);
		if(ss1 >> cp && ss1.eof() ){
			
			for(std::vector<*empresa>::iterator it = empresas.begin(); it != empresas.end(); it++){
				if( cp == (**it->CPNJ) ){
					std::cout << "CPNJ de empresa repitido, por favor digite um CPNJ diferente: " << std::endl << std::endl;
					tipos = errado;
					break;
				}
				if( (it + 1 ) == empresas.end()){
					tipos = certo;
				}
			}

			if(tipos == errado){
				std::cout << "O CPNJ de uma empresa e um numero inteiro e unico." << std::endl;
				std::cout << "Por favor digite o cpnj da empresa" << std::endl << std::endl;
				continue;
			}

			if(tipos == certo){
				empresas[i].setNome(nick);
				empresas[i].setCPNJ(cp);
				i++;
				break;
			}
		}

		std::cout << std::endl << "[ERRO] entrada invalida! " << std::endl << std::endl;
	    std::cout << "Por favor digite um numero inteiro: "<< std::endl << std::endl;
	}

	std::string option;
	int k = 1;
	int l = 0;
	
	while(option != "n"){

		std::cout << "Por favor digite o nome,salario,rg e data de admissao, nessa ordem do funcionario " << k << "da empresa"
		<< **ite->getNome() << std::endl;
		criarfuncionario(option,empresas,ite,dataAtual,l,valor_de_retorno3);
		
		if(option == n){
			break;
		}

		k++;
		if(valor_de_retorno3 != -1){
			l++;
		}
	}

	std::cout << "Voce deseja criar outra empresa?" << std::endl;
	std::string option1;

	while(std::getline(std::cin,option1)){
		if(option1 == "n"){
			valor_de_retorno2 = -1;
			return ;
		}
		if(option1 == "s"){
			return ;
		}
		std::cout<<"opção inválida, por favor digite 's' para criar outra empresa ou 'n' para nao criar mais empresas. "<<std::endl;
	}

}