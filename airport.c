#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "airport.h"

/**
 * Author: Emir Ferzan
 * 2022/12/02
 *
 * this program generates several reports of the existing airports
    it makes several comparisons and sorts them accordingly
 */

char *deepStringCopy(const char *s) {
    char *copy = (char *) malloc( sizeof(char) * (strlen(s) +1 ) );
    strcpy(copy, s);
    return copy;
}

Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv) {
      if(gpsId == NULL || type == NULL || name == NULL || city == NULL || countryAbbrv == NULL) {
        return NULL;
      }

      if(latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180) {
        return NULL;
      }
        Airport *airport = (Airport *) malloc(sizeof(Airport));
        initAirport(airport, gpsId, type, name, latitude, longitude, elevationFeet,
                city, countryAbbrv);
        return airport;

                       }


void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv) {
    if(gpsId == NULL || type == NULL || name == NULL || city == NULL || countryAbbrv == NULL) {
        return;
    }

    if(latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180) {
        return;
    }

    airport->gpsId = deepStringCopy(gpsId);

    airport->type = deepStringCopy(type);

    airport->name = deepStringCopy(name);

    airport->latitude = latitude;

    airport->longitude = longitude;

    airport->elevationFeet = elevationFeet;

    airport->city = deepStringCopy(city);

    airport->countryAbbrv = deepStringCopy(countryAbbrv);
                 }




char* airportToString(const Airport* a) {
  if (a == NULL) {
    char *resultError = (char *)malloc(sizeof(char) * 5);
    strcpy(resultError, "NULL");
    return resultError;
    }

   char buffer[1000];
   sprintf(buffer, "Gps Id: %s\nType: %s\nName: %s\nLocation: [%f, %f]\nElevation: %d\nCity: %s\nCountry: %s\n", a->gpsId,
            a->type, a->name, a->latitude, a->longitude,
            a->elevationFeet, a->city, a->countryAbbrv);
    char *str = (char *) malloc(sizeof(char) * (strlen(buffer)+1));
    strcpy(str, buffer);
    return str;
}

double getAirDistance(const Airport* origin, const Airport* destination) {
    if(origin == NULL || destination == NULL) {
        return 0;
    }
    double latA = origin->latitude;
    double logA = origin->longitude;
    double latB = destination->latitude;
    double logB = destination->longitude;
    if(latA < -90 || latA > 90 || latB < -90 || latB > 90  ||
     logA < -180 || logA > 180 || logB < -180 || logB > 180) {
        return 0;
    }


    double radianLat = (latA / 180.0) * (M_PI);
    double radianLog = (logA / 180.0) * (M_PI);
    double radianLatB = (latB / 180.0) * (M_PI);
    double radianLogB = (logB / 180.0) * (M_PI);

    double diff = (radianLogB - radianLog);
    double distanceFormula = acos((sin(radianLat) * sin(radianLatB)) + (cos(radianLat) * cos(radianLatB) * cos(diff))) * (6371);
    return distanceFormula;
}

double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs) {

    if(stops == NULL || size < 0 || aveKmsPerHour < 0 || aveLayoverTimeHrs <= 0) {
        return 0;
    }

    double totalKM;
    double kmToHour = 0;
    double totalDist = 0;


    for(int i=0; i<size; i++) {
        if(i+1 <= size-1 ) {
        totalKM = getAirDistance(&stops[i], &stops[i+1]);
        kmToHour = (totalKM / aveKmsPerHour);
        totalDist += kmToHour;
        }
    }
    totalDist = totalDist + (aveLayoverTimeHrs * (size-2));
    return totalDist;
                              }

int cmpByGPSId(const void* a, const void* b) {
    const Airport *g1 = (const Airport *)a;
    const Airport *g2 = (const Airport *)b;
    return strcmp(g1->gpsId, g2->gpsId);
}

int cmpByType(const void* a, const void* b) {
    const Airport *t1 = (const Airport *)a;
    const Airport *t2 = (const Airport *)b;
    return strcmp(t1->type, t2->type);
}

int cmpByName(const void* a, const void* b) {
    const Airport *n1 = (const Airport *)a;
    const Airport *n2 = (const Airport *)b;
    return strcmp(n1->name, n2->name);
}

int cmpByNameDesc(const void* a, const void* b) {
    return cmpByName(b,a);
}

int cmpByCountryCity(const void* a, const void* b) {
    const Airport *co1 = (const Airport *)a;
    const Airport *co2 = (const Airport *)b;
    if (strcmp(co1->countryAbbrv, co2->countryAbbrv) == 0) {
    return strcmp(co1->city, co2->city);
  } else {
    return strcmp(co1->countryAbbrv, co2->countryAbbrv);
  }

}

int cmpByLatitude(const void* a, const void* b) {
    const Airport *l1 = (const Airport *)a;
    const Airport *l2 = (const Airport *)b;
    if(l1->latitude < l2->latitude) {
    return 1;
  } else if(l1->latitude > l2->latitude) {
    return -1;
  } else {
    return 0;
  }
}

int cmpByLongitude(const void* a, const void* b) {
    const Airport *lo = (const Airport *)a;
    const Airport *lo2 = (const Airport *)b;
    if(lo->longitude < lo2->longitude) {
    return -1;
  } else if(lo->longitude > lo2->longitude) {
    return 1;
  } else {
    return 0;
  }
}

int cmpByLincolnDistance(const void* a, const void* b){
    Airport *lincoln = createAirport("",
                                        "",
                                        "",
                                        40.846176,
                                        -96.75471,
                                        0,
                                        "", "");
    const Airport *one = (const Airport *)a;
    const Airport *two = (const Airport *)b;
    double lincolnDist = getAirDistance(one, lincoln);
    double lincolnDistTwo = getAirDistance(two, lincoln);
    if(lincolnDist < lincolnDistTwo) {
    return 1;
  } else if(lincolnDist > lincolnDistTwo) {
    return -1;
  } else {
    return 0;
  }


}



void printAllAirports(Airport *airports, int size) {
  int i;

  for (i = 0; i < size; i++) {
    printf("-+-+-+-Airport %d+-+-+-+\n", i+1);
    char *ai = airportToString(&airports[i]);
    printf("%s\n", ai);
  }
  printf("\n\n");
}

void generateReports(Airport *airports, int n) {
    printf("Originial Order: \n");
    printAllAirports(airports, n);
    printf("(Quick) Sorted by gpsID: \n");
    qsort(airports, n, sizeof(Airport), cmpByGPSId);
    printAllAirports(airports, n);

    printf("(Quick) Sorted by type: \n");
    qsort(airports, n, sizeof(Airport), cmpByType);
    printAllAirports(airports, n);

    printf("(Quick) Sorted by name: \n");
    qsort(airports, n, sizeof(Airport), cmpByName);
    printAllAirports(airports, n);

    printf("(Quick) Reverse Sorted by name: \n");
    qsort(airports, n, sizeof(Airport), cmpByNameDesc);
    printAllAirports(airports, n);

    printf("(Quick) Reverse Sorted by name: \n");
    qsort(airports, n, sizeof(Airport), cmpByNameDesc);
    printAllAirports(airports, n);

    printf("(Quick) Sorted by Country then city: \n");
    qsort(airports, n, sizeof(Airport), cmpByCountryCity);
    printAllAirports(airports, n);

    printf("(Quick) Sorted by latitude: \n");
    qsort(airports, n, sizeof(Airport), cmpByLatitude);
    printAllAirports(airports, n);

    printf("(Quick) Sorted by longitude: \n");
    qsort(airports, n, sizeof(Airport), cmpByLongitude);
    printAllAirports(airports, n);

    printf("(Quick) Sorted by their distance from lincoln: \n");
    qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);
    printAllAirports(airports, n);




    printf("Searching for the west-east median Airport \n");
    qsort(airports, 5, sizeof(Airport), cmpByLatitude);
    if(n%2 == 0) {
      Airport *aiPortEven = bsearch(&airports[(n/2)+1], airports, n, sizeof(Airport), cmpByLatitude);
      char *resultE = airportToString(aiPortEven);
      printf("%s", resultE);
    } else {
    Airport *aiPort = bsearch(&airports[n/2], airports, n, sizeof(Airport), cmpByLatitude);
    char *result = airportToString(aiPort);
    printf("%s", result);
    }

    Airport newKey;
    initAirport(&newKey, "", "", "", 0, 0, 0, "New York", "US");
    qsort(airports, n, sizeof(Airport), cmpByCountryCity);
    Airport *aiNew = bsearch(&newKey, airports, n, sizeof(Airport), cmpByCountryCity);
    if(aiNew == NULL) {
      printf("Unforunately could not find the airport\n");
    } else {
      printf("Successful Search!\n");
    }

    Airport largekey;
    initAirport(&largekey, "", "large_airport", "", 0, 0, 0, "", "");
    qsort(airports, n, sizeof(Airport), cmpByType);
    Airport *largeFound = bsearch(&largekey, airports, n, sizeof(Airport), cmpByType);
    if(largeFound == NULL) {
      printf("Unforunately could not find the airport\n");
    } else {
      printf("Successful Search!\n");
    }
}