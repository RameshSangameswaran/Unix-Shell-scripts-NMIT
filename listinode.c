#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

void print_dirents(DIR * dir){
    struct dirent *entry;
    while ( (entry=readdir(dir)) != NULL ){
        printf("%s,%d\n",entry->d_name,entry->d_ino);
    }
}

int main(){

    char current_dir[PATH_MAX];
    DIR *cwd_p;

    if (  getcwd(current_dir,sizeof(current_dir)) != NULL){
        cwd_p = opendir(current_dir);
        print_dirents(cwd_p);
        closedir(cwd_p);
    } else {
        perror("NULL pointer returned from getcwd()");
    }

return 0;
}
