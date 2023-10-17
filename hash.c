#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

data_t *table[TAB_SZ];
int data_count = 0;
/*
int main(){
	char name [20];
	while(1){
		printf("%d",get_id());
	}
	return 0;	
}
*/
void main(){
	int count = 0;
	printf("\n\nDATABASE PROGRAM\n\n"); 
	while (1){
		system("clear");
		printf("\nEnter Command\nx-exit,\ti-insert,\tp-print,\td-delete\t: "); 
		int cmd  = getc(stdin);
		switch (cmd){
			case 'x':
				printf("\nProgram Terminated .. ! \n"); 
				return;
			case 'i':
				printf("\nInsert Data .. ! \n"); 
				insert_data();
				break;
			case 'd':
				printf("\nDelete Data.. ! \n"); 
				del_user( get_id() );
				break;
			case 'p':
				printf("\nPrint Data.. ! \n"); 
				print_all_data();
				break;
		}
		fflush(stdin);
		getc(stdin);
	}
}

void del_user(data_t *dp){
	if ( dp == NULL || dp->hash == -1){
		return;}
	table[dp->hash] = NULL;		// free mem
	free( dp );
	data_count--;
}

void print_all_data (){
	for (int i = 0; i < TAB_SZ; ++i){
		print_data( table[i] );
		printf("\n"); }
}

void print_data ( data_t *data ){
	if ( data == NULL || data == 0 || data->hash == -1){
		return; }
		printf("\nCustomer hash	: %d", 		data->hash);
		printf("\nCustomer Name : %s", 		data->name);
		printf("\nCustomer Age : %hd", 		data->age);
		printf("\nCustomer Description : %s", 	data->msg);
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
	hash_t hash_d;
	hash_d = sum % TAB_SZ;	// randomize and limit to hash table size
	return hash_d;
}

short insert_data(){
	data_t * data  = malloc( sizeof(data_t) );
	if ( data == NULL ){
		printf("\nMem alloc failed.. ! ");
		return ER_MEM; }
	printf("\nEnter name :");
	scanf (" %s", data->name);
	data_count++;
	hash_t hash_d = hash( data->name );
	if ( table[hash_d] != NULL ){
		printf("\n Insert Failed, data exists ..:");
		free (data);
		return ER_INS; }
	table[hash_d] = data;
	data->hash = hash_d;
	printf("\n hash : %d",data->hash);
	printf("\nEnter age:");
	scanf (" %hd", &data->age);
	printf("\nEnter Message:");
	scanf (" %s", data->msg);
	return ST_SUC;
}

data_t* get_id(){
	char name [20];
	printf("\nEnter name :");
	scanf (" %s", name);
	int id = hash (name);
	return table[id];
}
