#ifndef HASH_H	
#define HASH_H	

enum status {
	ST_SUC,
	ER_INS,
	ER_MEM
};
#define TAB_SZ 100
struct data {
	int hash ;
	char name [20];
	short age ;
	char msg [100];
};
typedef int hash_t ;
typedef struct data data_t;
void print_data ( data_t *data , int count);
short insert_data(data_t * data ,int count);
hash_t hash(char * ch );
data_t get_data( char *ch, data_t * dp );
void del_user();

#endif 
