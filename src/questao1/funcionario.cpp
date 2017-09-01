/** @since 31/08/2017
 * 
 * @date 31/08/2017
 */
#include "../../include/questao1/funcionario.h"

void funcionario::setNome(std::string a){
	nome = a;
}

void funcionario::setSalario(float s){
	salario = s;
}

void funcionario::setRg(int i){
	rg = i;
}

float funcionario::getSalario(){
	return salario;
}

int funcionario::getRg(){
	return rg;
}

std::string getNome(){
	return nome;
}

data funcionario::getData_de_admissao(){
	return data_de_admissao;
}

std::ostream& operator<< (std::ostream &o,funcionario const f){
	o << "O nome do funcionario e: " << f.getNome() << std::endl
	<< "O rg do funcionario e: " << f.getRg() << std::endl
	<< "A data de adimissao do funcionario e: " << f.getData_de_admissao() << std::endl
	<< "O salario do funcionario e: " << f.getSalario() << std::endl << std::endl;
	return o;
}

bool operator== (funcionario& const f){
	if(nome == f.getNome()){
		return true;
	}
	else 
		return false;
}

std::istream& operator>> (std::istream &i,funcionario &f){
	i >> f.nome >> f.salario >> f.rg >> f.data_de_admissao;
	return i;
}