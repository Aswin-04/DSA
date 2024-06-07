#include<bits/stdc++.h>
using namespace std;


void printPattern1 (int n) {
    
    for (int i=0; i < n; i++) {
        
        for (int j=0; j < n; j++) {

            cout << "*";
        }

        cout << endl;
    }
}

void printPattern2 (int n) {

    for (int i = 0; i < n; i++) {
        
        for (int j=0; j <= i; j++) {

            cout << "* ";
        }

        cout << endl;
    }
    
}

void printPattern3 (int n) {

    for (int i=1; i <= n; i++) {

        for (int j=1; j <= i; j++) {
            
            cout << j << " ";
        }

        cout << endl;
    }
}

void printPattern4 (int n) {

    for (int i=1; i <= n; i++) {
        
        for (int j=1; j <= i; j++) {

            cout << i << " ";
        }

        cout << endl;
    }
}

void printPattern5 (int n) {

    for ( int i = 0; i < n; i++) {

        for (int j=0; j< n-i; j++) {

            cout << "* ";
        }        
        
        cout << endl;
    }
    
}

void printPattern6 (int n) {

    for (int i=0; i < n; i++) {

        for(int j=0; j < n-i; j++) {

            cout << j+1 << " ";
        }

        cout << endl;
    }
}

void printPattern7 (int n) {

    for (int i = 0; i < n; i++){
        
        for (int j=0; j< n-i-1; j++) {

            cout << " ";
        }

        for (int j = 0; j < (2*i+1); j++) {

            cout << "*";
        }

        for (int j = 0; j < n-i-1; j++){
            
            cout << " ";
        }

        cout << endl;
    }
    
}

void printPattern8 (int n) {

    for (int i=0; i < n; i++) {

        for (int j=0; j < i; j++) {
            
            cout << " ";
        }

        for (int j=0; j < (2 * n) - (2 * i + 1); j++) {  

            //Another condition 2*(n-i) - 1  

            cout << "*";
        }

        for (int j=0; j < i; j++) {

            cout << " ";
        }

        cout << endl;
    }
}

void printPattern9 (int n) {

    for (int i=0; i < n; i++) {

        for (int j=0; j < n-i-1; j++) {

            cout << " ";
        }

        for (int j=0; j < 2*i+1; j++) {
            
            cout << "*";
        }

        for (int j=0; j < n-i-1; j++) {
            
            cout << " ";
        }

        cout << endl;
    }

    for (int i=0; i < n; i++) {

        for (int j=0; j < i; j++) {
            
            cout << " ";
        }

        for (int j=0; j < 2*n - (2*i+1); j++) {
            
            cout << "*";
        }

        for (int j=0; j < i; j++) {

            cout << " ";
        }

        cout << endl;
    }
}

void printPattern10 (int n) {

    for (int i=1; i <= 2*n-1; i++) {

        int stars =  i;

        if (stars > n) stars = 2*n-i;

        for (int j=1; j <= stars; j++) {

            cout << "*";
        }

        cout << endl;
    }
}

void printPattern11 (int n) {

    int start = 1;

    for (int i=0; i < n; i++) {

        for (int j=0; j <= i; j++) {

            cout << start << " ";
            start = 1 - start;
        }

        cout << endl;
    }
}

void printPattern12 (int n) {

    for(int i=1; i <= n; i++) {

        for(int j=1; j <= i; j++) {
            
            cout << j << " ";
        }

        for (int j=1; j <= 2*(n-i); j++) {

            cout << "  ";
        }

        for (int j=i; j >= 1; j--) {

            cout << j << " ";
        }

        cout << endl;
    }
}

void printPattern13 (int n) {

    int num = 1;

    for (int i=0; i < n; i++) {

        for (int j=0; j <= i; j++) {

            cout << num << " ";
            num++;
        }

        cout << endl;
    }
}

void printPattern14 (int n) {

    for (int i=0; i<n; i++) {

        char ch = 'A';

        for (int j=0; j<=i; j++) {

            cout << ch << " ";
            ch++;
        }

        cout << endl;
    }
}

void printPattern15 (int n) {

    for (int i=0; i < n; i++) {

        char ch = 'A';

        for (int j=0; j < n-i; j++) {

            cout << ch << " ";
            ch++;
        }

        cout << endl;
    }
}

void printPattern16 (int n) {

    char ch = 'A';

    for(int i=0; i < n; i++) {

        for (int j=0; j <= i; j++) {

            cout << ch << " ";
        }

        ch++;
        cout << endl;
    }
}

void printPattern17 (int n) {

    for(int i=0; i < n; i++) {

        for (int j=0; j < n-i; j++) {

            cout << "  ";
        }

        char ch = 'A';
        int breakpoint = (2*i+1) / 2;

        for (int j=0; j < 2*i+1; j++) {

            cout << ch << " ";
            if (j < breakpoint) ch++;
            else ch--;
        }

        for (int j=0; j < n-i; j++) {

            cout << "  ";
        }

        cout << endl;

    }
}

void printPattern18 (int n) {


    for (int i=0; i<n; i++) {

        char ch = 'E' - i;

        for (int j=0; j<=i; j++) {

            cout << ch << " ";
            ch++;
        }

        cout << endl;
    }
}

void printPattern19 (int n) {

    for (int i=0; i < n; i++) {

        for (int j=0; j < n-i; j++) {

            cout << "*";
        }

        for (int j=0; j < 2*i; j++) {

            cout << " ";
        }

        for (int j=0; j < n-i; j++) {

            cout << "*";
        }

        cout << endl;
    }

    int initSpace = 2*n-2;

    for (int i =1; i <= n; i++) {

        for (int j=1; j <= i; j++) {
            
            cout << "*";
        }


        for (int j=1; j <= initSpace; j++) {

            cout << " ";
        }

        initSpace -= 2;

        for (int j =1; j <= i; j++) {
            
            cout << "*";
        }

        cout << endl;
    }
}

void printPattern20 (int n) {

    int spaces = 2*n-2;

    for (int i=1; i <= 2*n-1; i++) {

        int stars = i;
        if (stars > n)  stars = 2 * n - i ;

        for (int j=1; j <= stars; j++) {

            cout << "*";
        }

        for (int j=1; j <= spaces; j++) {

            cout << " ";
        }

        for (int j=0; j < stars; j++) {

            cout << "*";
        }

        if (i < n) spaces -= 2;
        else spaces += 2;

        cout << endl;
    }
}

void printPattern21 (int n) {

    for (int i =0; i < n; i++) {

        for (int j =0; j < n; j++) {

            if (i == 0 || i == n-1 || j == 0 || j == n-1) {

                cout << "*";

            } else {

                cout << " ";
            }
        }

        cout << endl;
    }
}

void printPattern22 (int n) {

    for (int i=0; i < 2*n-1; i++) {

        for (int j=0; j < 2*n-1; j++) {

            int top = i;
            int left = j;
            int right = (2*n-2) - j;
            int bottom = (2*n-2) - i;

            cout << (n - min(min(top, bottom), min(left, right))) << " ";
        }

        cout << endl;
    }
}

int main() {

    int n;
    cin >> n;

    printPattern1(n);
    cout << endl;

    printPattern2(n);
    cout << endl;

    printPattern3(n);
    cout << endl;

    printPattern4(n);
    cout << endl;

    printPattern5(n);
    cout << endl;

    printPattern6(n);
    cout << endl;

    printPattern7(n);
    cout << endl;

    printPattern8(n);
    cout << endl;

    printPattern9(n);
    cout << endl;

    printPattern10(n);
    cout << endl;

    printPattern11(n);
    cout << endl;

    printPattern12(n);
    cout << endl;

    printPattern13(n);
    cout << endl;

    printPattern14(n);
    cout << endl;

    printPattern15(n);
    cout << endl;

    printPattern16(n);
    cout << endl;

    printPattern17(n);
    cout << endl;

    printPattern18(n);
    cout << endl;

    printPattern19(n);
    cout << endl;

    printPattern20(n);
    cout << endl;

    printPattern21(n);
    cout << endl;

    printPattern22(n);
    cout << endl;

    return 0;

}
