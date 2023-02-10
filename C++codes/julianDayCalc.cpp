#include <iostream>
#include <string>
#include <cmath>
#include <ctime>   
#include <iomanip> 


using namespace std;
string myFunc(string yourName);
int stringToInt( string stringIn );

// a funcion class that gets a date and time and
// finds the julian date number corresponding to the given date and time
class JulianDate{
    public:

        int Day;
        int Month;
        int Year;
        int Hour;
        int Minute;
        int Second;
        int A;
        double DayDecimal;
        double B;
        double julianDayNum;
    
        JulianDate( string dateIn, string timeIn){
            int slashPlace1 = dateIn.find( "/" );
            int slashPlace2 = dateIn.find( "/", slashPlace1 + 1 );

            Day = stringToInt( dateIn.substr( 0, slashPlace1 ) );
            Month = stringToInt( dateIn.substr( slashPlace1 + 1, slashPlace2 - slashPlace1 - 1 ) );
            Year = stringToInt( dateIn.substr( slashPlace2 + 1 ) );

            if( !( ( 31 >= Day >= 1 ) && ( 12 >= Month >= 1 ) ) ){
                cout << "Invalid date!" << endl;
            }


            int colonPlace1 = timeIn.find( ":" );
            int colonPlace2 = timeIn.find( ":", colonPlace1 + 1 );
            
            Hour = stringToInt( timeIn.substr( 0, colonPlace1 ) );
            Minute = stringToInt( timeIn.substr( colonPlace1 + 1, colonPlace2 - colonPlace1 - 1 ) );
            Second = stringToInt( timeIn.substr( colonPlace2 + 1 ) );

            if( !( ( 24 >= Hour >= 1 ) && ( 59 >= Minute >= 1 ) && ( 59 >= Second >= 1 ) ) ){
                cout << "Invalid time!" << endl;
            }

            A = (int)(Year/100);
            B = 2 - A + (int)(A/4);

            DayDecimal = Day + (( ( Hour * 3600 ) + ( Minute * 60 ) + Second ) / 86400.0);


            //julianDayNum = ( 1461 * ( Year + 4800 + ( Month - 14 ) / 12 ) ) / 4 + ( 367 * ( Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + Day - 32075;
            julianDayNum = ( (int)(365.25 * ( Year + 4716 )) + int( 30.6001 * ( Month + 1 ) ) + DayDecimal + B - 1524.5 ) ;
        }
         

};


int main() {

    // give the date and time that you want to get its julian day number of
    JulianDate myDate( "29/04/2030", "07:55:23" );


    // prints out the julian day number with 10 decimal points
    cout << "\n" << endl;
    cout << fixed << setprecision(10) << myDate.julianDayNum;
    //cout << myDate.julianDayNum << endl;
    cout << "\n" << endl;

    return 0;
}


// converts string to int
int stringToInt( string stringIn ){
    for( int i = 0; i < stringIn.length(); i++ ){
        if( !isdigit( stringIn[i] ) ){
            cout << "stringIn in the function stringToInt contain(s) character that is not a digit" << endl;
            return -1;
        }
    }
    return stoi( stringIn );
}







