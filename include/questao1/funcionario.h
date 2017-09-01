/** @since 31/08/2017
 * 
 * @date 31/08/2017
 */
#ifndef funcionario_h
#define funcionario_h

#include <string>
#include "data.h"

class funcionario{
private:
	std::string nome;
	float salario;
	int rg;
	data data_de_admissao;

public:
	
	static int quantidade;
	
	void setNome(std::string a);
	void setSalario(float s);
	void setRg(int i);
	int getRg();
	float getSalario();
	
	std::string getNome();
	data getData_de_admissao();
	
	friend std::ostream& operator<< (std::ostream &o,funcionario const f);

	friend bool operator== (funcionario& const f); 

	friend std::istream& operator>> (std::istream &i,funcionario &f);
		
};




void criarfuncionario();


#endif