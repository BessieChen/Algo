#include <cstdio> //printf()
#include <iostream>

using namespace std;

int main()
{
    string a,b,c,d;
    cin >> a >> b >> c >> d;

    int k = 0;
    while(true) //因为题目说了一定有一个解,所以一定可以走出来
    {
        if(a[k] == b[k] && a[k] >= 'A' && a[k] <= 'G')
        {
            char weekday[7][4] = {
                "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN",
            };

            printf("%s ", weekday[a[k] - 'A']);
            break;
        }
        k++;
    }

    k++; //bug!,不能从之前的k继续,需要k+1
    while(true){ 
        if(a[k] == b[k] &&  ((a[k] >= '0' && a[k] <= '9') || (a[k] >= 'A' && a[k] <= 'N')))
        {
            //cout << a[k] << endl;
            printf("%02d:", a[k] <= '9' ? a[k] - '0' : a[k] - 'A' + 10); //注意要+10
            break;
        }
        k++;
    }

    k = 0;
    while(true){
      if(c[k] == d[k] && ((c[k] >= 'a' && c[k] <= 'z') || (c[k] >= 'A' && c[k] <= 'Z'))){
          printf("%02d", k);
          break;
      }
    k++;
    }

    return 0;
}
