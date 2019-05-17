/*	Project_Name	:	MP3_Tag_Reader
	Auther_Name 	:	Agasthyanath-GS
	Version			:	ID3v2.2 & ID3v2.3
*/	


#include"main.h"
 unint tag_size(char *filename)
{
 	FILE *fp;                          //assigning a file pointer fp
 	unint size_of_tag=0,i=0,mask;      //declaring unsighned intiger type variables
 	char size[4],ch;                   //declaring charecter type variables

	fp = fopen(filename,"r");          //open the file in read mode with file pointer fp

	 if(fp == NULL)                    //if file pointer is null the file was not opened ,print error msg       
	 {
	  printf("cannot open file\n");
	  exit(0);
	 }

 	ch = fgetc(fp);                    //load first byte from file to the char constant ch
	 while(i<=2)                       //run a loop to load the first 3 bytes of the file to check wheather the file is in ID3 format or not
	 {
	   size[i] = ch;
	   ch = fgetc(fp);
	   i++;
	 } 

 	if(strcmp("ID3",size))          //checking wheather the format is ID3 or not
    	{
    	 printf("ID3 format miss match\n");
    	 exit(0);
    	 }
 
 fseek(fp,6,SEEK_SET);         		//setting the file pointer to the 7th position
 ch = fgetc(fp);              		//loading first value to ch
 i=0;                         		//setting the variable to zero 
	while(i<=3)                    	//getting 4 bytes from the pos 7 to 10 which denotes the size of metadata
	{ 
  	size[i] = ch;
  	ch = fgetc(fp);
  	i++;
	}

mask = ~(1<<7);        				//creating mask to get the least 7 bits from each bytes of metadata size saved bytes                                                                          
size_of_tag = size_of_tag | (size[0] & mask) << 21 | (size[1] & mask) << 14 | (size[2] & mask) << 7 | (size[3] & mask);        //calculated the metadata size 

	fseek(fp,3,SEEK_SET);           //setting fp to 4th byte which denotes the version of the ID3
    ch = fgetc(fp);                 //loading the value to charecter byte ch
	printf("  ----------------------------------------------------\n");
    printf("  --------------MP3 TAG READER(ID3v2.%d)---------------\n",ch);
	printf("  ----------------------------------------------------\n");	
fclose(fp);                       	//closing file

return size_of_tag;                 //returning meta_data total size

}
