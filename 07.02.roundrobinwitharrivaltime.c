#include<stdio.h>

int main()
{
    int n, qt;
    int at[10], bt[10], rem_bt[10];
    int wt[10], tat[10], ct[10];
    int time = 0, remain, i;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    remain = n;

    printf("\nEnter Arrival Time and Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d Arrival Time: ", i+1);
        scanf("%d",&at[i]);

        printf("P%d Burst Time: ", i+1);
        scanf("%d",&bt[i]);

        rem_bt[i] = bt[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d",&qt);

    while(remain != 0)
    {
        int executed = 0;

        for(i=0;i<n;i++)
        {
            if(at[i] <= time && rem_bt[i] > 0)
            {
                executed = 1;

                if(rem_bt[i] > qt)
                {
                    time += qt;
                    rem_bt[i] -= qt;
                }
                else
                {
                    time += rem_bt[i];
                    ct[i] = time;
                    rem_bt[i] = 0;
                    remain--;
                }
            }
        }

        if(executed == 0)
            time++;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        awt += wt[i];
        atat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", awt/n);
    printf("\nAverage Turnaround Time = %.2f\n", atat/n);

    return 0;
}

/*
ROUND ROBIN SCHEDULING WITH ARRIVAL TIME

This program simulates the Round Robin CPU scheduling algorithm
considering arrival time of processes.

STEP BY STEP WORKING OF THE PROGRAM

1. Include stdio.h
   - Required for input and output functions like printf() and scanf().

2. Declare variables
   - n : number of processes
   - qt : time quantum
   - at[] : array to store arrival times
   - bt[] : array to store burst times
   - rem_bt[] : remaining burst time of processes
   - wt[] : waiting time
   - tat[] : turnaround time
   - ct[] : completion time
   - time : current CPU time
   - remain : number of processes still not completed
   - awt : average waiting time
   - atat : average turnaround time

3. Input number of processes
   - User enters how many processes will be scheduled.

4. Input arrival time and burst time
   - For each process, the user enters:
       Arrival Time (AT)
       Burst Time (BT)
   - Remaining burst time is initially set equal to burst time.

5. Input time quantum
   - The fixed time slice each process can run before switching.

6. Start scheduling loop
   - The loop continues until all processes are finished
     (remain becomes 0).

7. Check each process
   - For every process:
       If arrival time <= current time
       AND remaining burst time > 0
       then the process can execute.

8. Execute process
   Case 1:
       If remaining burst time > time quantum
       - Run process for time quantum
       - Reduce remaining burst time
       - Increase current time

   Case 2:
       If remaining burst time <= time quantum
       - Run process until completion
       - Update completion time
       - Set remaining burst time to 0
       - Decrease remaining process count

9. CPU idle case
   - If no process is ready at the current time
     increase time by 1 (CPU waits).

10. Calculate times
    After all processes finish:

    Turnaround Time (TAT) = Completion Time - Arrival Time
    Waiting Time (WT) = Turnaround Time - Burst Time

11. Calculate averages
    Average Waiting Time = sum of WT / number of processes
    Average Turnaround Time = sum of TAT / number of processes

12. Display results
    The program prints a table showing:
        PID
        Arrival Time
        Burst Time
        Completion Time
        Turnaround Time
        Waiting Time

    Finally it prints:
        Average Waiting Time
        Average Turnaround Time
*/
