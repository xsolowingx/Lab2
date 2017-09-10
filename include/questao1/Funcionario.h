#ifndef Funcionario_h
#define Funcionario_h

#include "../../include/questao1/Data.h"

typedef enum st_tipos
{
	novato,
	veterano
}tipoExperiencia;

class Funcionario
{

protected:

	std::string nome;
	float salario;
	std::string rg;
	tipoExperiencia experiencia;
	Data data_de_admissao;

public:

	static int totalFuncionarios;
	static int getTotalFuncionarios();

	Funcionario(std::string n,float sal,std::string r,Data dataADM);
	Funcionario();
	Funcionario(Funcionario* funcionario);
	
	void setNome(std::string n);
	void setSalario(float sal);
	void setRg(std::string R);
	void defineExperiencia();
	void setData_de_admissao(Data dataADM);

	std::string getNome();
	float getSalario();
	std::string getRg();
	tipoExperiencia getExperiencia();
	Data getData_de_admissao();

	friend std::ostream& operator<< (std::ostream& o, Funcionario* f);
	friend std::ostream& operator<< (std::ostream& o, Data& d);
	bool operator==(Funcionario func);
	Funcionario& operator=(Funcionario& f);

};



#endif