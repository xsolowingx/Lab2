/** @since 31/08/2017
 * 
 * @date 02/09/2017
 */

#include "../../include/questao1/funcionario.h"


void criarfuncionario(std::string& opcao,std::vector<empresa>& const empresas,std::vector<empresa>::iterator& ite,data& dataAtual,int& l,int& valor_de_retorno3){

	if(l > 0){
		empresas.acrescentaFuncionario();
	}
	
	std::vector<*funcionario>::iterator it1 = ite->funcionarios.begin();
	
	pegaDados(std::cin,it1,dataAtual,valor_de_retorno3);
	
	if(valor_de_retorno3 == -1){
		return ;
	}
	
	std::cout << "Voce deseja atribuir mais funcionarios a essa empresa?" << std::endl << std::endl;
	while(std::getline(std::cin,opcao)){
		if(opcao == "n"){
			return ;
		}
		if(opcao == "s"){
			break;
		}
		std::cout<<"opção inválida, por favor digite 's' para atribuir mais funcionarios ou 'n' para nao atribuir mais funcionarios. "<<std::endl;
	}	
}