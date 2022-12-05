#include <time.h>


typedef struct {
  char *title;
  char *link;
  char *date;
  char *description;
} Rss;

/**
 * A factory function to create an empty RSS feed
 * with "default" values
 */
Rss* createEmptyRss();

/**
 * A factory function to create an Rss structure
 * with the given values
 */
Rss* createRss(const char* title,
               const char* link,
               const char* date,
               const char* description);

/**
 * An initialization function to initialize an RSS feed with the
 * given values.
 */
void initRss(Rss *feed,
             const char* title,
             const char* link,
             const char* date,
             const char* description);

/**
 * A function that prints the given Rss structure
 * to the standard output.
 */
void printRss(const Rss* item);


/**
this function  will turn the given input to
a string
*/
// char *rssToString(const Rss *rss);
