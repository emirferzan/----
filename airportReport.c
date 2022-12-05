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


int main(int argc, char **argv) {
   Airport *airportOne = createAirport("XA85",
                                        "small_airport",
                                        "Cougar Landing Airport",
                                        31.633301,
                                        -97.316704,
                                        595,
                                        "Waco", "US-TX");

  Airport *airportTwo = createAirport("28NC",
                                        "balloonport",
                                        "Balloonport of Greensboro Balloonport",
                                        35.955799,
                                        -79.818901,
                                        800,
                                        "Greensboro", "US-NC");
   Airport *airportThree = createAirport("EPML",
                                        "small_airport",
                                        "Mielec Airport",
                                        50.322300,
                                        21.462099,
                                        548,
                                        "None", "PL-PK");

   Airport *airportFour = createAirport("UAKK",
                                        "large_airport",
                                        "Sary-Arka Airport",
                                        49.670799,
                                        73.334396,
                                        1765,
                                        "Karaganda", "KZ-KAR");
   Airport *airportFive = createAirport("5OR1",
                                        "heliport",
                                        "Helitradewinds Heliport",
                                        45.141201,
                                        -122.621002,
                                        360,
                                        "Molala", "US-OR");

    Airport *stops = (Airport *) malloc(sizeof(Airport) * 5);
    initAirport(&stops[0], airportOne->gpsId, airportOne->type, airportOne->name,
    airportOne->latitude, airportOne->longitude, airportOne->elevationFeet,
    airportOne->city, airportOne->countryAbbrv);
    initAirport(&stops[1], airportTwo->gpsId, airportTwo->type, airportTwo->name,
    airportTwo->latitude, airportTwo->longitude, airportTwo->elevationFeet,
    airportTwo->city, airportTwo->countryAbbrv);
    initAirport(&stops[2], airportThree->gpsId, airportThree->type, airportThree->name,
    airportThree->latitude, airportThree->longitude, airportThree->elevationFeet,
    airportThree->city, airportThree->countryAbbrv);
    initAirport(&stops[3], airportFour->gpsId, airportFour->type, airportFour->name,
    airportFour->latitude, airportFour->longitude, airportFour->elevationFeet,
    airportFour->city, airportFour->countryAbbrv);
    initAirport(&stops[4], airportFive->gpsId, airportFive->type, airportFive->name,
    airportFive->latitude, airportFive->longitude, airportFive->elevationFeet,
    airportFive->city, airportFive->countryAbbrv);
    generateReports(stops, 5);


    return 0;
}