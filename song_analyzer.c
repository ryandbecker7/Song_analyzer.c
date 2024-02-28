/** @file song_analyzer.c
 *  @brief A pipes & filters program that uses conditionals, loops, and string processing tools in C to process song
 *  data and printing it in a different format.
 *  @author Felipe R.
 *  @author Hausi M.
 *  @author Angadh S.
 *  @author Juan G.
 *  @author Ryan Becker
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief The maximum line length.
 *
 */
#define MAX_LINE_LEN 132

/**
 * Function: main
 * --------------
 * @brief The main function and entry point of the program.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv The list of arguments passed to the program.
 * @return int 0: No errors; 1: Errors produced.
 *
 */
void q1(FILE *f, FILE *o){
    fprintf(o, "Artist(s),Song\n");

    char line[MAX_LINE_LEN];

    //Iterate through the lines of the file
    while(fgets(line, MAX_LINE_LEN, f))
    {
        //Get song name
        char *data = strtok(line, ",");
        char *song = data;

        //Iterate though a line
        while(data != NULL){
            //Check for songs written by Rae Spoon
            if(strcmp("Rae Spoon", data) == 0){
                fprintf(o, "%s,%s\n", data, song);
            }
            data = strtok(NULL, ",");   
        }
    } 
}


void q2(FILE *f, FILE *o){
    fprintf(o, "Artist(s),Song\n");
    char line[MAX_LINE_LEN];

    //Iterate through the lines of the file
    while(fgets(line, MAX_LINE_LEN, f))
    {
        //Get song name
        char *data = strtok(line, ",");
        char *song = data;


        //Iterate though a line
        while(data != NULL){
            //Check for songs written by Tate McRae
            if(strcmp("Tate McRae", data) == 0){
                fprintf(o, "%s,%s\n", data, song);
            }
            data = strtok(NULL, ",");      
        }        
    } 
}

void q3(FILE *f, FILE *o){
    fprintf(o, "Artist(s),Song\n");
    char line[MAX_LINE_LEN];

    //Iterate through the lines of the file
    while(fgets(line, MAX_LINE_LEN, f))
    {
        //Remove \n at end of line
        line[strcspn(line, "\r\n")] = 0;
        
        //Get song name
        char *data = strtok(line, ",");
        char *song = data;

        //Get artist name
        data = strtok(NULL, ",");
        char *artist = data;

        //Run through line 6 times to find the songs mode
        for (int i = 1; i <= 6; i++){
            data = strtok(NULL, ","); 
        }

        //Check if song is written by The Weeknd and in major
        if(strcmp("The Weeknd", artist) == 0 && strcmp(data, "Major") == 0){
            fprintf(o, "%s,%s\n", artist, song);   
        }   
        data = strtok(NULL, ",");    
    }
}

void q4(FILE *song_list, FILE *output) {

    fprintf(output, "Artist(s),Song\n");

    char line[MAX_LINE_LEN];
    //Iterate through the lines of the file
    while (fgets(line, MAX_LINE_LEN, song_list)) {
              
        //Remove \n at end of line
        line[strcspn(line, "\r\n")] = 0;
        
        //Get song name
        char *data = strtok(line, ",");
        char *song = data;

        //Get artist name
        data = strtok(NULL, ",");
        char *artist = data;

        //Create counter i and playlist variables
        int i = 0;
        char *playlist;

        //Iterate though a line
        while (data != NULL) {

            //Find amount of playlists
            if(i == 3){
                playlist = data;
            }

            //Check if playlists > 5000 and song is written in either key D or A
            if(i == 5 && atoi(playlist) > 5000 && (strcmp("D", data) == 0 || strcmp("A", data) == 0)){
                fprintf(output,"%s,%s\n", artist, song);
            }
            data = strtok(NULL, ",");
            
            //Increment counter
            i++;
        }
      
    }
}

void q5(FILE *f, FILE *o){
    fprintf(o, "Artist(s),Song\n");

    char line[MAX_LINE_LEN];
    
    //Initialize counter i
    int i = 0;

    //Iterate through the lines of the file
    while(fgets(line, MAX_LINE_LEN, f)){
        
        //Initialize year variable
        char *year;
        
        //Get song name
        char *data = strtok(line, ",");
        char *song = data;

        //Get artist
        data = strtok(NULL, ",");
        char *artist = data;

        //Iterate though a line
        while (data != NULL){

            //Get Year song was made
            if(i = 2){
                year = data;
            }

            //Check if Drake was an artist
            if (strstr(artist,"Drake") != NULL){

                //Check if song was made in 2021 or 2022
                if(atoi(year) == 2021 || atoi(year) == 2022){
                    fprintf(o, "%s,%s\n", artist, song);
                }
            }
            
            data = strtok(NULL, ",");
            i++;
        }
    }
}

int main(int argc, char *argv[])
{   
    //Open input file
    FILE *f;
    f = fopen(argv[2]+7, "r");

    //Open output file
    FILE *o = fopen("output.csv", "w");

    //Get question number
    char qNum = argv[1][11];

    
    
    //Pick a function based on qNum
    if(qNum == '1'){
        q1(f, o);
    }
    if (qNum == '2'){
        q2(f, o);
    }
    if(qNum == '3'){
        q3(f, o);
    }
    if(qNum == '4'){
        q4(f, o);
    }
    if(qNum == '5'){
        q5(f, o);
    }
    
    //Close both files
    fclose(f);
    fclose(o);

    exit(0);
}
