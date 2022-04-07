#include <iostream>
using namespace std;
 
class Distance {
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
      
   public:
      // required constructors
      Distance() {
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i) {
         feet = f;
         inches = i;
      }
    //   void operator = (const Distance &D ) { 
    //      feet = D.feet;
    //      inches = D.inches;
    //   }
      
      // method to display distance
      void displayDistance() {
         cout << "F: " << feet <<  "\nI:" <<  inches << endl;
      }
};

class base
{
public:
    base() {cout<<"base constructor\n";}
    virtual ~base() {cout<<"base desstructor\n";}

};

class derived : public base
{
public:
    derived() {cout<<"derived constructor\n";}
    ~derived() {cout<<"derived desstructor\n";}

};

int main() {
   Distance D1(11, 10), D2(5, 11);

   cout << "First Distance : "<<endl;
   D1.displayDistance();
   cout << "Second Distance :"<<endl; 
   D2.displayDistance();

   // use assignment operator
   D1 = D2;
   cout << "First Distance :"<<endl;
   D1.displayDistance();
    cout<<&D1<<endl;
    cout<<&D2<<endl;

    base* Base = new base();
    delete Base;
    cout<<"_______________________________"<<endl;
    derived* Derived = new derived();
    cout<<"delete:"<<endl;
    delete Derived;
    cout<<"____________****_______________"<<endl;
    base* poly = new derived();
    delete poly;

    class a
    {
        private:
        int x;
        int func(int w);
        
    };
    a classa;

    class b : public a
    {
    public:
        int func(int s) //override 
        {
            cout<<"hello"<<endl;
            // x = 8;
            return s;

        }
    };
    b classb;
    // b* classb = new b;
    // classa.x = 3;
    // classb.x = 4;
    classb.func(2);

    return 0;
}

