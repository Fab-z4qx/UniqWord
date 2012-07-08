/********************************************
 * Use Std::unordered_map for hashmap 		 *
 * by z4qx 07/2012  						 *
 * Remove all word duplicate word in a file  *
 * g++ -std=gnu++0x main.cpp -O3 -s -DNDEBUG *
 * ******************************************/

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <sys/sysinfo.h>
#include <unordered_map>

#define MEMUSE 70 

double removed = 0.0;
double total_lines = 0.0;
unsigned int hash_entries = 0;

using namespace std;

typedef std::unordered_map<string , int> Mymap;

/* Memory - not used */
unsigned long getMemFree(void)
{
   struct sysinfo info;
   sysinfo(&info);
   return info.freeram;
}

unsigned long  getMemTotal(void)
{
   struct sysinfo info;
   sysinfo(&info);
   return info.totalram;
}
    

#define PRINT_INFOS() do{                                                         \
     /* cout << "Total lines    : " <<  total_lines << endl;  */                  \
      cout << "Lines removed  : " << removed << endl;                	          \
      cout << "removed %      : " << (removed/(double)total_lines)*100.0 << endl; \
      cout << "Hash entries   : " <<  hash_entries << endl;   		              \
   						                                                          \
}while(0)

int process(string s_in, string s_out)
{
	int i=0;
    char buffer[50];
    FILE *in, *out;
    
    Mymap mot_unique;

    if((in  = fopen(s_in.c_str(), "r")) == NULL)
	{
		cout << "Erreur d'ouverture de : " << s_in << endl;
        exit(EXIT_FAILURE);
    }

    if(( out = fopen(s_out.c_str(), "w")) == NULL)
	{
		cout << "Erreur d'ouverture de : " << s_out << endl;
		exit(EXIT_FAILURE);
	}

        int start = clock();
        while(fgets(buffer, sizeof(buffer), in) != NULL)
        {
        	if ( mot_unique.find (buffer) == mot_unique.end() ) // si le mot n'est pas present 
            {
	    	  	mot_unique.insert(Mymap::value_type(buffer,i)); 
                fputs(buffer, out);
                hash_entries++;
            }
           else
               removed++;

           if(i%1000000 == 0)
           {
			   PRINT_INFOS();
					// timer 
               cout << "10000000 Loops : " << ((clock() - start) / (double)CLOCKS_PER_SEC  )<< "s " << endl << endl;
               start = clock(); //reset time 
		   }
     
		i++; total_lines++; 
        }
  
 fclose(in);
 fclose(out);

return 0;
}


int main(int argc, char **argv)
{
   if(argc < 2)
   {
      cout << "Usage : " << argv[0] << "<in> <out>" << endl;
      exit(EXIT_FAILURE);
   }

   process(argv[1],argv[2]);

return 0;
}


