#include <stdio.h>
#include <dirent.h>

int main(void)
{
	char *NameArr[20]; // the array which will store the filenames
	DIR *dir;
	int i=0,k;
	struct dirent *ent;
	dir = opendir (dir);
	if (dir != NULL) 
	{
	/* print all the files and directories within directory */
	while ((ent = readdir (dir)) != NULL) 
		{
		NameArr[i]=ent->d_name;
		/* save filenames in the array */
		i++;
		}
	closedir (dir);
	} 
	else 
	{
	/* could not open directory */
	perror ("");
	}
	for (k=0;(k<(i+1)) && (k<20);k++) printf("%s\n",NameArr[k]);
	//print the filenames on the screen
	return 0;
}