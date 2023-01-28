 #include "lib/include.h"
extern void printString(char* string)
{
    while(*string)
    {
        printChar(*(string++));
    }
}
 extern char * readString(char delimitador)//leer cadena 
{

   int i=0;
   char *string = (char *)calloc(50,sizeof(char));//asiganar memoria para 50 caracteres 
   char c = readChar();
   while(c != delimitador)
   {
       
       *(string+i) = c;
       i++;
        if(i%50==0)
       {
           string = realloc(string,(i+50)*sizeof(char));
       }
       c = readChar();
   }
   return string ;

}
 extern void invertirCadena (char*name,int a)
 {
    char *Cadena = (char *)calloc(50,sizeof(char));
    int p=0; 
    int q=0; 
    for (int i=a; i>0; i++){
    string [p+1]=q;
    string[i-1]=*(name+(i-1));
    q++; 
    p=p+2; 
    }
    extern char* agregarNumeros (char*string, char*num,int i){
    int p=0;
    int q=0;
    while (1<i){
    num[1]=Cadena[q];
    p++;
    num[1]=string(unsigned char);
    q++;
    p++; 
    }
 return num; 
 }
 }
 return name[0];

 