/*	Project_Name	:	MP3_Tag_Reader
	Auther_Name 	:	Agasthyanath-GS
	Version			:	ID3v2.2 & ID3v2.3
*/	


#include"main.h"

int main(int argc,char *argv[])
{
unint size_of_tag;            //declaring variable in unsigned intiger form
 

system("clear");

/*loading standard ID3 
  tags inside the structure*/ 

meta_data header;
    	strcpy(header.title,"TIT2");             
		strcpy(header.track,"TRCK");
		strcpy(header.artist,"TPE1");
	 	strcpy(header.album,"TALB");
	 	strcpy(header.year,"TYER");
	 	strcpy(header.comment,"COMM");
	 	strcpy(header.genre,"TCON");

   switch(argc)                        //switch case for different command line atrguments
{
  
   case 2:
	  if(strcmp(argv[1],"-h")== 0)                            //if there is only -h as command line argument ,print help 
            { 
				printf("----------------------------------\n");
	            printf("-------------Help_Menu------------\n");
				printf("----------------------------------\n");

                printf("-v   View tags \n");
				printf("-e   Edit tags \n\n");
               	printf("-t   Modifies Title Tag\n");
				printf("-T   Modifies Track Tag\n");
				printf("-a   Modifies Artist Tag\n");
				printf("-A   Modifies Album Tag\n");
				printf("-y   Modifies Year Tag\n");
				printf("-c   Modifies Commen Tag\n");
				printf("-g   Modifies Genre Tag\n");
				return sucess; 
			}
    	else
			{
            	printf("error:%s :invalid arguments\n",argv[1]);           //if there is another variable rather than -h exit the program with error statement
          		printf("usage: %s :-h for help\n",argv[1]);
				return failure;
			}
    	break;
 	case 3:
		size_of_tag = tag_size(argv[2]);                                   //calling function to find the size of metadata
		if(strcmp(argv[1],"-v") == 0 )                                     //if there is 2 arguments then check first argument is -v,print metadata
			{
                view_tag(argv[2],size_of_tag,header );                     //call view_tag function to print the meta data
				return sucess;
            } 
		else                                                              //if there is another variable rather than -v exit the program with error statement        
			{
            	printf("error:%s :invalid arguments\n",argv[0]);
          		printf("usage: %s :-h for help\n",argv[0]);
				return failure;
			}
 		break;  

	case 5:
		size_of_tag = tag_size(argv[2]);                                 //calling function to find the size of metadata
		if(strcmp(argv[1],"-e") == 0)                                    //check wheather argument passed for edit option or not
			{
 		    	edit_tag(argv[2],size_of_tag,argv[3],argv[4],header);    //calling the function to edit the metadata of the fie
				return sucess;
     	    }
		else
			{
            	printf("error:%s :invalid arguments\n",argv[0]);		//if there is another variable rather than -e exit the program with error statement
          		printf("usage: %s :-h for help\n",argv[0]);
				return failure;
			}
		break;
	 default:                                                           //default case to print program with error statement
          		printf("error:%s :invalid arguments\n",argv[1]);      
          		printf("usage: %s :-h for help\n",argv[1]);
				return failure;			
          		break;
}
return sucess;
}
	