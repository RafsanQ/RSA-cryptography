#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int hcf(int a, int b){
    int i, hf;
    for(i=1; i<=a && i<=b; i++)
        if (a%i == 0 && b%i == 0)
            hf = i;
    return hf;
}

int main(){
    int p, q, n, t, e, d, i, k;
    cout << "Enter the First Prime Number: ";
    cin >> p;
    cout << "Enter the Second Prime Number: ";
    cin >> q;
    n = p*q;
    t = (p-1)*(q-1);

    while(1){
        cout << "Enter a Number x such that 1 < x < " << t << " and x is Co-Prime with " << n << " and " << t << ": \n";;
        cin >> e;
        if(hcf(e,t) == 1) break;
        else{
            cout << "Invalid input. Try again.\n";
            for(i=2; ; i++)
                if(hcf(i,t) == 1) break;
            cout << "Suggested Value: " << i << "\n";
        }

    }
    for(k=1; ; k++){
        if((k*t + 1)%e == 0) break;
    }
    d = (k*t + 1) / e;
    string msg, msg1;
    cout << "Enter Message (All Caps):\n";
    cin >> msg;
    int msg_1[100], msg_2[100];
    cout << "\nEncrypted  Message:\n";
    for(i=0; msg[i]; i++){
        msg_1[i] = (int)pow(msg[i],e)%n;
        cout << msg_1[i] << " ";
    }

    cout << "\nPrivate Key = " << d << "\n";

    return 0;
}
