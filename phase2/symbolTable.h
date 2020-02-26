#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define SIZE 100
#define SCOPE_RANGE 10

int tableIndex = 0;
int currentScope = 0;

// struct for each symbol table entry 
typedef struct symbolTableEntry{
	
	char *lexeme;
	double value;
	int dataType;
	struct symbolTableEntry* successor;

} symbolTableEntry;

// struct for scopewise symbol table and pointer to parent scope.

typedef struct symbolTableCollection{

	symbolTableEntry **symbolTable;
	int parent;

} symbolTable_Collection;

// extern - so that it can be shared between lex and yacc.
// this is creating an array of pointer to pointer to symbolTable of size 10.
// hence we are limiting to a scope depth of 10 for the input program.
extern symbolTable_Collection symbolTableCollection[SCOPE_RANGE];

// create a symbol table
symbolTableEntry **createTable() {

	// create pointer to pointer to symbol table.
	symbolTableEntry **symbolTable_ptr = NULL;
	symbolTable_ptr = (symbolTableEntry**)malloc(sizeof(symbolTableEntry*) * SIZE);
	
	for(int i=0;i<SIZE;i++){
		symbolTable_ptr[i] = NULL;
	}
	return symbolTable_ptr;
}

//  create new scope when code falls in a scope level deeper.
int createNewScope(){
	
	tableIndex++;
	symbolTableCollection[tableIndex].symbolTable = createTable();
	symbolTableCollection[tableIndex].parent = currentScope;

	return tableIndex;
}

// exit from current scope when code falls out of a scope.
int exitScope(){
	return symbolTableCollection[currentScope].parent;
}

// create an entry for a token (identifier). Called when Inserting a new token.
symbolTableEntry *createEntry(char *lexeme, int value, int dataType){

	// allocate space for new entry.
	symbolTableEntry *newEntry;
	newEntry = (symbolTableEntry*)malloc(sizeof(symbolTableEntry));
	
	// insert values in entry fields.
	newEntry->lexeme = strdup(lexeme);
	newEntry->value = value;
	newEntry->dataType = dataType;
	newEntry->successor = NULL;

	return newEntry;
}

// hash function to hash the lexeme. Sum of ascii of all characters % SIZE.
uint32_t getHash(char *lexeme){

	uint32_t hash = 0;
	size_t i;
	for(i=0;i<strlen(lexeme);i++){
		hash = hash + (int)(lexeme[i]);
	}
	hash = hash % SIZE;
	return hash;
}

/* search for an entry matching the given lexeme.
Return pointer to the entry if found else return NULL */
symbolTableEntry *searchLexeme(symbolTableEntry **symbolTable_ptr, char *lexeme){

	uint32_t index = 0;
	symbolTableEntry *entry;

	index = getHash(lexeme);	//get hashed index based on lexeme
	
	entry = symbolTable_ptr[index];
	
	// loop until not null or until same lexeme isn't found.	
	while(entry!=NULL && strcmp(entry->lexeme,lexeme)!=0)
		entry = entry -> successor;

	return entry;	// NULL if not found, lexeme itself otherwise.
}

// check for the lexeme across all scope-wise symbol tables.
symbolTableEntry *searchAcrossTables(char* lexeme){
	int index = currentScope;
	symbolTableEntry *search = NULL;
	
	while(index != -1){
		search = searchLexeme(symbolTableCollection[index].symbolTable, lexeme);
		if(search != NULL)
			return NULL;
		index = symbolTableCollection[index].parent;	
	}
	return search;
}

// insert new entry into hashtable. (checks first if same lexeme exists or not)
symbolTableEntry *insertEntry(symbolTableEntry **symbolTable_ptr, char *lexeme, int value, int datatype){
	
	symbolTableEntry *exists = searchLexeme(symbolTable_ptr,lexeme);
	if(exists == NULL)
		return exists;	// if entry already exists, do not insert again.

	uint32_t index;
	symbolTableEntry *newEntry = NULL, *head = NULL;
	index = getHash(lexeme);
	
	newEntry = createEntry(lexeme,value,datatype);	//allocate memory, insert lexeme and value.
	head = symbolTable_ptr[index];
	
	if(head == NULL)
		head = newEntry;
	else
		newEntry->successor = head;
		head = newEntry;

	return head;
}
