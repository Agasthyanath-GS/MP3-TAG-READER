
/*	Project_Name	:	MP3_Tag_Reader
	Auther_Name 	:	Agasthyanath-GS
	Version			:	ID3v2.2 & ID3v2.3
*/	

#include"main.h" 
void edit_tag(char *filename,int tag_size,char *edit_type,char * new_tag,meta_data header)
{

	switch(edit_type[1])
		{
			case 't': 
                  edit_frame(filename,header.title,tag_size,new_tag);         	//calling function to edit the title of the file
				  break;		
			case 'T':
                  edit_frame(filename,header.track,tag_size,new_tag);			//calling function to edit the title of the file
				  break;	
			case 'a':
                  edit_frame(filename,header.artist,tag_size,new_tag); 			//calling function to edit the title of the file
				  break;	
			case 'A':
                  edit_frame(filename,header.album,tag_size,new_tag);			//calling function to edit the title of the file
				  break;	
			case 'y':
                  edit_frame(filename,header.year,tag_size,new_tag);			//calling function to edit the title of the file
				  break;	
			case 'c':
                  edit_frame(filename,header.comment,tag_size,new_tag);			//calling function to edit the title of the file
				  break;	
			case 'g':
                  edit_frame(filename,header.genre,tag_size,new_tag);			//calling function to edit the title of the file
				  break;	
			default:
				  printf("editing option missmatch\n");                   		//default condition printds error msg and exit from the program
				  exit(0);
        }
			view_tag(filename,tag_size,header);                 				//calling function to view the edited metadata

}
