#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "rss.h"



Rss * createEmptyRss() {
    return createRss("", "", "", "");
}

Rss * createRss(const char * title, const char * link, const char * date, const char * description) {
    Rss *rss = (Rss *)malloc(sizeof(Rss) * 1);



  rss->title = (char *)malloc(sizeof(char) * (strlen(title) + 1));
  strcpy(rss->title, title);

  rss->link = (char *)malloc(sizeof(char) * (strlen(link) + 1));
  strcpy(rss->link, link);


  rss->description = (char *)malloc(sizeof(char) * (strlen(description) + 1));
  strcpy(rss->description, description);

  rss->date = (char *)malloc(sizeof(char) * (strlen(date) + 1));
  strcpy(rss->date, date);


  return rss;

}

void initRss(Rss *feed, const char* title, const char* link, const char* date,
               const char* description) {

   feed->title = (char *)malloc(sizeof(char) * (strlen(title) + 1));
  strcpy(feed->title, title);

  feed->link = (char *)malloc(sizeof(char) * (strlen(link) + 1));
  strcpy(feed->link, link);

  feed->description = (char *)malloc(sizeof(char) * (strlen(description) + 1));
  strcpy(feed->description, description);

  feed->date = (char *)malloc(sizeof(char) * (strlen(date) + 1));
  strcpy(feed->date, date);

  return;
}



void printRss(const Rss * item) {
  printf("<channel>\n\t<item>\n\t<title>%s</title>\n\t<link>%s</link>\n\t<description>%s</description>\n\t<date>%s/</date>\n\t</item>\n</channel>\n", item->title, item->link, item->description, item->date);
  return;
}
