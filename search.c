#include "history.h"
#include <string.h>
#include <ctype.h>
static int contains_ci(const char *text,const char *pattern){size_t m=strlen(pattern);if(!m)return 1;for(;*text;text++){size_t i=0;while(i<m&&text[i]&&tolower((unsigned char)text[i])==tolower((unsigned char)pattern[i]))i++;if(i==m)return 1;}return 0;}
static void stamp(time_t t,char *out,size_t size){struct tm *v=localtime(&t);if(v)strftime(out,size,"%Y-%m-%d %H:%M:%S",v);else snprintf(out,size,"unknown");}
void search_history(void){char term[INPUT_MAX];if(!read_line("Search URL (full or partial): ",term,sizeof term))return;if(!term[0]){puts("Search term cannot be empty.");return;}size_t pos=0,matches=0;for(HistoryNode *p=head;p;p=p->next){pos++;if(contains_ci(p->url,term)){char timebuf[32];stamp(p->visited_at,timebuf,sizeof timebuf);printf("#%zu  %s  | %s%s\n",pos,p->url,timebuf,p==current?"  [CURRENT]":"");matches++;}}if(!matches)puts("No matching history entries.");printf("Search complexity: O(n) simplified; naive substring comparisons can take O(n × L).\n");}
