#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
    
    
    int PScheduler(void);
    int PScheduler2(void);
    int PScheduler3(void);

    if (atoi(argv[1]) == 1) {
        PScheduler(); //task 1 test
    }
    else if(atoi(argv[1]) == 3) {
        
        PScheduler3(); //test donate
    }
    else if(atoi(argv[1]) == 2) {
        PScheduler2(); //test aging
    }
    else
        printf(1, "\ntype \"%s 1\" to test task1, \"%s 2\" to test aging\n, \"%s 3\" to test donation\n", argv[0], argv[0], argv[0]);
    exit();
}    
      
int PScheduler(void){
		 
    // Use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority. All processes have a default priority of 10
    // You can use your own priority range/value setup

    int pid, ret_pid;
    int i,j,k;
  
    printf(1, "Testing the priority scheduler and setpriority system call:\n");
    printf(1, "Assuming that the priorities range between range between 0 to 31\n");
    printf(1, "0 is the highest priority. All processes have a default priority of 10\n");
    printf(1, " - The parent processes will switch to priority 0\n");
    setpriority(0);
    for (i = 0; i < 3; i++) {
	pid = fork();
	if (pid > 0) {
            continue;
        } else if ( pid == 0) {
            printf(1, " - Hello! this is child# %d and I will change my priority to %d \n", getpid(), 30 - 10 * i);
            setpriority(30 - 10 * i);
            for (j = 0; j < 50000; j++) {
                asm("nop");
                for(k = 0; k < 10000; k++) {
                    asm("nop"); 
                }
            }
            printf(1, " - Child #%d with priority %d has finished! \n", getpid(), 30-10*i);		
            exit();
        } else {
            printf(2," \n Error fork() \n");
            exit();
        }
    }

    if(pid > 0) {
        for (i = 0; i < 3; i++) {
            ret_pid = wait();
            printf(1, " - This is the parent: child with PID# %d has finished\n", ret_pid);
        }
        printf(1, " - If processes with highest priority finished first then its correct. \n");
    }
			
    return 0;
}

int PScheduler2(void){
		 
    // Use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority. All processes have a default priority of 10
    // You can use your own priority range/value setup

    int pid, ret_pid;
    int i,j,k;
  
    printf(1, "Testing aging priority scheduler:\n");
    printf(1, " - The parent processes will switch to priority 0\n");
    setpriority(0);
    for (i = 0; i < 3; i++) {
	pid = fork();
	if (pid > 0) {
            continue;
        } else if ( pid == 0) {
            printf(1, " - Hello! this is child# %d and I will change my priority to %d \n", getpid(), 30 - 10 * i);
            setpriority(30 - 10 * i);
            for (j = 0; j < 50000; j++) {
                asm("nop");
                for(k = 0; k < 10000; k++) {
                    asm("nop"); 
                }
            }
            printf(1, " - Child #%d with ending priority %d has finished! \n", getpid(), getpriority());		
            exit();
        } else {
            printf(2," \n Error fork() \n");
            exit();
        }
    }

    if(pid > 0) {
        for (i = 0; i < 3; i++) {
            ret_pid = wait();
            printf(1, " - This is the parent: child with PID# %d has finished\n", ret_pid);
        }
    }
			
    return 0;
}

int PScheduler3(void){
		 
    // Use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority. All processes have a default priority of 10
    // You can use your own priority range/value setup

    int pid, ret_pid;
    int i,j,k;
  
    printf(1, "Testing donation of parent priority(switching):\n");
    printf(1, " - The parent processes will switch to priority 0\n");
    setpriority(0);
    for (i = 0; i < 3; i++) {
	pid = fork();
	if (pid > 0) {
            continue;
        } else if ( pid == 0) {
            printf(1, " - Child #%d with fork priority:%d\n", getpid(), getpriority());	
            printf(1, " - Hello! this is child# %d and I will change my priority to %d \n", getpid(), 30 - 10 * i);
            setpriority(30 - 10 * i);
            for (j = 0; j < 50000; j++) {
                asm("nop");
                for(k = 0; k < 10000; k++) {
                    asm("nop"); 
                }
            }
            printf(1, " - Child #%d with ending priority %d has finished! \n", getpid(), getpriority());		
            exit();
        } else {
            printf(2," \n Error fork() \n");
            exit();
        }
    }

    if(pid > 0) {
        for (i = 0; i < 3; i++) {
            ret_pid = wait();
            printf(1, " - This is the parent: child with PID# %d has finished\n", ret_pid);
        }
        printf(1, " - Parent's ending priority is: %d\n", getpriority());	
        printf(1, " - If processes with highest priority finished first then its correct. \n");
    }
			
    return 0;
}


