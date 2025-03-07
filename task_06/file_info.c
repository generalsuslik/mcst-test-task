#include "file_info.h"

#include <stdio.h>
#include <sys/types.h>
#include <time.h>

int print_info(const char *path)
{
	struct stat file_stat;
	if (stat(path, &file_stat) == -1) {
		perror("stat error");
		return -1;
	}

	printf("File: %s\n", path);
	print_type(&file_stat);
	printf("Size: %ld bytes\n", file_stat.st_size);
	print_permissions(&file_stat);
	printf("Last modified: %s", ctime(&file_stat.st_mtime));

	return 0;
}

void print_type(struct stat *file_stat)
{
	printf("File type: ");
	if (S_ISREG(file_stat->st_mode)) {
		printf("Regular file\n");
	} else if (S_ISDIR(file_stat->st_mode)) {
		printf("Directory\n");
	} else if (S_ISCHR(file_stat->st_mode)) {
		printf("Byte oriented\n");
	} else if (S_ISBLK(file_stat->st_mode)) {
		printf("Block oriented\n");
	} else {
		printf("Unknown\n");
	}
}

void print_permissions(struct stat *file_stat)
{
	mode_t mode = file_stat->st_mode;
	
	char permissions[10] = {0};
	
	permissions[0] = (mode & S_IRUSR) ? 'r' : '-';
	permissions[1] = (mode & S_IWUSR) ? 'w' : '-';
	permissions[2] = (mode & S_IXUSR) ? 'x' : '-';

	permissions[3] = (mode & S_IRGRP) ? 'r' : '-';
	permissions[4] = (mode & S_IWGRP) ? 'w' : '-';
	permissions[5] = (mode & S_IXGRP) ? 'x' : '-';

	permissions[6] = (mode & S_IROTH) ? 'r' : '-';
	permissions[7] = (mode & S_IWOTH) ? 'w' : '-';
	permissions[8] = (mode & S_IXOTH) ? 'x' : '-';

	printf("Permissions: ");
	printf("%s\n", permissions);
}


