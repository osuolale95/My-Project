#include <stdio.h>
#include "ezxml.h"


int getParameters(ezxml_t root);
int getcipherKeys(ezxml_t root);
int getmasterKey(ezxml_t root);

int main()
{

    ezxml_t root = ezxml_parse_file("mConversionResponse.txt");
    if(!root)
    {
        printf("Root Not Found\n");

        return 1;
    }
   
    if(getParameters(root))
    {
        ezxml_free(root);
        return 1;
    }
   
   if(getcipherKeys(root))
   {
       ezxml_free(root);
       return 1;
   }

   if(getmasterKey(root))
   {
       ezxml_free(root);
       return 1;
   }

   return 0;
}

int getParameters(ezxml_t root)
{
   

    ezxml_t param = ezxml_child(root, "param");
    if (!param)
    {
        printf("Parameters Not Found\n");

        return -2;
    }

    //This is the date time
    ezxml_t dateTime = ezxml_child(param, "datetime");

    if(!dateTime)
    {
        printf("Date Time Not Found\n");

        return -3;
    }
    ezxml_t year = ezxml_child(dateTime, "year");
    ezxml_t syear = ezxml_child(dateTime, "syear");
    ezxml_t mon = ezxml_child(dateTime, "mon");
    ezxml_t day = ezxml_child(dateTime, "day");
    ezxml_t hour = ezxml_child(dateTime, "hour");
    ezxml_t min = ezxml_child(dateTime, "min");
    ezxml_t sec = ezxml_child(dateTime, "sec");

    printf("Date Time\nYear: %s\nSYear: %s\nMonth: %s\nDay: %s\nHour: %s Minute: %s Seconc: %s\n", year->txt, syear->txt, mon->txt, day->txt, hour->txt, min->txt, sec->txt);


    ezxml_t merchantID = ezxml_child(param, "merchantid"); 
    printf("Merchant ID: %s\n", merchantID->txt);

    ezxml_t header = ezxml_child(param, "header");
    printf("Header: %s\n", header->txt);

    ezxml_t footer = ezxml_child(param, "footer");
    printf("Footer: %s\n", footer->txt);

    ezxml_t market = ezxml_child(param, "market");
    printf("Market: %s\n", market->txt);

    ezxml_t pinReset = ezxml_child(param, "pinreset");
    printf("PinReset: %s\n", pinReset->txt);

    ezxml_t updateLogo = ezxml_child(param, "updatelogo");
    printf("Update Logo: %s\n", updateLogo->txt);

    ezxml_t updateMenu = ezxml_child(param, "updatemenu");
    printf("Update Menu: %s\n", updateMenu->txt);

    ezxml_t replyTimeout = ezxml_child(param, "replytimeout");
    printf("Reply Timeout: %s\n", replyTimeout->txt);

    ezxml_t currency = ezxml_child(param, "currency");
    printf("Currency: %s\n", currency->txt);

    ezxml_t fract = ezxml_child(param, "fract");
    printf("Fract: %s\n", fract->txt);

    ezxml_t prefix = ezxml_child(param, "prefix");
    printf("Prefix: %s\n", prefix->txt);

    ezxml_t negnum = ezxml_child(param, "negnum");
    printf("Negnum: %s\n", negnum->txt);

    ezxml_t currcode = ezxml_child(param, "currcode");
    printf("Currcode: %s\n", currcode->txt);

    ezxml_t decsym = ezxml_child(param, "decsym");
    printf("Decysm: %s\n", decsym->txt);

    ezxml_t thoussep = ezxml_child(param, "thoussep");
    printf("Thoussep: %s\n", thoussep->txt);

    ezxml_t countryCode = ezxml_child(param, "countrycode");
    printf("Country Code: %s\n", countryCode->txt);

    ezxml_t endOfDay = ezxml_child(param, "endofday");
    printf("End Of Day: %s\n", endOfDay->txt);

    ezxml_t updatePrompts = ezxml_child(param, "updateprompts");
    printf("Update Prompts: %s\n", updatePrompts->txt);

    ezxml_t attendance = ezxml_child(param, "attendance");
    printf("Attendance: %s\n", attendance->txt);

    ezxml_t agentAccess = ezxml_child(param, "agentaccess");
    printf("Agent Access: %s\n", agentAccess->txt);

    ezxml_t eodTime = ezxml_child(param, "eodtime");
    if (!eodTime)
    {
        printf("EOD Time Not Found\n");

        return -4;
    }

    ezxml_t enabled = ezxml_child(eodTime, "enabled");
    printf("Enabled: %s\n", enabled->txt);

    ezxml_t conn1 = ezxml_child(param, "conn1");
    printf("Conn1: %s\n", conn1->txt);

    ezxml_t conn2 = ezxml_child(param, "conn2");
    printf("Conn2: %s\n", conn2->txt);

    ezxml_t download = ezxml_child(param, "download");
    if(!download)
    {
        printf("Download Not Founf\n");

        return -5;
    }

    ezxml_t enableDownload = ezxml_child(download, "enabled");
    printf("Enable Download: %s\n", enableDownload->txt);

    ezxml_t downloadConn = ezxml_child(download, "downloadconn");
    printf("Downlaod Conn: %s\n", downloadConn->txt);

    ezxml_t disabled = ezxml_child(param, "disabled");
    printf("Disable: %s\n", disabled->txt);

    return 0;
}

int getcipherKeys(ezxml_t root)
{
    //This Function Is To Get Cipher Keys
    ezxml_t getKey = ezxml_child(root, "getkeys");
    if(!getKey)
    {
        printf("Get Key Is Not Found\n");

        return -6;
    }
    
   ezxml_t cipher = ezxml_child(getKey, "cipher");
   if(!cipher)
    {
       printf("Cipher Not Found\n");

       return -7;
    }
    ezxml_t cipherNo = ezxml_child(cipher, "no");
    ezxml_t cipherKey = ezxml_child(cipher, "key");

    for(cipher = ezxml_child(getKey, "cipher"); cipher; cipher = cipher->next)
    {
        printf("%s: %s\n", cipherNo->txt, cipherKey->txt);
    }

    return 0;
}

int getmasterKey(ezxml_t root)
{
     //This Function Is To Get New Key
    ezxml_t newKey = ezxml_child(root, "newkey");

    ezxml_t masterKey = ezxml_child(newKey, "masterkey");
    if(!masterKey)
    {
        printf("Master Key Not Found\n");

        return -8;
    }

    printf("Master Key is %s\n", masterKey->txt);

    return 0;
}