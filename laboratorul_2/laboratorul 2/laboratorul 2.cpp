#include <iostream>
#include<vector>
#include<fstream>
#include<cstring>
using namespace std;
ifstream f("TextFile1.txt");
struct Student
{
    char firstName[30], lastName[30];
    int yearOfStudy;
    struct CalendaristicDate
    {
        int zi, luna, an;
        friend istream& operator>>(istream& is, CalendaristicDate& p)
        {
            is >> p.zi;
            is >> p.luna;
            is >> p.an;
            return is;
        }
        friend ostream& operator<<(ostream& os, CalendaristicDate& p)
        {
            return os << p.zi << "." << p.luna << "." << p.an;
            
        }


    }dateOfBirth;
    struct Grade
    {
        char numeMaterie[20];
        int nota;
    }grade[3];
    enum StudyProgram
    {
        MateInfo,
        Info,
        InfoAplicata
    }y;
    friend ostream& operator<<(ostream& os, Student& p)
    {
        os << "first name: " << p.firstName<<endl;
        os << "last name: " << p.lastName<<endl;
        os << "year of study: " << p.yearOfStudy<<endl;
        os << "data in care s-a nascut:" << p.dateOfBirth<<endl;
        for (int i = 0; i < 3; i++)
        {
            os << "Materia: "<<p.grade[i].numeMaterie<<endl;
            os << "Nota: "<< p.grade[i].nota<< endl;
        }
        os <<"Specializarea: "<< p.y << endl;
        return os;

    }


    friend istream& operator>>(istream& is, Student& p)
    {
        is >> p.firstName;
        is >> p.lastName;
        is >> p.yearOfStudy;
        is >> p.dateOfBirth;
        for (int i = 0; i < 3; i++)
        {
            is >> p.grade[i].numeMaterie;
            is >> p.grade[i].nota;
        }
        int x;
        is >> x;
        p.y = static_cast<StudyProgram>(x);
        return is;
    }
}p1[5];
double medie(int x, int y, int z)
{
    double s = x+y+z;
    return s / 3.0;
}
int main()
{
    for(int i=0;i<5;i++)
        f >> p1[i];
    for(int i=0;i<5;i++)
        cout << p1[i];
    char s[8] = "Popescu";
    cout << endl;
    cout << "Urmatorii sunt cu numele de Popescu:"<<endl;
    for (int i = 0; i < 5; i++)
        if (strcmp(p1[i].firstName, s) ==0)
        {
            cout << p1[i] << endl;
        }
    cout << endl;
    cout << "Urmatorii sunt nascuti in mai: " << endl;

    for (int i = 0; i < 5; i++)
        if (p1[i].dateOfBirth.luna == 5)
        {
            cout << p1[i] << endl;
        }
    cout << endl;
    cout << "Urmatorii sunt zodia balanta: ";
    for (int i = 0; i < 5; i++)
        if ((p1[i].dateOfBirth.luna == 9 && p1[i].dateOfBirth.zi >=22)|| (p1[i].dateOfBirth.luna == 10 && p1[i].dateOfBirth.zi <=21))
                cout << p1[i]<<endl;
    cout << endl;
    cout << "Urmatorii sunt la mate-info:"<<endl;
    for (int i = 0; i < 5; i++)
        if (p1[i].y == 0)
            cout << p1[i] << endl;
    cout << endl;
    cout << "La Mate-Info sunt:";
    int j = 0;
    for (int i = 0; i < 5; i++)
        if (p1[i].y == 0)
            j++;
    cout << j << endl;
    cout << "La Info sunt:";
    j = 0;
    for (int i = 0; i < 5; i++)
        if (p1[i].y == 1)
            j++;
    cout << j << endl;
    cout << "La Info Aplicata sunt:";
    j = 0;
    for (int i = 0; i < 5; i++)
        if (p1[i].y == 2)
            j++;
    cout << j << endl;
    int mini = INT_MAX;
    j=0;
    for (int i = 0; i < 5; i++)
        if (p1[i].grade[0].nota < mini)
            mini = p1[i].grade[1].nota, j=i;
    cout <<endl<< "Elevul cu nota cea mai mica la matematica este: " << endl<<p1[j];
    for (int i = 0; i < 5; i++)
        cout << endl << "media elevului " << p1[i].firstName << " " << p1[i].lastName << " este " << medie(p1[i].grade[0].nota, p1[i].grade[1].nota, p1[i].grade[2].nota)<<endl;
    cout << endl << "Urmatorii elevi au notele cele mai mari la Romana: "<<endl;
    int max1=INT_MIN, max2=INT_MIN, max3 = INT_MIN,k=-1,l=-1,m=-1;

    for (int i = 0; i < 5; i++)
        if (p1[i].grade[1].nota >= max1)
        {
            max1 = max2;
            max2 = max3;
            max3 = p1[i].grade[1].nota;
            m = l;
            l = k;
            k = i;
        }
    cout << p1[l] << endl << p1[m] << endl << p1[k] << endl;
    int mic = INT_MAX, mare = 0;
    int anmic = INT_MAX, lunamic = INT_MAX, zimic= INT_MAX;
    for (int i = 0; i < 5; i++)
        if (p1[i].dateOfBirth.an <= anmic)
        {
            anmic = p1[i].dateOfBirth.an;
            if (p1[i].dateOfBirth.luna <= lunamic)
            {
                lunamic = p1[i].dateOfBirth.luna;
                if (p1[i].dateOfBirth.zi <= zimic)
                {
                    mic = i;
                    zimic = p1[i].dateOfBirth.zi;
                }
            }
        }
    cout << endl << "Cel mai mare elev ca varsta este: " << endl << p1[mic] << endl;
    int anmare = INT_MIN, lunamare = INT_MIN, zimare = INT_MIN;
    for (int i = 1; i < 5; i++)
        if (p1[i].dateOfBirth.an > p1[mare].dateOfBirth.an)
            mare = i;
        else
            if (p1[i].dateOfBirth.luna > p1[mare].dateOfBirth.luna && p1[i].dateOfBirth.an == p1[mare].dateOfBirth.an)
                mare = i;
            else
                if (p1[i].dateOfBirth.zi > p1[mare].dateOfBirth.zi&& p1[i].dateOfBirth.luna == p1[mare].dateOfBirth.luna)
                {
                    mare = i;
                }
    cout << endl << "Cel mai mic elev ca varsta este: " << endl << p1[mare] << endl;
    cout << endl << "Cei sub 25 de ani: "<<endl;
    for (int i = 0; i < 5; i++)
        if (p1[i].dateOfBirth.an > 1998)
            cout << p1[i]<<endl<<endl;
    cout << "Cei cu media cea mai mare sunt:" << endl;
    max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    for(int i=0;i<5;i++)
        if (medie(p1[i].grade[0].nota, p1[i].grade[1].nota, p1[i].grade[2].nota) >(double) max3)
        {
            max1 = max2;
            max2 = max3;
            max3 = medie(p1[i].grade[0].nota, p1[i].grade[1].nota, p1[i].grade[2].nota);
            m = l;
            l = k;
            k = i;
        }
        else
            if (medie(p1[i].grade[0].nota, p1[i].grade[1].nota, p1[i].grade[2].nota) > (double)max2)
            {
                max1 = max2;
                    max2 = medie(p1[i].grade[0].nota, p1[i].grade[1].nota, p1[i].grade[2].nota);
                    m = l;
                    l = i;
            }
            else
                if (medie(p1[i].grade[0].nota, p1[i].grade[1].nota, p1[i].grade[2].nota) > (double)max1)
                {
                    max1 = medie(p1[i].grade[0].nota, p1[i].grade[1].nota, p1[i].grade[2].nota);
                    m = i;
                }
    cout << p1[k] << endl << p1[l] << endl << p1[m] << endl;
    Student aux;
    for(int i=0;i<4;i++)
        for(int j=i+1;j<5;j++)
            if (strcmp(p1[i].firstName, p1[j].firstName) > 0)
            {
                aux = p1[i];
                p1[i] = p1[j];
                p1[j] = aux;
            }
            else
                if (strcmp(p1[i].firstName, p1[j].firstName) == 0)
                    if (strcmp(p1[i].lastName, p1[j].lastName) > 0)
                    {
                        aux = p1[i];
                        p1[i] = p1[j];
                        p1[j] = aux;
                    }
    cout << "Elevii in ordine alfabetica sunt: " << endl;
    for (int i = 0; i < 5; i++)
        cout << p1[i] << endl << endl;
    return 0;

}
