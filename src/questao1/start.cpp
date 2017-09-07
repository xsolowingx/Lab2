/** @since 31/08/2017
 * 
 * @date 02/09/2017
 */
#include <iostream>
#include <string>

void start(std::vector<*empresa>& empresas,std::vector<*empresa>::iterator& ite,int& valor_de_retorno1,int& valor_de_retorno2,int& i,data& dataAtual,int& valor_de_retorno3){
	
	std::cout << "Bem vindo ao GEF(Gerenciamento de Empresas e Funcionarios)!" << std::endl;
	std::cout << "Por favor digite a data atual " << std::endl;
	pegaDataAtual(std::cin,dataAtual);
	std::cout << "Digite 's' para criar uma empresa ou 'n' para sair do programa. " << std::endl;
	std::string line;
	std::string option;
	
	while(std::getline(std::cin,option)){
		if(option == "n"){
			std::cout<<"saindo..."<<std::endl;
			valor_de_retorno1 = -1;
			return ;
		}
		if(option == "s"){
			break;
		}
		std::cout<<"opção inválida, por favor digite 's' para criar uma empresa ou 'n' para sair. "<<std::endl;
	}
	
	while(valor_de_retorno2 != -1){
		criarEmpresa(empresas,valor_de_retorno2,ite,i,dataAtual,valor_de_retorno3);
		ite++;
		i++;
	}	
	
	std::cout << "Deseja listar os dados de todos os funcionarios de alguma empresa?" << std::endl;
	
	std::string option1;
	tipo tipos1;
	int posicao;

	while(std::getline(std::cin,option1)){
		
		if(option1 == "n"){
			break;
		}
		
		if(option1 == "s"){
			tipos1 = ajudante;
		}
		
		if( (option1 != "s") && (option1 != "n") ){
			std::cout<<"opção inválida, por favor digite 's' para listar os dados de todos os funcionarios de alguma 
			empresa ou 'n' para ir para a proxima opcao. "<<std::endl << std::endl;
			continue;
		}

		if(tipos1 == ajudante){
		
			std::string option2;
			tipo tipos2;
			std::vector<*empresa>::iterator iterat3;
			
			std::cout << "Por favor digite o nome da  empresa: " << std::endl;

			while(std::getline(std::cin,option2)){
				
				for(std::vector<*empresa>::iterator iterat2 = empresas.begin() ; iterat2 != empresas.end() ; iterat2++){
					if(option2 == (*iterat2->getNome())){
						tipos2 = certo;
						iterat3 = iterat2;
						break;
					}
				}

				if(tipos2 == certo){
					break;
				}

				std::cout << "Empresa nao encontrada. Por favor digite o nome da empresa exatamente igual a alguma existente." << std::endl << std::endl;
				listaEmpresas(empresas);
			}
		}

		if(tipos2 == certo){

			std::cout << "Os funcionarios da empresa " << option2 << "sao: " << std::endl << std::endl;
			listaFuncionarios(iterat3);
			std::cout << "Voce deseja ver todos os dados dos funcionarios de alguma outra empresa?" << std::endl;

			continue ;
		
		}
	}
	
	std::cout << "Voce deseja da um aumento no salario de todos os funcionarios de alguma empresa?" << std::endl << std::endl;

	std::string option3;
	tipo tipos3;

	while(std::getline(std::cin,option3)){
		
		if(option3 == "n"){
			break;
		}

		if(option3 == "s"){
			tipos3 = certo;
			break;
		}

		std::cout << "Opcao invalida. Por favor digite 's' para da um aumento no salario de todos os funcionarios de alguma empresa ou 'n' para nao da." << std::endl;
	
	}
	
	std::vector<*empresa>::iterator iterat4;
	tipo tipos4;
	std::string option4;
	float aux_aumento;

	if(tipos3 == certo){

		std::cout << "Por favor selecione a empresa que voce deseja da o aumento no salario de todos os funcionarios." << std::endl << std::endl;
		
		while(std::getline(std::cin,option4)){
			
			for(std::vector<*empresa>::iterator iterat6 = empresas.begin() ; iterat6 != empresas.end() ; iterat6++){
	
				if(option4 == (*iterat6.getNome())){	
					tipos4 = certo;
					iterat4 = iterat6;
					break;
				}	
			}

			if(tipos4 == certo){
				break;
			}

			std::cout << "Empresa nao encontrada. Por favor digite o nome da empresa exatamente igual a alguma existente." << std::endl << std::endl;
			listaEmpresas(empresas);

		}

		if(tipos4 == certo){
			std::cout << "O aumento sera de quantos %%?" << std::endl;
			while(std::getline(std::cin,option4)){
				
				std::stringstream ss(option4);
				
				if(ss >> aux_aumento && ss.eof()){
					break;
				}

				std::cout << "Numero invalido. o aumento deve ser um numero real variando de 0.00 a 100.0 ." << std::endl;
			}
			
			*iterator4.aumento(aux_aumento);
		}
	}

	std::cout << "Voce deseja listar todos os funcionarios em periodo de experiencia?" << std::endl << std::endl;

	tipo tipos5;
	std::string option5;

	while(std::getline(std::cin,option5)){

		if(option5 == "n"){
			break;
		}

		if(option5 == "s"){
			tipos5 = correto;
			break;
		}

		std::cout << "[ERRO]!" << std::endl;
		std::cout << "Por favor digite 's' para listar os funcionarios em periodo de experiencia ou 'n' para nao listar. " << std::endl << std::endl;
	}

	std::vector<*empresa>::iterator iterat8;

	if(tipos5 == correto){
		
		tipo tipos6;

		std::cout << "Voce deseja listar os funcionarios em periodo de experiencia de qual empresa?" << std::endl;
		
		while(std::getline(std::cin,option5)){
			
			for(std::vector<*empresa>::iterator iterat7 = empresas.begin() ; iterat7 != empresas.end() ; iterat7++){

				if(option5 == (*iterat7.getNome() ) ){
					tipos6 = certo;
					iterat8 = iterat7;
					break;
				}

			}

			if(tipos6 == certo){
				break;
			}		

		}

		listaFuncionario_em_periodo_de_experiencia(iterat8);

	}
}	