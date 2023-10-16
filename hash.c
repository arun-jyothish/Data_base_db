#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


void main(){
	int count = 0;
	printf("\n\nDATABASE PROGRAM\n\n"); 
	data_t *d1 = (data_t *)malloc ( sizeof (struct data)) ;
	while (1){
		system("clear");
		printf("\nEnter Command\nx-exit,\ti-insert,\tp-print,\td-delete\t: "); 
		int cmd  = getc(stdin);
		switch (cmd){
			case 'x':
				printf("\nProgram Terminated .. ! \n"); 
				return;
			case 'i':
				count ++;
				printf("\nInsert Data .. ! \n"); 
				insert_data( d1 ,count);
				break;
			case 'd':
				printf("\nDelete Data.. ! \n"); 
				del_user(d1);
				return;
			case 'p':
				printf("\nPrint Data.. ! \n"); 
				print_data(d1, count);
				return;
		}
	}
}

void del_user(data_t *dp){
	char name [20];
	printf("\nEnter name :");
	scanf (" %s", name);
	dp[hash(name)].hash = -1;
}

void print_data ( data_t *data , int count){
	for (int i = 0; i < count; ++i){
		printf("\nCustomer Name : %s", 		data[i].name);
		printf("\nCustomer Age : %hd", 		data[i].age);
		printf("\nCustomer Description : %s", 	data[i].msg);
	}
}

hash_t hash(char * ch ){
	int sum = 0, i = 0;		
	while ( ch[i] != '\0'){
		sum *= ch[i];
		sum += ch[i];
		i++;
		if ( i > 20 ){
			printf("hash failed ... more than 20 characters\n");
			return -1; }
	}
	hash_t hash;
	hash = sum * 31 % TAB_SZ;	// randomize and limit to hash table size
	return hash;
}

short insert_data(data_t * data,int count ){
	data = realloc ( data, sizeof(data_t)* count );
	if ( data == NULL ){
		printf("\nMem alloc failed.. ! ");
		return ER_MEM; }
	if ( data == NULL ) return -1;
	printf("\nEnter name :");
	scanf (" %s", data->name);
	hash_t hash_d = hash( data->name );
	if ( data[hash_d].hash == hash_d ){
		printf("\n Insert Failed, data exists ..:");
		return ER_INS; }
	printf("\nEnter age:");
	scanf (" %hd", &data->age);
	printf("\nEnter Message:");
	scanf (" %s", data->msg);
return ST_SUC;
}
data_t get_data( char *ch, data_t * dp ){
	hash_t hash_da = hash (ch);
	return dp[hash_da];
}
