/** @since 31/08/2017
 * 
 * @date 02/09/2017
 */

#include "../../include/questao1/funcionario.h"
#include <iostream>

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

std::string funcionario::getNome(){
	return nome;
}

data funcionario::getData_de_admissao(){
	return data_de_admissao;
}

tipoExp funcionario::getExp(){
	return exp;
}

void funcionario::setDia(int d){
	data_de_admissao.setDia(d);
}

void funcionario::setMes(int m){
	data_de_admissao.setMes(m);
}

void funcionario::setAno(int a){
	data_de_admissao.setAno(a);
}

int funcionario::getDia(){
	return data_de_admissao.getDia();
}

int funcionario::getMes(){
	return data_de_admissao.getMes();
}

int funcionario::getAno(){
	return data_de_admissao.getAno();
}
std::ostream& operator<< (std::ostream &o,funcionario f){
	o << "Nome: " << f.getNome() << std::endl << "RG: " << f.getRg() << std::endl
	<< "Data de adimissao: " << f.getData_de_admissao() << std::endl
	<< "Salario: " << f.getSalario() << std::endl << std::endl;
	return o;
}

bool funcionario::operator== (funcionario& f){
	if(nome == f.getNome()){
		return true;
	}
	if(rg == f.getRg() ) 
		return true;
	else
		return false;
}

void pegaDados(std::istream& i,funcionario& f,data& dataAtual,std::vector<funcionario>& funcionarios,int & valor_de_retorno3){
	std::string nomeAux;
	float salarioAux;
	int rgAux;


	std::string line;
	std::cout << "Digite o nome do funcionario: " << std::endl;
	i >> nomeAux;
	f.setNome(nomeAux);
	std::cout << "Digite o salario do funcionario: " << std::endl;
	while(std::getline(i , line) ){
		std::stringstream ss(line);
		if(ss >> salarioAux && ss.eof()){
			f.setSalario(salarioAux);
			break;
		}
		std::cout << "Por favor digite um valor 'real' para o salario do funcionario. " << std::endl;
	}
	while(std::getline(i , line) ){
		std::stringstream ss(line);
		if(ss >> rgAux && ss.eof()){
			f.setRg(rgAux);
			break;
		} 
		std::cout << "Por favor digite um valor inteiro para o rg do funcionario sem '.' " << std::endl;
	} 
	if(verificaFuncionario(f,funcionarios) == true ){
		std::cout << "[ERRO]!" << std::endl;
		std::cout << "Funcionario ja pertence a alguma empresa." << std::endl;
		valor_de_retorno3 = -1;
		return ;
	}

	std::cout << std::endl << "Por favor digite a data de adimissao do funcionario: " << std::endl;
	f.pegaData(std::cin, dataAtual);
	f.verificaData(data_de_admissao,dataAtual);
	f.verificaExp(data_de_admissao,dataAtual,f.exp);
}

void listaFuncionario(std::vector<funcionario>::iterator& iterator4){
	std::cout << *iterator4 << std::endl;
}

bool verificaFuncionario(funcionario& f,std::vector<funcionario>& funcionarios){
	for(std::vector<funcionario>::iterator itab = funcionarios.begin(); itab != funcionarios.end() ; itab++){
		if(f == *itab){
			return true;
		}
	}
	return false;
}

void funcionario::setExp(tipoExp topo){
	exp = topo;
}

void funcionario::verificaExp(data& datac, data& dataAtual,tipoExp& exp){

	int aux1,aux2;

	if(datac.getAno() == dataAtual.getAno()){
		aux1 = datac.getMes() * 30;
		aux2 = dataAtual.getMes() * 30;
		
		if( (aux2 - aux1) >= 90 ){
			exp = veterano;
			return ;
		}

		else{
			exp = novato;
			return ;
		}
	}

	if( (dataAtual.getAno() - datac.getAno() ) > 1 ){
		exp = veterano;
		return ;
	}

	if( (dataAtual.getAno() - datac.getAno() ) == 1){
		aux1 = datac.getMes() * 30;
		aux2 = (dataAtual.getMes() * 30) + 360;

		if( (aux2 - aux1) >= 90){
			exp = veterano;
			return ;
		}

		else{
			exp = novato;
			return ;
		}

	}

}

void listaFuncionario_em_periodo_de_experiencia(std::vector<funcionario> iterat7){

	for(std::vector<funcionario>::iterator it5 = iterat7.begin() ; it5 != iterat7.end() ; it5++){
		
		if(it5->getExp() == novato){

			std::cout << "Dados do funcionario: " << std::endl;
			listaFuncionario(it5);

		}
	}
}
