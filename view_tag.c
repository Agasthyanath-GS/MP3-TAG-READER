/*	Project_Name	:	MP3_Tag_Reader
	Auther_Name 	:	Agasthyanath-GS
	Version			:	ID3v2.2 & ID3v2.3
*/	


#include"main.h" 
void view_tag(char *filename,int tag_size,meta_data header)
{
int runner = 0;

while(runner < 7)                             //variable used to run the switch for seven times to print data about the file
  {
	switch(runner)
		{
			case 0:
                  printf("Title   :"); 
                  view_frame(filename,header.title,tag_size);            //calling the function which print title of the file
				  break;		
			case 1:
				  printf("Track   :");
                  view_frame(filename,header.track,tag_size);			//calling the function which print track of the file
				  break;	
			case 2:
				  printf("Artist  :");
                  view_frame(filename,header.artist,tag_size);			//calling the function which print artist of the file
				  break;	
			case 3:
                  printf("Album   :");
                  view_frame(filename,header.album,tag_size);			//calling the function which print album of the file
				  break;	
			case 4:
                  printf("Year    :");
                  view_frame(filename,header.year,tag_size);			//calling the function which print year of the file
				  break;	
			case 5:
                  printf("Comment :");
                  view_frame(filename,header.comment,tag_size);			//calling the function which print comment of the file
				  break;	
			case 6:
                  printf("Genre   :");
                  view_frame(filename,header.genre,tag_size);			//calling the function which print genre of the file
				  break;	
			default:													//default condition to exit the prgrm
				  exit(0);
            }
		printf("\n");
		runner++;
	}
}
