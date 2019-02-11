// Implements a dictionary's functionality
//
// +---+      +---+      +---+
// | + |------| A |------| M |------NULL
// +---+      +-+-+      +---+
//              |          |
//              |        +---+
//              |        | A |
//            +---+      +---+
//            | P |        |
//            +-+-+      +---+
//              |        | Y |
//              |        +---+
//              |
//            +---+      +---+                 +---+
//            | + |------| P |-----------------| R |
//            +---+      +---+                 +---+
//                         |                     |
//                       +---+      +---+      +---+
//                       | * |------| P |      | I |
//                       +---+      +---+      +---+
//                                    |          |
//                                  +---+      +---+
//                                  | L |      | L |
//                                  +---+      +---+
//                                    |                        
//                                  +---+                      
//                                  | E |                      
//                                  +---+                      
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#define DictionaryAheadIncl '*'    // Word in dictionary
#define DictionaryAheadExcl '+'    // Word not in dictionary
#define EndOfWord '-'

// structure definitions
typedef struct node1{
	char c;
	struct node1* down;
};
typedef struct node2{
	char c;
	struct node1* down;
	struct node2* next;
};

// Global variables
struct node1* dict;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    struct node1* cur1 = dict;
    struct node2* cur2;
	int cur2_active = 0;
	for(int i=0; word[i]!='\0'; ++i){
		if(cur1->c==DictionaryAheadExcl || cur1->c==DictionaryAheadIncl){
			if(cur2_active){
				if(cur2->down==NULL) return false;
				cur1 = cur2->down;
				if(cur1->c==DictionaryAheadExcl || DictionaryAheadIncl){
					--i;
					cur2_active = false;
				}
				else if(cur1->c!=word[i]) return false;
			}
			else{
				cur2 = (struct node2*)cur1->down;
				
			}
			cur2_active = 1;
			while(cur2->c!=word[i] && cur2->next){
				cur2 = cur2->next;
			}
			if(cur2->c!=word[i]) return false;
		}
	}
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *fptr = fopen(dictionary, "r");
	if(!fptr) return false;
	
	dict = calloc(1, sizeof(struct node1));
	if(!dict){
		return false;
	}
	// dict->c = DictionaryAhead;
	// dict->down
	char c;
	struct node1* cur1 = dict;
	struct node1* prv1;
	struct node2* cur2;
	struct node2* prv2;
	int cur2_active = 0;      // 0-inactive 1-active
	while((c=fgetc(fptr))!=EOF){
		if(c=='\n'){
			cur1 = dict;
			cur2_active = 0;
		}
		else{
			if(!(cur1->down)){
				cur1->down = calloc(1, sizeof(struct node1));
			}
			cur1 = cur1->down;
			if(cur1->c==NULL){
				cur1->c = c;
			}
			else if(cur1->c==DictionaryAheadIncl || cur1->c==DictionaryAheadExcl){
				if(cur1->down==NULL){
					cur1->down = calloc(1, sizeof(struct node2));
					cur1->down->c = c;
				}
				else{
					if(cur2_active==1){
						cur2->down = calloc(1,sizeof(struct node1));
						cur1 = cur2->down;
						cur1->c = c;
						cur2_active = 0;
					}
					else{
						cur2_active = 1;
						cur2 = (struct node2 *)cur1->down;
						while(cur2->next && cur2->next->c!=c){
							cur2 = cur2->next;
						}
						if(cur2->c!=c){
							cur2->next = calloc(1, sizeof(struct node2));
							cur2 = cur2->next;
							cur2->c = c;
						}
					}
				}
			}
			else if(cur1->c!=c){
				struct node2* temp1 = calloc(1, sizeof(struct node2));
				struct node2* temp2 = calloc(1, sizeof(struct node2));
				temp1->c = cur1->c;
				temp2->c = c;
				temp1->next = temp2;
				temp1->down = cur1->down;
				cur1->c = (cur1->down) ? DictionaryAheadExcl : DictionaryAheadIncl;
				cur1->down = temp1;
				cur2 = temp2;
				cur2_active = 1;
			}
		}
	}
	return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
