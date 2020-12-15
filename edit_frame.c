/*	Project_Name	:	MP3_Tag_Reader
	Auther_Name 	:	Agasthyanath-GS
	Version			:	ID3v2.2 & ID3v2.3
*/	

#include"main.h"
int edit_frame(char *filename,char *frame,int tag_size,char *new_frame_name)
{
  
  FILE *fp;
  char frame_arr[4],ch;
  unint i=0,j=0,frame_size[4],size_of_frame,len_new;

  fp=fopen(filename,"r+");								//open the file in  r+ (read & write) mode with file pointer fp

  if( fp == NULL )										//exit from program if file pointer not entered the file
	{
		printf("not opened");
		exit(0);
	}

  fseek(fp,10,SEEK_SET);								//setting file pointer to 11th position to start with first ID3 frame
	while(tag_size--)            						//run the loop till the size of meta data
	{
			
    	while(i<=3)                              		//pick 4 bytes each time to compare the value with ID3 frames
		{
			ch=fgetc(fp);
			frame_arr[i] = ch;						
			i++;
		}
		
		if(strcmp(frame_arr,frame) == 0)       			//check for wheather the variables inside structure that match with the ID3 frames present in file
		{ 	
			
        	while(j<=3)                                	//loading the next 4 bytes to find the total size of the frame
			{
				ch=fgetc(fp);
				frame_size[j] = ch;							
				j++;
			}

            size_of_frame = size_of_frame | (frame_size[0] << 24) | (frame_size[1] << 16) | (frame_size[2] << 8) | frame_size[3] ; //converting the 4 byte hexa value to int value                  
		
           	
            len_new=strlen(new_frame_name);                                //saving length of new frame name
     		
			if(len_new > size_of_frame )                                   //if length of new frame is grater than the current frame size print error
     		{
	 			printf("cannot posssible:input tag_size is grater\n");
				exit(0);
	 		}

			fseek(fp,2,SEEK_CUR);                                         //jumping file pointer by 2 bytes to avoid flag bytes
           while(size_of_frame-(len_new))
			{  				
				fputc('\0',fp);                                           //replacing balance bytes with NULL after alocating the required frame size for new frame
				size_of_frame--;
			}		

			fputs(new_frame_name,fp);                                     //replacing the old frame with new frame
		
			fclose(fp);                                                  //close file
			return sucess;                                               //return a sucess value
	}
		
		i=0;								//to set i to start position
		fseek(fp,-3,SEEK_CUR);
			
		if(tag_size == 1)					//error codition:if the frame mismatch occur print error ms
		{
			printf("no details about the tag \n\n\n");
			fclose(fp);						//close file
			return failure;                 //return failure for error condition
		}
	}
}