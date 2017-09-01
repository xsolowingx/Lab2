/** @since 31/08/2017
 * 
 * @date 31/08/2017
 */

#ifndef data_h
#define data_h

class data{
	private:
		int dia;
		int mes;
		int ano;	
	public:
		data(int d,int m,int a);
		int getDia();
		int getMes();
		int getAno();

		friend std::ostream& operator<< (std::ostream &o,data const datad);

		friend std::istream& operator>> (std::istream &i,data &date);
};

#endif