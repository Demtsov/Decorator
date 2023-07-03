#include <QCoreApplication>
#include <iostream>
using namespace std;

class coffee{
 public:
    string description="unknown";

   virtual int cost()=0;
    virtual string getdescription(){
        return description;
    }

};

class cappuccino:public coffee
{
public:
    cappuccino(){description="cappuccino";}

    int cost() override {
     return 75;
    }
};

class latte:public coffee
{
public:
    latte(){description="latte";}

    int cost() override  {
        return 89;

    }
};

class americano:public coffee
{
public:
americano(){description="americano";}
    int cost() override{
        return 58;
    };
};

class espresso:public coffee
{
public:
espresso(){description="espresso";}
    int cost() override{
       return 100;
    };
};




 class decorator:public coffee
 {
 public:

};


 class milk:public decorator
 {
     coffee* coffee1;
 public:
      milk( coffee* coffee1){
      this->coffee1=coffee1;
     }
      string getdescription(){
      return coffee1->getdescription()+", milk";
};
      int cost(){
      return 15+coffee1->cost();
     };
 };


 class syrop:public decorator
 {
     coffee* coffee1;
 public:
     syrop (coffee* coffee1){
     this->coffee1=coffee1;
     }
     string getdescription(){
      return coffee1->getdescription()+", syrop"; }
     int cost(){
         return 25+coffee1->cost();};
 };

 class sugar:public decorator
 {
     coffee* coffee1;
 public:
     sugar(coffee* coffee1){
     this->coffee1=coffee1;
     }
     string getdescription(){
     return coffee1->getdescription()+", sugar"; }
     int cost(){
     return 5+coffee1->cost();};
 };


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

  coffee* coffee2= new latte();
cout<<coffee2->getdescription()<<"-";
cout<<coffee2->cost()<<endl;

 coffee* coffee3=new cappuccino();
coffee3= new milk(coffee3);
coffee3= new sugar(coffee3);
cout<<coffee3->getdescription()<<"-";
cout<<coffee3->cost()<<endl;

    return a.exec();
}
