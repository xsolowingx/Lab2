/** @since 31/08/2017
 * 
 * @date 31/08/2017
 */
#include "../../include/questao1/empresa.h"

empresa::empresa(std::string n,int C){
	nome = n;
	CPNJ = C;
}

void empresa::aumento(float aum){
	for(std::vector<funcionario>::iterator it = funcionarios.begin(); it != funcionarios.end(); it++){
		float salario_aumentado;
		salario_aumentado = (*it.getSalario) * aum;
		*it.setSalario(salario_aumentado);
	}
}