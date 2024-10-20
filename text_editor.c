#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char ch;
    
    FILE* fp = fopen("temp1.txt","r+");

	if(fp==NULL)
	{
		printf("File Not Opened");	
		exit(1);
	}
    
    char **txt_arr = (char**)malloc(30*sizeof(char*));
	
    char *txt;
    txt = (char*)malloc(100*sizeof(char));
    int i=0,j=0;
    
    
    do{
    
    	ch = fgetc(fp);
    
    	if(ch =='\n' || ch == EOF)
    	{
            	txt[j] = '\0';
    		txt_arr[i]=txt;
    		i++;
    		j=0;
    		txt = (char*)malloc(100*sizeof(char));
    	}	
    	else
    	{
    		txt[j++] = ch;	
    	}	
    	
    	
    }while(ch != EOF);
	
	//printf("%d) %s",i+1,txt);
   
    int n;
    
    // printf("\nEnter line no. to print : ");
    // scanf("%d",&n);
    
    // printf("%d) %s\n",n,*(txt_arr+n-1));
   
    int choice,no;

    while(1)
    {
        printf("0. Clear Terminal\n1. Display File\n2. Save & Exit\n3. Add Line\n4. Delete Line\n5. Search\n6. Search & Replace\n\n");

        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        getchar();
        printf("\n");

        switch(choice)
        {
            case 0:
                system("clear");
            break;

            case 1:
                int b=1;
                for(int a=0;a<i;a++)
                {
                    if(txt_arr[a]!=NULL)
                    {
                        printf("%d) %s\n",b,txt_arr[a]);
                        b++;
                    }
                }
                printf("\n");
            break;

            case 2:
                fclose(fp);

                FILE* fp1 = fopen("temp1.txt","w");

                for(int a=0;a<i;a++)
                {
                    if(txt_arr[a] != NULL)
                    {
                        fputs(txt_arr[a],fp1);
                        
                        if(a != i-1)
                        {
                            fputs("\n",fp1);
                        }
                    }
                }
                fclose(fp1);
                
                for (int i = 0; i < 10; i++) {
       			 free(txt_arr[i]);
  			  }
    
    		free(txt_arr);
    
                return 0;
            break;

            case 3:
                 /*printf("Enter Line no. To Print : ");
                 scanf("%d",&no);
                 printf("\n");

                 int a=0;

                 while(no != 0 && !(a>i))
                 {
                    if(txt_arr[a]!=NULL)
                    {
                        no--;
                    }
                    a++;
                 }

                 if(no==0)
                 {
                    printf("%s\n",txt_arr[a-1]);
                 }
                 else
                 {
                    printf("Line Not Found\n");
                 }*/
                 
                 
                 txt = (char*)malloc(100*sizeof(char));
                 if(txt==NULL)
                 {
                 	printf("fail");
                 }
                 printf("Enter a string: ");
                 fgets(txt, 100, stdin);

		 txt_arr[i]=txt;
    		 i++;
                    
                printf("\n");
            break;

             case 4:
            /*  printf("Enter Line no. To Delete : ");
                 scanf("%d",&no);
                 txt_arr[no-1]=NULL;
            */


                printf("Enter Line no. To Delete : ");
                 scanf("%d",&no);
                
                if(no == i)
                {
                    i--;
                }

                 int a=0;

                 while(no != 0 && !(a>i))
                 {
                    if(txt_arr[a]!=NULL)
                    {
                        no--;
                    }
                    a++;
                 }

                 if(no==0)
                 {
                    txt_arr[a-1]=NULL;
                 }
                 else
                 {
                    printf("Line Not Found\n");
                 }
                    
                printf("\n");
            break;

            case 5:
                char str[100];
                printf("Enter a string: ");
                scanf("%s", str);

                int count = 0;

                for(int a=0;a<i;a++)
                {
                    if(txt_arr[a] != NULL)
                    {
                        const char *tmp = txt_arr[a];

                        while ((tmp = strstr(tmp, str)) != NULL) {
                            count++;
                            tmp++;
                        }
                    }
                }

                printf("Count = %d\n\n",count);
                //printf("\n");
            break;

            case 6:
                char s2[100];
                char rep[100];

                printf("Enter a String to Search: ");
                scanf("%s", s2);

                printf("Enter a String to Replace: ");
                scanf("%s", rep);

                for(int a=0;a<i;a++)
                {
                    if(txt_arr[a]!=NULL)
                    {
                        char* first= (char*) malloc(50*sizeof(char));
                        char* temp= (char*) malloc(200*sizeof(char));
                        
                        if (!first || !temp) {
                            printf("Memory allocation failed\n");
                                exit(1);
                            }
                        
                        temp[0]='\0';

                        char* spl_loc;

                        char *s1 = txt_arr[a];
                        char* tp=s1;

                        while((spl_loc = strstr(s1,s2)) != NULL)
                        {
                            int p = spl_loc-s1;

                            spl_loc+=strlen(s2);
                            tp=spl_loc;
                            strncpy(first,s1,p);
                            first[p]='\0';
                          
                            strcat(first,rep);
                            strcat(temp,first);
                            s1=spl_loc;
                            tp=s1;
                        }

                        strcat(temp,tp);
                        free(txt_arr[a]);
                        txt_arr[a] = strdup(temp);
                        free(first);
                        free(temp);
                    }
                }
                printf("\n");
            break;

        }


    }

    
    free(fp);
    
    return 0;
    
    
}
