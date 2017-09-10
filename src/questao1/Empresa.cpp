/**
 * @date 09/09/2017
 * @file Empresa.cpp
 * @brief arquivo que contém as implementações da classe Empresa.
 * @since 31/08/2017
 * @author Matheus de Jesus Leandro de Medeiros.
 */
#include "../../include/questao1/Empresa.h"

int Empresa::totalEmpresas= 0;

int Empresa::getTotalEmpresas()
{	
	/*retorna o total de empresas.*/
	return totalEmpresas;
}

Empresa::Empresa()
{
	/*construtor padrão.*/
	nome = "sem nome";
	CNPJ = "sem CNPJ";
	totalEmpresas++;
}

Empresa::Empresa(std::string n,std::string CP)
{
	/*construtor parametrizado.*/
	nome = n;
	CNPJ = CP;
	totalEmpresas++;
}

Empresa::~Empresa()
{
	/*destrutor*/
	for(std::vector<Funcionario*>::iterator it = funcionarios.begin(); it != funcionarios.end() ; it++)
	{
		delete[] *it;
	}
}

void Empresa::setNome(std::string n)
{	
	/*atribui o nome a empresa.*/
	nome = n;
}

void Empresa::setCNPJ(std::string CP)
{	
	/*atribui o CNPJ a empresa.*/
	CNPJ = CP;
}

std::string Empresa::getNome()
{	
	/*retorna o nome da empresa.*/
	return nome;
}

std::string Empresa::getCNPJ()
{
	/*retorna o CNPJ da empresa.*/
	return CNPJ;
}

std::ostream& Empresa::listaFuncionarios(std::ostream& output_aux)
{	
	/*lista os funcionarios da empresa, somente se ela não estiver vazia.*/
	if(funcionarios.empty())
	{
		output_aux << "A empresa nao possui funcionarios. " << std::endl;
		return 	output_aux;

	}

	else
	{
		output_aux << "Esses sao os funcionarios da empresa: " << std::endl << std::endl;

		for(std::vector<Funcionario*>::iterator it = funcionarios.begin(); it != funcionarios.end() ; it++)
		{
			if( (*it)->getExperiencia() == novato )
			{	
				output_aux << *it ;
			}
		}
		return output_aux;
	}	
	return output_aux;
}

void Empresa::listaFuncionarios_em_experiencia()
{	
	/*lista os funcionarios em período de experiência da empresa,somente se a empresa não estiver vazia.*/
	if(funcionarios.empty())
	{
		std::cout << "A empresa nao possui funcionarios. " << std::endl;
	}

	else
	{
		std::cout << "Esses sao os funcionarios da empresa em periodo de experiencia: " << std::endl << std::endl;
		
		for(std::vector<Funcionario*>::iterator it = funcionarios.begin(); it != funcionarios.end() ; it++)
		{
			if( (*it)->getExperiencia() == novato )
			{	
				std::cout << *it ;
			}
		}
	}
}

void Empresa::aumentarSalario(float aum)
{	
	/*da um aumento de "aum" % a todos os funcionarios da empresa.*/

	for(std::vector<Funcionario*>::iterator it = funcionarios.begin(); it != funcionarios.end(); it++)
	{
		float auxiliar_aumento,auxiliar_porcentagem;
		float salario_aumentado;
		auxiliar_aumento = (*it)->getSalario();
		auxiliar_porcentagem = aum / 100;
		auxiliar_porcentagem *= auxiliar_aumento; 
		salario_aumentado = auxiliar_porcentagem + auxiliar_aumento;
		(*it)->setSalario(salario_aumentado);
	}
}

std::ostream& operator<<(std::ostream& output_aux,Empresa& emp)
{	
	/*sobrecarga do operador de inserção.*/
	emp.listaFuncionarios(output_aux);
	return output_aux;
}

void Empresa::listOptions()
{	
	/*mostra o "menu" das opções ao usuário.*/
	std::cout << "(0) Sair do GEF: " << std::endl;
	std::cout << "(1) Criar uma empresa: " << std::endl;
	std::cout << "(2) Atribuir funcionarios a alguma empresa: " << std::endl;
	std::cout << "(3) Listar todos os dados dos funcionarios de alguma empresa: " << std::endl;
	std::cout << "(4) Listar todos os dados dos funcionarios em periodo de experiencia de alguma  empresa: " << std::endl;
	std::cout << "(5) Dar um aumento para os funcionarios de alguma empresa em %:" << std::endl;
	std::cout << "(6) Listar a media de funcionarios por empresa:" << std::endl;
}

std::vector<Funcionario*>::iterator Empresa::getBegin()
{	
	/*retorna o iterador apontando para o começo do vector funcionarios.*/
	return this->funcionarios.begin();
}

std::vector<Funcionario*>::iterator Empresa::getEnd()
{	
	/*retorna o iterador apontando para o fim do vector funcionarios.*/
	return this->funcionarios.end();
}

int Empresa::verificaRG(std::vector<Empresa*> empresas,std::string& rg_funcionario,tipoEstado& estado_rg)
{	
	/*verifica se o rg dado pelo usuário, já não pertence à outro funcionário.*/
	for(std::vector<Empresa*>::iterator itEMP = empresas.begin(); itEMP != empresas.end(); itEMP ++)
	{
		for(std::vector<Funcionario*>::iterator itFUN = (*itEMP)->getBegin(); itFUN != (*itEMP)->getEnd() ; itFUN++)
		{
			if(rg_funcionario == (*itFUN)->getRg() )
			{
				std::cout << "esse RG ja pertence a outra pessoa, por favor digite um diferente" << std::endl;
				estado_rg = errado;
				return -1;
			}
		}
	}
	estado_rg = certo;
	return 1;
}

void Empresa::addFuncionario(std::vector<Empresa*> empresas)
{	/*função que cria e adiciona um funcionário no final do vector de empresas.*/
	std::string nome_funcionario;
	std::string rg_funcionario;

	std::cout << "Digite o nome do funcionario " << std::endl;
	std::cin >> nome_funcionario;
	std::cout << "Digite o RG do funcionario " << std::endl;
	tipoEstado estado_rg;
	long int rg_auxiliar;
	int i = 0;

	while(std::getline(std::cin,rg_funcionario) )
	{
		std::stringstream ss(rg_funcionario);
		
		if(ss >> rg_auxiliar && ss.eof() )
		{
			this->verificaRG(empresas,rg_funcionario,estado_rg);
			
			if(estado_rg == errado)
			{	
				continue;
			}
			
			if(estado_rg == certo)
			{	
				break;
			}
			
		}

		else
		{
			if(i > 0)
			{
				std::cout << "Entrada invalida, o rg so contem numeros inteiros." << std::endl;
				std::cout << "Por favor digite o rg do funcionario: " << std::endl;
			}
			continue;
		}
	}

	std::cout << "Digite o salario do funcionario " << std::endl;
	std::string salario_auxiliar;
	float salario_funcionario;

	while(std::getline( std::cin, salario_auxiliar) )
	{
		std::stringstream ss_salario(salario_auxiliar);

		if(ss_salario >> salario_funcionario && ss_salario.eof())
		{
			break;
		}

		std::cout << "Entrada invalida, o salario e um numero 'real' ." << std::endl;

	}
	Data data_de_admissao;
	this->pegaDataADM(data_de_admissao);

	Funcionario* _funcionario = new Funcionario(nome_funcionario,salario_funcionario,rg_funcionario,data_de_admissao);
	funcionarios.push_back(_funcionario);
}


void Empresa::pegaDataADM(Data& dataADM)
{	
	/*função que pega a data de admissão do funcionário.*/
	std::string line,dia,mes,ano;
	int d,m,a;

	std::cout << "Por favor digite o dia em que o funcionario foi contratado: " << std::endl;

	while(std::getline(std::cin, line) )
	{
		
		std::stringstream ss(line);
		
		if(ss >> d && ss.eof())
		{

			if( ( d < 1 || d > 30) )
			{
				std::cout << "Dia invalido, os dias vao de 1 a 30. " << std::endl;
			}
			break;
		}
		std::cout << "Dia invalido, os dias sao numeros inteiros que variam de 1  a 30. " << std::endl;
	}

	dia = line;

	std::cout << "Por favor digite o mes em que o funcionario foi contratado: " << std::endl;

	while(std::getline(std::cin, line) )
	{
		
		std::stringstream ss(line);
		
		if(ss >> m && ss.eof())
		{
			if(m < 1 || m > 12)
			{
				std::cout << "Mes invalido, o mes varia de 1 a 12. " << std::endl;
			}
			break;
		}
		std::cout << "Mes invalido, o mes e um inteiro que varia de 1 a 12. " << std::endl;
	}
	
	mes = line;

	std::cout << "Por favor digite o ano em que o funcionario foi contratado: " << std::endl;

	while(std::getline(std::cin, line) )
	{
		
		std::stringstream ss(line);
		
		if(ss >> a && ss.eof())
		{
			if(a < 0 ){
				std::cout << "ano invalido, ano varia de 0 ate o ano atual. " << std::endl;
			}
			break;
		}
		std::cout << "Ano invalido, ano e um inteiro que varia de 0 ate o ano atual. " << std::endl;
	}

	ano = line;

	dataADM.setDia(dia);
	dataADM.setMes(mes);
	dataADM.setAno(ano);
}