/** @since 31/08/2017
 * 
 * @date 01/09/2017
 */
#include "../../include/questao1/empresa.h"

empresa::empresa(std::string n,int C){
	nome = n;
	CPNJ = C;
}

std::string empresa::getNome(){
	return nome;
}

int empresa::getCPNJ(){
	return CPNJ;
}

void empresa::aumento(float aum){
	for(std::vector<funcionario>::iterator it = funcionarios.begin(); it != funcionarios.end(); it++){
		float salario_aumentado;
		salario_aumentado =(*it.getSalario()) +  (*it->getSalario * aum);
		*it->setSalario(salario_aumentado);
	}
}

std::ostream& operator <<(std::ostream& o,empresa& const emp){
 o << "Nome da empresa:  " << emp.getNome() << "CPNJ da empresa:  " << emp.getCPNJ() << std::endl;
return o;

}


void listaEmpresa(std::vector<*empresa>& empresas){
	for(std::vector<*empresa>::iterator ite2 = empresas.begin() ; ite2 != empresas.end() ; ite2++){
		std::cout << **ite2;
	}
}


void listaFuncionarios(std::vector<*empresa>::iterator& iterat3){
	int i =1;

	for(std::vector<funcionario>::iterator it3 = *iterat3->funcionarios.begin() ; it3 != *iterat3->funcionarios.end() ; it3++){
		std::cout << "Dados do funcionario" << i << std::endl;
		listaFuncionario(it3);
		i++;
	}
}