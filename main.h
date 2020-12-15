
/*	Project_Name	:	MP3_Tag_Reader
	Auther_Name 	:	Agasthyanath-GS
	Version			:	ID3v2.2 & ID3v2.3
*/	


#ifndef MAIN_H
#define MAIN_H

#define sucess 0      
#define failure -1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int unint;
typedef struct metadata           //structure for saving predefined tags of the ID3 format
{
  char title[5];
  char track[5];
  char artist[5];
  char album[5];
  char year[5];
  char comment[5];
  char genre[5];

}meta_data;

unint tag_size(char *);                                 //function for finding meta_data size
void view_tag(char *,int,meta_data);					//function for switching between ID3 tags which we are given
unint view_frame(char *,char *,int);					//function for view specfic frame
void edit_tag(char *,int,char *,char *,meta_data);		//function for switch between modifiers for editing
int edit_frame(char *,char *,int,char *);				//function for editing the current frame with new frame
#endif