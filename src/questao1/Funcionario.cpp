/**
 * @date 09/09/2017
 * @file Funcionario.cpp
 * @brief arquivo que contém as implementações da classe Funcionario.
 * @since 31/08/2017
 * @author Matheus de Jesus Leandro de Medeiros.
 */
#include "../../include/questao1/Funcionario.h"
#include "../../include/questao1/Data.h"
#include <cstdlib>
#include <string>
#include <iomanip>

int Funcionario::totalFuncionarios =0;

int Funcionario::getTotalFuncionarios()
{	
	/*retorna o total de funcionários.*/
	return totalFuncionarios;
}



Funcionario::Funcionario(std::string n,float sal,std::string r, Data dataADM)
{	
	/*construtor parametrizado.*/
	nome = n;
	salario = sal;
	rg = r;
	data_de_admissao = dataADM;
	totalFuncionarios++;
}

Funcionario::Funcionario()
{
	/*construtor padrão.*/
	nome = "sem nome";
	salario = 0;
	rg = "0";
	experiencia = novato;
	Data data_padrao("2","2","2");
	data_de_admissao = data_padrao;
	totalFuncionarios++;
}

Funcionario::Funcionario(Funcionario* funcionario)
{	
	/*construtor copia onde o parâmetro é um ponteiro de objeto.*/
	nome = funcionario->getNome();
	salario = funcionario->getSalario();
	rg = funcionario->getRg();
	experiencia = funcionario->getExperiencia();
	data_de_admissao = funcionario->data_de_admissao;
	totalFuncionarios++;
}

void Funcionario::setNome(std::string n)
{	
	/*atribui o nome ao funcionário.*/
	nome = n;
}

void Funcionario::setSalario(float sal)
{	
	/*atribui o salario ao funcionário.*/
	salario = sal;
}

void Funcionario::setRg(std::string R)
{
	/*atribui o rg ao funcionário.*/
	rg = R;
}

void Funcionario::defineExperiencia()
{
	/*função que define se o funcionário está em período de experiência ou não.*/
	int auxiliar_dataADM_MES,auxiliar_dataAtual_MES;
	int auxiliar_dataADM_ANO,auxiliar_dataAtual_ANO;
	
	auxiliar_dataADM_ANO = stoi(data_de_admissao.getAno());
	auxiliar_dataAtual_ANO = stoi(Data::data_atual.getAno());

	auxiliar_dataADM_MES = stoi(data_de_admissao.getMes());
	auxiliar_dataAtual_MES = stoi(Data::data_atual.getMes());
	
	if(data_de_admissao.getAno() == Data::data_atual.getAno())
	{
		auxiliar_dataADM_MES *= 30;
		auxiliar_dataAtual_MES *= 30;
		
		if( (auxiliar_dataAtual_MES - auxiliar_dataADM_MES) >= 90)
		{
			experiencia = veterano;
			return ;
		}		
		else
		{
			experiencia = novato;
			return ;
		}
	}

	else if( (auxiliar_dataAtual_ANO - auxiliar_dataADM_ANO ) > 1 )
	{
		experiencia = veterano;
		return ;
	}

	else if( (auxiliar_dataAtual_ANO - auxiliar_dataADM_ANO ) == 1 )
	{
		auxiliar_dataADM_MES *= 30;
		auxiliar_dataAtual_MES *= 30;
		auxiliar_dataAtual_MES += 360;

		if( (auxiliar_dataAtual_MES - auxiliar_dataADM_MES) >= 90)
		{
			experiencia = veterano;
			return ;
		}	
		
		else
		{
			experiencia = novato;
			return ;
		}
	}	

}


void Funcionario::setData_de_admissao(Data dataADM)
{	
	/*atribui a data de admissão.*/
	data_de_admissao = dataADM;
}


std::string Funcionario::getNome()
{
	/*retorna o nome do funcionário.*/
	return nome;
}

float Funcionario::getSalario()
{
	/*retorna o salário.*/
	return salario;
}

std::string Funcionario::getRg()
{	
	/*retorna o rg.*/
	return rg;
}

tipoExperiencia Funcionario::getExperiencia()
{
	/*retorna experiencia do funcionário(novato ou veterano).*/	
	return experiencia;
}

Data Funcionario::getData_de_admissao()
{
	/*retorna a data de admissão.*/
	return data_de_admissao;
}

std::ostream& operator<< (std::ostream& o, Data d)
{	
	/*sobrecarga do operador de inserção da classe Data.*/
	o << d.getDia() << "/" << d.getMes() << "/" << d.getAno();
	return o;
}

std::ostream& operator<< (std::ostream &o,Funcionario* f)
{	
	/*sobrecarga do operador de inserção da classe Funcionario.*/
	o<< std::setprecision(2) << std::fixed << "Nome: " << f->getNome() << std::endl << "RG: " << f->getRg() << std::endl
	<< "Data de adimissao: " << f->getData_de_admissao() << std::endl
	<< "Salario: R$" << f->getSalario() << std::endl << std::endl;
	return o;
}

Funcionario& Funcionario::operator=(Funcionario& f)
{	
	/*sobrecarga do operador de atribuição da classe Funcionario.*/
	nome = f.getNome();
	salario = f.getSalario();
	rg = f.getRg();
	experiencia = f.getExperiencia();
	data_de_admissao = f.data_de_admissao;
	return *this;
}

bool Funcionario::operator==(Funcionario func)
{
	/*sobrecarga do operador de igualdade da classe funcionário.*/
	if(rg == func.getRg())
	{
		return true;
	}
	else
		return false;
}