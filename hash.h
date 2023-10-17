#ifndef HASH_H	
#define HASH_H	

enum status {
	ST_SUC,
	ER_INS,
	ER_MEM
};
#define TAB_SZ 10
struct data {
	int hash ;
	char name [20];
	short age ;
	char msg [100];
};
typedef int hash_t ;
typedef struct data data_t;


void del_user(data_t *dp);
void print_all_data ();
void print_data ( data_t *data );
hash_t hash(char * ch );
short insert_data();
data_t* get_id();
#endif 
