#include <stdio.h>
#include "ezxml.h"

int main()
{
    ezxml_t driver, team;

    ezxml_t root = ezxml_parse_file ("file.txt");

    if(!root) {
        printf("root not found\n");
        return 1;
    }

    team = ezxml_child(root, "team"); 

    if(!team) {
        printf("Team not found\n");
        return 1;
    }
    

    // do{

    //     if(!driver) {
    //         printf("Driver not found\n");
    //         return 1;
    //     }

    //     driverName = ezxml_child(driver, "name")->txt;

    //     printf("%s\n", driverName);
    // } while(driver->next);

    for (driver = ezxml_child(team, "driver"); driver; driver = driver->next) {

        ezxml_t dName = ezxml_child(driver, "name");
        ezxml_t dPoint = ezxml_child(driver, "points");

        printf("%s \t %s\n", dName->txt, dPoint->txt);
    // teamname = ezxml_attr(team, "name");
    // for (driver = ezxml_child(team, "driver"); driver; driver = driver->next) {
    //     printf("%s, %s: %s\n", ezxml_child(driver, "name")->txt, teamname,
    //            ezxml_child(driver, "points")->txt);
    }


    ezxml_free(root);

    return 0;
}