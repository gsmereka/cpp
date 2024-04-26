#ifndef NEWCLASS_H
# define NEWCLASS_H

class NewClass 
{
	public:
		NewClass(void);
		~NewClass(void);
		NewClass(const NewClass &obj);
		NewClass& operator = (const NewClass &obj);   
	private:
		NewClass	*XXX();
	// Atributes

	// Methods


};
#endif
