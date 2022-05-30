#include<iostream>

using namespace std;

int main()
{      
    int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j;
    cout << "Enter total number of processes(maximum 20):";     // nhập tổng số tiến trình (tối đa 20)
    cin >> n;
    //int n: số lượng tiến trình
    // bt[20]: thời gian bust i
    // wt[20]: thời gian chờ i
    // tat[20]: thời gian quay vòng i
    // avwt: thời gian chờ trung bình
    // avtat: thời gian quay vòng trung bình

    cout << "\nEnter Process Burst Time\n";                     // nhập thời gian xử lý liên tục
    for (i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]:";
        cin >> bt[i];
    }

    wt[0] = 0;    //waiting time for first process is 0         //Thời gian chờ đợi cho tiến trình đầu tiên là 0

    //calculating waiting time                                  //tính toán thời gian chờ đợi
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
    }

    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time"; 
    //     tiến trình\t\thời gian burst\t\Thời gian chờ\t\thời gian quay vòng
   
    //calculating turnaround time                               //tính toán thời gian quay vòng
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        cout << "\nP[" << i + 1 << "]" << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }

    avwt /= i;
    avtat /= i;
    cout << "\n\nAverage Waiting Time:" << avwt;                //Thời gian chờ trung bình
    cout << "\nAverage Turnaround Time:" << avtat;              //Thời gian quay vòng trung bình

    return 0;
}