#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "airport.h"


int main(int argc, char **argv) {



    Airport *airportOne = createAirport("XA85",
                                        "small_airport",
                                        "Cougar Landing Airport",
                                        31.633301,
                                        -97.316704,
                                        595,
                                        "Waco", "US-TX");

    if((strcmp(airportOne->gpsId, "XA85") == 0) &&
        (strcmp(airportOne->type, "small_airport") == 0) &&
        (strcmp(airportOne->name, "Cougar Landing Airport") == 0)
        && (airportOne->latitude == 31.633301) && (airportOne->longitude == -97.316704)
        && (airportOne->elevationFeet == 595) &&
        (strcmp(airportOne->city, "Waco") == 0) &&
        (strcmp(airportOne->countryAbbrv, "US-TX") == 0)) {
            printf("PASSED: Succesfully created an airport!\n");
        } else {
            printf("FAILED\n");
        }

    Airport *airportTwo = createAirport("28NC",
                                        "balloonport",
                                        "Balloonport of Greensboro Balloonport",
                                        35.955799,
                                        -79.818901,
                                        800,
                                        "Greensboro", "US-NC");

    if((strcmp(airportTwo->gpsId, "28NC") == 0) &&
        (strcmp(airportTwo->type, "balloonport") == 0) &&
        (strcmp(airportTwo->name, "Balloonport of Greensboro Balloonport") == 0)
        && (airportTwo->latitude == 35.955799) && (airportTwo->longitude == -79.818901)
        && (airportTwo->elevationFeet == 800) &&
        (strcmp(airportTwo->city, "Greensboro") == 0) &&
        (strcmp(airportTwo->countryAbbrv, "US-NC") == 0)) {
            printf("PASSED: Succesfully created an airport!\n");
        } else {
            printf("FAILED\n");
        }

        Airport *airportThree = createAirport("EPML",
                                        "small_airport",
                                        "Mielec Airport",
                                        50.322300,
                                        21.462099,
                                        548,
                                        "None", "PL-PK");

    if((strcmp(airportThree->gpsId, "EPML") == 0) &&
        (strcmp(airportThree->type, "small_airport") == 0) &&
        (strcmp(airportThree->name, "Mielec Airport") == 0)
        && (airportThree->latitude == 50.322300) && (airportThree->longitude == 21.462099)
        && (airportThree->elevationFeet == 548) &&
        (strcmp(airportThree->city, "None") == 0) &&
        (strcmp(airportThree->countryAbbrv, "PL-PK") == 0)) {
            printf("PASSED: Succesfully created an airport!\n");
        } else {
            printf("FAILED\n");
        }
        Airport *airportFour = createAirport("UAKK",
                                        "large_airport",
                                        "Sary-Arka Airport",
                                        49.670799,
                                        73.334396,
                                        1765,
                                        "Karaganda", "KZ-KAR");

    if((strcmp(airportFour->gpsId, "UAKK") == 0) &&
        (strcmp(airportFour->type, "large_airport") == 0) &&
        (strcmp(airportFour->name, "Sary-Arka Airport") == 0)
        && (airportFour->latitude == 49.670799) && (airportFour->longitude == 73.334396)
        && (airportFour->elevationFeet == 1765) &&
        (strcmp(airportFour->city, "Karaganda") == 0) &&
        (strcmp(airportFour->countryAbbrv, "KZ-KAR") == 0)) {
            printf("PASSED: Succesfully created an airport!\n");
        } else {
            printf("FAILED\n");
        }
        Airport *airportFive = createAirport("5OR1",
                                        "heliport",
                                        "Helitradewinds Heliport",
                                        45.141201,
                                        -122.621002,
                                        360,
                                        "Molalla", "US-OR");

    if((strcmp(airportFive->gpsId, "5OR1") == 0) &&
        (strcmp(airportFive->type, "heliport") == 0) &&
        (strcmp(airportFive->name, "Helitradewinds Heliport") == 0)
        && (airportFive->latitude == 45.141201) && (airportFive->longitude == -122.621002)
        && (airportFive->elevationFeet == 360) &&
        (strcmp(airportFive->city, "Molalla") == 0) &&
        (strcmp(airportFive->countryAbbrv, "US-OR") == 0)) {
            printf("PASSED: Succesfully created an airport!\n");
        } else {
            printf("FAILED\n");
        }
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Testing airportToString function");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("       First Airport: \n");
    char *testOne = airportToString(airportOne);
    printf("%s", testOne);
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("       Second Airport: \n");
    char *testTwo = airportToString(airportTwo);
    printf("%s", testTwo);
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("       Third Airport: \n");
    char *testThree = airportToString(airportThree);
    printf("%s", testThree);
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("       Fourth Airport: \n");
    char *testFour = airportToString(airportFour);
    printf("%s", testFour);
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("       Fifth Airport: \n");
    char *testFive = airportToString(airportFive);
    printf("%s", testFive);

    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("Distance between first and fifth airport:\n");
    double testAir = getAirDistance(airportOne, airportFive);
    printf("%lf km\n", testAir);

    printf("Distance between second and fourth airport:\n");
    double testAirTwo = getAirDistance(airportTwo, airportFour);
    printf("%lf km\n", testAirTwo);

    printf("Distance between third and fifth airport:\n");
    double testAirThree = getAirDistance(airportThree, airportFive);
    printf("%lf km\n", testAirThree);

    printf("Distance between first and fourth airport:\n");
    double testAirFour = getAirDistance(airportOne, airportFour);
    printf("%lf km\n", testAirFour);

    printf("Distance between second and third airport:\n");
    double testAirLast = getAirDistance(airportTwo, airportThree);
    printf("%lf km\n", testAirLast);


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

    double expected = getEstimatedTravelTime(stops, 5, 300.0, 2.30);
    printf("stops:5, speed:300, layover:2.30 tavel time:%lf\n", expected);
    double expectedTwo = getEstimatedTravelTime(stops, 4, 400.0, 2);
    printf("stops:4, speed:400, layover:2 tavel time:%lf\n", expectedTwo);
    double expectedThree = getEstimatedTravelTime(stops, 3, 100.0, 4);
    printf("stops:3, speed:300, layover:4 tavel time:%lf\n", expectedThree);
    double expectedFour = getEstimatedTravelTime(stops, 5, 100.0, 1);
    printf("stops:5, speed:100, layover:1 tavel time:%lf\n", expectedFour);
    double expectedFive = getEstimatedTravelTime(stops, 2, 500.0, 1);
    printf("stops:2, speed:500, layover:1 tavel time:%lf\n", expectedFive);

    return 0;
}