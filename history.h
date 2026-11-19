#ifndef HISTORY_H
#define HISTORY_H
#include <stdio.h>
#include <time.h>
#define URL_MAX 255
#define INPUT_MAX 1024
typedef struct HistoryNode { char url[URL_MAX+1]; time_t visited_at; struct HistoryNode *prev,*next; } HistoryNode;
extern HistoryNode *head,*tail,*current;
extern size_t history_count;
int read_line(const char *prompt,char *buffer,size_t size);
int read_number(const char *prompt,long *number);
HistoryNode *create_node(const char *url);
void free_forward_branch(void);
void clear_history(void);
void visit_page(void);
void go_back(void);
void go_forward(void);
void show_current(void);
void search_history(void);
void show_history(void);
void delete_history_entry(void);
void show_statistics(void);
#endif
