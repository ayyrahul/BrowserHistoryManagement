#include "history.h"
#include <stdlib.h>
#include <string.h>
HistoryNode *head=NULL,*tail=NULL,*current=NULL;
size_t history_count=0;
int read_line(const char *prompt,char *buffer,size_t size){
 if(!buffer||size<2) return 0;
 fputs(prompt,stdout);
 fflush(stdout);
 if(!fgets(buffer,(int)size,stdin))return 0;
 size_t n=strlen(buffer);
 if(n && buffer[n-1]=='\n'){buffer[--n]='\0'; if(n&&buffer[n-1]=='\r')buffer[--n]='\0';return 1;}
 if(n==size-1){int c;while((c=getchar())!='\n'&&c!=EOF){}; puts("Input too long; please try again.");buffer[0]='\0';return 0;}
 return 1;
}
int read_number(const char *prompt,long *number){char line[INPUT_MAX],*end; if(!read_line(prompt,line,sizeof line))return 0; if(!line[0])return 0; long v=strtol(line,&end,10);while(*end==' '||*end=='\t')end++;if(end==line||*end)return 0;*number=v;return 1;}
HistoryNode *create_node(const char *url){HistoryNode *n=malloc(sizeof *n);if(!n)return NULL;snprintf(n->url,sizeof n->url,"%s",url);n->visited_at=time(NULL);n->prev=n->next=NULL;return n;}
void free_forward_branch(void){if(!current)return;HistoryNode *p=current->next;current->next=NULL;tail=current;while(p){HistoryNode *next=p->next;free(p);if(history_count)history_count--;p=next;}}
void clear_history(void){HistoryNode *p=head;while(p){HistoryNode *next=p->next;free(p);p=next;}head=tail=current=NULL;history_count=0;}
