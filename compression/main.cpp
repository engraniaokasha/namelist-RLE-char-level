
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;


char *RLE(char *nlist)
{
  int repeat;
  char counter[500];
  char dest [500];
  int len = strlen(nlist);
  int j = 0 ;

  for(int i = 0; i < len; i++)
  {

    dest[j++] = nlist[i];
    repeat = 1;
        while(i + 1 < len && nlist[i+1] == nlist[i])
        {
            repeat++;
            i++;
        }

    // display and store repeat value in counter

    sprintf(counter,"@%d",repeat);

if (repeat>1){

    for(int a = 0; *(counter+a)!=NULL; a++)
    {
        dest[j] =counter[a];
        j++;

    }

            }

  }


  dest[j] = NULL ;
  return dest;
}


int main() {
   cout <<"please entre the extention of your name list file"<< endl;
   char filename[500];
   ifstream com ;
   cin.getline(filename,500);
   com.open(filename);
        if (!com.is_open()){
                cout<<"wrong path!"<<endl;
                exit(EXIT_FAILURE);

                            }
    char word[500];
    com >> word ;
        while (com.good()){
            char *res = RLE(word);
            cout <<res<< " ";
            getchar();
            com>>word;
            //cout<<word<< " ";

                          }

    return 0;

}

