       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <stdlib.h>
        #include <unistd.h>
        #include <stdio.h>


int main()
{

    int create;
    unsigned char buff[200] ;
    create= open ("cdac.txt", O_CREAT | O_WRONLY | O_APPEND , S_IRUSR | S_IWUSR );
    if (create == -1)
    {
        perror("Failed.");
    }

        int num ;

        


        while ((num=read(0,buff , 200)))
        {
                int filewrite = write (create, buff, num);
                    if (filewrite==-1)
                    perror("failed to write");
        }
        



       /* int filewrite = write(create, "Anaadi_Mishra", 24);
*/
   
    
    close(create);

}
